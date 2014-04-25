/*
 * Mamifero.h
 *
 *  Created on: Feb 11, 2014
 *      Author: ivan
 */

#ifndef MAMIFERO_H_
#define MAMIFERO_H_

#include <iostream>

class Mamifero {
int m_olhos;

public:
	Mamifero();
	virtual ~Mamifero();

	int getOlhos() const;
	void setOlhos(int olhos);
};

#endif /* MAMIFERO_H_ */
