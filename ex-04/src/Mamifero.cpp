/*
 * Mamifero.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: ivan
 */

#include "Mamifero.h"

Mamifero::Mamifero() {
	auto i = 3;

	std::cout << i << std::endl;
	std::cout << "ctor" << std::endl;

}

int Mamifero::getOlhos() const {
	return m_olhos;
}

void Mamifero::setOlhos(int olhos) {
	m_olhos = olhos;
}

Mamifero::~Mamifero() {
	std::cout << "dtor" << std::endl;
}

