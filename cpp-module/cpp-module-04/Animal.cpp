#include "Animal.hpp"

Animal::Animal() : type("animal")
{
    std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(std::string t) : type(t)
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
}

void    Animal::makeSound()
{
    std::cout << "Animal make sound." << std::endl;
}
