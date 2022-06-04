#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{
	std::cout << "Harl destructed" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nI love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!\n" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levelinfo = "DIWE";
	switch(levelinfo.find(level[0]))
	{
	case 0:
		debug();
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}
