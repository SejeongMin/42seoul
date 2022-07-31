#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a)
{
    std::cout << "WrongAnimal copy constructor called." << std::endl;
    *this = a;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructed." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a)
{
    type = a.type;
	return (*this);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal is making sound..." << std::endl;
}

const std::string&	WrongAnimal::getType() const
{
	return type;
}
