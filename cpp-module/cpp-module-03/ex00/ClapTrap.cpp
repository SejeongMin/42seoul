/*
class ClapTrap{

public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& c);
	~ClapTrap();
	ClapTrap&	operator=(const ClapTrap& c);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string	_name;
	int	_hitPoints;
	int	_energyPoints;
	int	_attackDamage;

};*/

#include "ClapTrap.hpp"
#include <string>

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
{
	std::cout << "ClapTrap " << _name << " constructed." << std::endl;
	*this = c;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &c)
{
	_name = c._name; // 음 ...........?
	_hitPoints = c._hitPoints;
	_energyPoints = c._energyPoints;
	_attackDamage = c._attackDamage;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " has already dead." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " 
			<< target << ", causing " << _attackDamage
			<< " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energyPoints) // hit=0이면?
	{
		std::cout << "ClapTrap " << _name << "has already dead." << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself "
			<< amount << " points!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout << "ClapTrap " << _name << "has already dead." << std::endl;
		return ;
	}
}

void	ClapTrap::displayStatus()
{
}
