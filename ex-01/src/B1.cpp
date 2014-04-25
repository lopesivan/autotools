#include <iostream>

#include "B1.h"

B1::B1()
{
	std::cout << "!!!constructor stub!!!" << std::endl;
}

B1::~B1()
{
	std::cout << "!!!destructor stub!!!" << std::endl;
}

void B1::imprima()
{
	std::cout << "!!!Hello World!!!" << std::endl;
}

