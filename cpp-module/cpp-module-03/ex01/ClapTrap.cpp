#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
{
	std::cout << "ClapTrap " << _name << " constructed.(copy constructor)" << std::endl;
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
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " 
			<< target << ", causing " << _attackDamage
			<< " points of damage!" << std::endl;
	displayStatus();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energyPoints) // hit=0이면?
	{
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself "
			<< amount << " points!" << std::endl;
	displayStatus();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return ;
	}
	if (_hitPoints <= amount)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " is dead." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage." << std::endl;
	_hitPoints -= amount;
	displayStatus();
}

void	ClapTrap::displayStatus()
{
	std::cout << "\n" << _name << " : hit point (" << _hitPoints
			<< ") | energy point (" << _energyPoints
			<< ") | attack damage (" << _attackDamage << ")\n" << std::endl;
}
