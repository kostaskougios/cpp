/*
 * DHTMeasurement.h
 *
 *  Created on: 1 Nov 2019
 *      Author: pi
 */

#ifndef DHTMEASUREMENT_H_
#define DHTMEASUREMENT_H_

namespace gpio {

class DHTMeasurement {
private:
	float m_humidity;
	float m_celsius;
	float m_fahrenheit;

public:

	static const DHTMeasurement INVALID;


	DHTMeasurement(float,float,float);
	virtual ~DHTMeasurement();

	float humidity();
	float celsius();
	float fahrenheit();
};

} /* namespace gpio */
#endif /* DHTMEASUREMENT_H_ */
