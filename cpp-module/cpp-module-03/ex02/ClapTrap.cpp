#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called.\n" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed.\n" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
{
	std::cout << "ClapTrap " << _name << " constructed.(copy constructor)\n" << std::endl;
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
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " is already dead.\n" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " 
			<< target << ", causing " << _attackDamage
			<< " points of damage!" << std::endl;
	displayStatus();
	if (!_energyPoints)
		std::cout << "ClapTrap " << _name << " is dead. (no energy points left)\n" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energyPoints || !_hitPoints) // hit=0이면?
	{
		std::cout << "ClapTrap " << _name << " is already dead.\n" << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself "
			<< amount << " points!" << std::endl;
	displayStatus();
	if (!_energyPoints)
		std::cout << "ClapTrap " << _name << " is dead. (no energy points left)\n" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " is already dead.\n" << std::endl;
		return ;
	}
	if (_hitPoints <= amount)
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage." << std::endl;
		_hitPoints = 0;
		displayStatus();
		std::cout << "ClapTrap " << _name << " is dead. (no hit points left)" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage." << std::endl;
	_hitPoints -= amount;
	displayStatus();
}

void	ClapTrap::displayStatus()
{
	std::cout << "\nClapTrap " << _name << " : hit point (" << _hitPoints
			<< ") | energy point (" << _energyPoints
			<< ") | attack damage (" << _attackDamage << ")\n" << std::endl;
}
