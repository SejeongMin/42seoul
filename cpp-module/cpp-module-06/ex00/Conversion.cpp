#include "Conversion.hpp"
#include <sstream>

Conversion::Conversion()
{
    std::cout << "Conversion default constructor called." << std::endl;
}

Conversion::Conversion(std::string& value)
{
    std::cout << "Conversion constructor called." << std::endl;
    _value = value;
}

Conversion::Conversion(const Conversion& c)
{
    std::cout << "Conversion copy constructor called." << std::endl;
    *this =  c;
}

Conversion::~Conversion()
{
    std::cout << "Conversion destructed." << std::endl;
}

Conversion& Conversion::operator=(const Conversion& c)
{
    _value = c._value;
    return *this;
}

const char* Conversion::NonDisplayableException::what() const throw()
{
    return "Non displayable";
}

const char* Conversion::ImpossibleException::what() const throw()
{
    return "impossible";
}

void    Conversion::toChar()
{
}

void    Conversion::toInt()
{

}

void    Conversion::toDouble()
{
    std::stringstream dStream(_value);
    double d;
    dStream >> d;
    std::cout << d;
}

void    Conversion::toFloat()
{

}

