#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_gatekeeperMode = false;
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_gatekeeperMode = false;
	std::cout << "ScavTrap " << _name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s) : ClapTrap(s._name)
{
	*this = s;
	std::cout << "ScavTrap " << _name << " constructed.(copy constructor)" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << "destructed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& s)
{
	_name = s._name;
	_hitPoints = s._hitPoints;
	_energyPoints = s._energyPoints;
	_attackDamage = s._attackDamage;
	_gatekeeperMode = s._gatekeeperMode;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout << "ScavTrap " << _name << " is already dead." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " 
			<< target << ", causing " << _attackDamage
			<< " points of damage!" << std::endl;
	displayStatus();
}

void	ScavTrap::guardGate()
{
	_gatekeeperMode = true;
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
