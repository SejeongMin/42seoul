#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called." << std::endl;
}

Brain::Brain(const Brain& b)
{
    std::cout << "Brain copy constructor called." << std::endl;
    *this = b;
}

Brain::~Brain()
{
    std::cout << "Brain destructed." << std::endl;
}

Brain& Brain::operator=(const Brain& b)
{
    for(int i = 0; i < 100; i++){
		ideas[i] = b.ideas[i];
	}
	return (*this);
}

void    Brain::setIdeas(int idx, std::string txt)
{
    ideas[idx] = txt;
}

const std::string&	Brain::getIdeas(int idx) const
{
    return ideas[idx];
}

