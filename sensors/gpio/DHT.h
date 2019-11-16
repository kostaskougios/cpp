/*
 * DHT.h
 *
 *  Created on: 1 Nov 2019
 *      Author: pi
 */

#ifndef DHT_H_
#define DHT_H_

#include "DHTMeasurement.h"

namespace gpio {

class DHT {
private:
	int m_pin;
	unsigned short data[5];

	short readData();

public:
	DHT(int);
	DHTMeasurement measure();
	virtual ~DHT();
};

} /* namespace gpio */
#endif /* DHT_H_ */
