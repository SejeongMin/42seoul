#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

Base * generate(void)
{
	Base* base;
	srand((unsigned int)time(NULL));
	if (rand() % 3 == 0)
		base = dynamic_cast<Base*>(new A);
	else if (rand() % 3 == 1)
		base = dynamic_cast<Base*>(new B);
	else
		base = dynamic_cast<Base*>(new C);
	return base;
}

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "A" << std::endl;
	if (b)
		std::cout << "B" << std::endl;
	if (c)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(std::exception & e){}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(std::exception & e){}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(std::exception & e){}
}

int main(void)
{
	Base* b = generate();

	identify(b);
	identify(*b);

	delete b;

	return (0);
}
