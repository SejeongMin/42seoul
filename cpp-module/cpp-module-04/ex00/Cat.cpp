#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& a)
{
    std::cout << "Cat copy constructor called." << std::endl;
    *this = a;
}

Cat::~Cat()
{
    std::cout << "Cat destructed." << std::endl;
}

Cat& Cat::operator=(const Cat& a)
{
    type = a.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat: Meow Meow Meow Meow Meow Meow Meow" << std::endl;
}

