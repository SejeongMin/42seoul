#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{
	std::cout << "Harl destructed" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nI love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*harlFunc[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	Harl	*harl = new Harl();
	std::string	levelinfo = "DIWE";
	int	lv = levelinfo.find(level[0]);
	if (lv >= 0 && lv <= 3)
		(harl->*harlFunc[lv])();
	else
		std::cout << "WRONG INPUT : Enter [\"DEBUG\", \"INFO\", \"WARNING\", \"ERROR\"]" << std::endl;
	delete harl;
}
