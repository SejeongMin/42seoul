#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
    brain = new Brain();
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& c)
{
    std::cout << "Cat copy constructor called." << std::endl;
    brain = new Brain();
    *this = c;
}

Cat::Cat(const Brain& b)
{
    std::cout << "Cat constructor called." << std::endl;
    type = "Cat";
    *brain = b;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructed." << std::endl;
}

Cat& Cat::operator=(const Cat& c)
{
    type = c.type;
    *brain = *(c.brain);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat: Meow Meow Meow Meow Meow Meow Meow" << std::endl;
}

void    Cat::setIdeas(int idx, std::string txt)
{
    brain->setIdeas(idx, txt);
}

const std::string& Cat::getIdeas(int idx) const
{
    return brain->getIdeas(idx);
}

