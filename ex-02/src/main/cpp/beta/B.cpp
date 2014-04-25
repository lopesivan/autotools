/*
 * B.cpp
 *
 *  Created on: Jan 23, 2013
 *      Author: ivan
 */

#include "B.h"

B::B() {
	std::cout << "constructor" << std::endl;

	this->myName = "Eu sou a classe G";

}

B::~B() {
	std::cout << "destructor" << std::endl;
}

char* B::getMyName() const {
	return myName;
}

void B::setMyName(char* myName) {
	this->myName = myName;
}
