/*
 * A.h
 *
 *  Created on: Jan 23, 2013
 *      Author: ivan
 */

#ifndef A_H_
#define A_H_

#include <iostream>

class A {
private:
	char* myName;

public:
	A();
	virtual ~A();

	char* getMyName() const;
	void setMyName(char*);
};

#endif /* A_H_ */
