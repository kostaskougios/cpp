/*
 * Led.h
 *
 *  Created on: 31 Oct 2019
 *      Author: pi
 */

#ifndef LED_H_
#define LED_H_

namespace gpio {

class Led {
private:
	int m_pin;
public:
	Led(int);
	void on();
	void off();
	virtual ~Led();
};

} /* namespace gpio */
#endif /* LED_H_ */
