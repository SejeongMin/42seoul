#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
    std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& w)
{
    std::cout << "WrongCat copy constructor called." << std::endl;
    *this = w;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructed." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& w)
{
    type = w.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat: Meow Meow Meow Meow Meow Meow Meow" << std::endl;
}

