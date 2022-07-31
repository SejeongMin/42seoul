#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
    std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog& d)
{
    std::cout << "Dog copy constructor called." << std::endl;
    *this = d;
}

Dog::~Dog()
{
    std::cout << "Dog destructed." << std::endl;
}

Dog& Dog::operator=(const Dog& d)
{
    type = d.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog: Bark Bark Bark Bark Bark Bark Bark" << std::endl;
}

