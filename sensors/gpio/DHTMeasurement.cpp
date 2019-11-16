/*
 * DHTMeasurement.cpp
 *
 *  Created on: 1 Nov 2019
 *      Author: pi
 */

#include "DHTMeasurement.h"

namespace gpio {

DHTMeasurement::DHTMeasurement(float humidity, float celsius,
		float fahrenheit) {
	m_humidity = humidity;
	m_celsius = celsius;
	m_fahrenheit = fahrenheit;
}

DHTMeasurement::~DHTMeasurement() {
	// TODO Auto-generated destructor stub
}

float DHTMeasurement::humidity() {
	return m_humidity;
}

float DHTMeasurement::celsius() {
	return m_celsius;
}

float DHTMeasurement::fahrenheit() {
	return m_fahrenheit;
}

const DHTMeasurement DHTMeasurement::INVALID=DHTMeasurement(0,0,0);


}
/* namespace gpio */
