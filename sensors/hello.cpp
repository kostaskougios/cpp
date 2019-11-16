//============================================================================
// Name        : hello.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <iostream>
#include "gpio/Led.h"
#include "gpio/DHT.h"

using namespace std;

const int LED_PIN = 2;
const int DHT_PIN = 0;

int main(void) {
	if (wiringPiSetup() == -1) {
		cout << "Can't initialize wiringPi!" << endl;
	} else {
		gpio::Led led(LED_PIN);
		gpio::DHT dht(DHT_PIN);

		//pinMode(LED_PIN, OUTPUT);
		led.on();
		cout << "Let there be light! On pin " << LED_PIN << endl;

		auto measurement = dht.measure();

		printf("TEMP: %6.2f *C (%6.2f *F) | HUMI: %6.2f %\n\n",
				measurement.celsius(), measurement.fahrenheit(),
				measurement.humidity());
		delay(1000);
		led.off();
	}
	return EXIT_SUCCESS;
}
