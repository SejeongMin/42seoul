/*
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	void	complain(std::string level);
*/

#include "Karen.hpp"

Karen::Karen()
{}

Karen::~Karen()
{
	std::cout << "Karen destructed" << std::endl;
}

void	Karen::debug(void)
{
	std::cout << "[ DEBUG ]\nI love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level)
{
	std::string	levelinfo = "DIWE";
	switch(levelinfo.find(level[0]))
	{
	case 0:
		debug();
		break;
	case 1:
		info();
		break;
	case 2:
		warning();
		break;
	case 3:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}
