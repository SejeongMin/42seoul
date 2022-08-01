#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called." << std::endl;
	type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog& d)
{
    std::cout << "Dog copy constructor called." << std::endl;
    brain = new Brain();
    *this = d;
}

Dog::Dog(const Brain& b)
{
    std::cout << "Dog constructor called." << std::endl;
    type = "Dog";
    *brain = b;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructed." << std::endl;
}

Dog& Dog::operator=(const Dog& d)
{
    type = d.type;
    *brain = *(d.brain);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog: Bark Bark Bark Bark Bark Bark Bark" << std::endl;
}

void    Dog::setIdeas(int idx, std::string txt)
{
    brain->setIdeas(idx, txt);
}

const std::string& Dog::getIdeas(int idx) const
{
    return brain->getIdeas(idx);
}
