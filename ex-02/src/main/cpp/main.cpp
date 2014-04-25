#include <iostream>
#include "alpha/A.h"
#include "beta/B.h"
#include "gama/G.h"

int main()
{
	std::cout << "Oi mundo!" << std::endl;

	A a;
	B b;
	G g;

	std::cout << "A =" << a.getMyName() << std::endl;
	std::cout << "B =" << b.getMyName() << std::endl;
	std::cout << "G =" << g.getMyName() <<std::endl;


	return 0;
}
