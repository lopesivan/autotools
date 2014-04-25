/*
 * A.cpp
 *
 *  Created on: Jan 23, 2013
 *      Author: ivan
 */

#include "A.h"

A::A() {
	std::cout << "constructor" << std::endl;

	this->myName = "Eu sou a classe A";

}

A::~A() {
	std::cout << "destructor" << std::endl;
}

char* A::getMyName() const
{
	return myName;
}

void A::setMyName(char* myName)
{
		this->myName = myName;
}
