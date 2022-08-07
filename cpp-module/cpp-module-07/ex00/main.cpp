#include "whatever.hpp"
#include <iostream>

int main(void)
{
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		std::cout << "\n========= Min ==========\n" << std::endl;
		int a = 1;
		int b = 2;
		std::cout << "a : " << a << ", b : " << b << std::endl;
		std::cout << "min : ";
		int* res = &min(a, b);
		std::cout << (res == &a ? "a" : "b" ) << std::endl;
		std::cout << std::endl;
		b = 1;
		std::cout << "a : " << a << ", b : " << b << std::endl;
		std::cout << "min : ";
		res = &min(a, b);
		std::cout << (res == &a ? "a" : "b" ) << std::endl;
	}
	{
		std::cout << "\n========= Max ==========\n" << std::endl;
		int a = 1;
		int b = 2;
		std::cout << "a : " << a << ", b : " << b << std::endl;
		std::cout << "max : ";
		int* res = &max(a, b);
		std::cout << (res == &a ? "a" : "b" ) << std::endl;
		std::cout << std::endl;
		b = 1;
		std::cout << "a : " << a << ", b : " << b << std::endl;
		std::cout << "max : ";
		res = &max(a, b);
		std::cout << (res == &a ? "a" : "b" ) << std::endl;
	}
}
