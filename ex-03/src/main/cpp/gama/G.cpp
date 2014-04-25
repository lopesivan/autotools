/*
 * G.cpp
 *
 *  Created on: Jan 23, 2013
 *      Author: ivan
 */

#include "G.h"

G::G() {
	std::cout << "constructor" << std::endl;

	this->myName = "Eu sou a classe G";

}

G::~G() {
	std::cout << "destructor" << std::endl;
}

char* G::getMyName() const
{
	return myName;
}

void G::setMyName(char* myName)
{
		this->myName = myName;
}
