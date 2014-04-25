/*
 * B.h
 *
 *  Created on: Jan 23, 2013
 *      Author: ivan
 */

#ifndef B_H_
#define B_H_

#include <iostream>

class B {
private:
	char* myName;
public:
	B();
	virtual ~B();

	char* getMyName() const;
	void setMyName(char*);
};

#endif /* B_H_ */
