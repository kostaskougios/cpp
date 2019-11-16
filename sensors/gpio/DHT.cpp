/*
 * DHT.cpp
 *
 *  Created on: 1 Nov 2019
 *      Author: pi
 */

#include "DHT.h"
#include "DHTMeasurement.h"
#include <wiringPi.h>

namespace gpio {

DHT::DHT(int pin) {
	m_pin = pin;
}

DHT::~DHT() {
}

short DHT::readData() {
	unsigned short val = 0x00;
	unsigned short signal_length = 0;
	unsigned short val_counter = 0;
	unsigned short loop_counter = 0;
	while (1) {
		// Count only HIGH signal
		while (digitalRead(m_pin) == HIGH) {
			signal_length++;

			// When sending data ends, high signal occur infinite.
			// So we have to end this infinite loop.
			if (signal_length >= 200) {
				return -1;
			}

			delayMicroseconds(1);
		}

		// If signal is HIGH
		if (signal_length > 0) {
			loop_counter++; // HIGH signal counting

			// The DHT22 sends a lot of unstable signals.
			// So extended the counting range.
			if (signal_length < 10) {
				// Unstable signal
				val <<= 1; // 0 bit. Just shift left
			}

			else if (signal_length < 30) {
				// 26~28us means 0 bit
				val <<= 1; // 0 bit. Just shift left
			}

			else if (signal_length < 85) {
				// 70us means 1 bit
				// Shift left and input 0x01 using OR operator
				val <<= 1;
				val |= 1;
			}

			else {
				// Unstable signal
				return -1;
			}

			signal_length = 0; // Initialize signal length for next signal
			val_counter++; // Count for 8 bit data
		}

		// The first and second signal is DHT22's start signal.
		// So ignore these data.
		if (loop_counter < 3) {
			val = 0x00;
			val_counter = 0;
		}

		// If 8 bit data input complete
		if (val_counter >= 8) {
			// 8 bit data input to the data array
			data[(loop_counter / 8) - 1] = val;

			val = 0x00;
			val_counter = 0;
		}
	}
}

DHTMeasurement DHT::measure() {

	// Initialize data array for next loop
	for (unsigned char i = 0; i < 5; i++) {
		data[i] = 0;
	}

	pinMode(m_pin, OUTPUT);
	digitalWrite(m_pin, LOW);
	delay(20);
	pinMode(m_pin, INPUT);
	DHT::readData();

	float humidity;
	float celsius;
	float fahrenheit;
	short checksum;
	// The sum is maybe over 8 bit like this: '0001 0101 1010'.
	// Remove the '9 bit' data using AND operator.
	checksum = (data[0] + data[1] + data[2] + data[3]) & 0xFF;

	if (data[4] == checksum && checksum != 0x00) {
		// * 256 is the same thing '<< 8' (shift).
		humidity = ((data[0] * 256) + data[1]) / 10.0;

		// found that with the original code at temperatures > 25.4 degrees celsius
		// the temperature would print 0.0 and increase further from there.
		// Eventually when the actual temperature drops below 25.4 again
		// it would print the temperature as expected.
		// Some research and comparisin with other C implementation suggest a
		// different calculation of celsius.
		//celsius = data[3] / 10.0; //original
		celsius = (((data[2] & 0x7F) * 256) + data[3]) / 10.0; //Juergen Wolf-Hofer

		// If 'data[2]' data like 1000 0000, It means minus temperature
		if (data[2] == 0x80) {
			celsius *= -1;
		}

		fahrenheit = ((celsius * 9) / 5) + 32;

		return DHTMeasurement(humidity, celsius, fahrenheit);
	}
	return DHTMeasurement::INVALID;
}

} /* namespace gpio */
