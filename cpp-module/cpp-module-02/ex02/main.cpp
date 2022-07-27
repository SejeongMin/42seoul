#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
    }
    {
        Fixed c(10);
        Fixed d(5.1f);
        std::cout << "c = " << c << std::endl;
        std::cout << "d = " << d << std::endl;
        std::cout << (c > d) << std::endl;
        std::cout << (c < d) << std::endl;
        std::cout << (c >= d) << std::endl;
        std::cout << (c <= d) << std::endl;
        std::cout << (c == d)  << std::endl;
        std::cout << (c != d) << std::endl;
        std::cout << (c + d) << std::endl;
        std::cout << (c - d) << std::endl;
        std::cout << (c * d) << std::endl;
        std::cout << (c / d) << std::endl;
        std::cout << Fixed::min(c,d) << std::endl;
        std::cout << Fixed::max(c,d) << std::endl;
    }
}
