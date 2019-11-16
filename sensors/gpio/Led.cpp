/*
 * Led.cpp
 *
 *  Created on: 31 Oct 2019
 *      Author: pi
 */

#include "Led.h"
#include <wiringPi.h>

namespace gpio {

Led::Led(int pin) {
	m_pin=pin;
	pinMode(m_pin, OUTPUT);
}

void Led::on() {
	digitalWrite(m_pin, HIGH);
}

void Led::off() {
	digitalWrite(m_pin, LOW);
}

Led::~Led() {
	// destructor
}

} /* namespace gpio */
