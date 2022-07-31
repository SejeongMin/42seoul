#include "Animal.hpp"

Animal::Animal() : type("animal")
{
    std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal& a)
{
    std::cout << "Animal copy constructor called." << std::endl;
    *this = a;
}

Animal::~Animal()
{
    std::cout << "Animal destructed." << std::endl;
}

Animal& Animal::operator=(const Animal& a)
{
    type = a.type;
    return (*this);
}

void    Animal::makeSound() const
{
    std::cout << "Animal is making sound..." << std::endl;
}

const std::string& Animal::getType() const
{
    return type;
}
