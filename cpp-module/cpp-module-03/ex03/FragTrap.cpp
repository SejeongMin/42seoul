#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap& f) : ClapTrap(f._name)
{
	*this = f;
	std::cout << "FragTrap " << _name << " constructed.(copy constructor)" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& f)
{
	_name = f._name;
	_hitPoints = f._hitPoints;
	_energyPoints = f._energyPoints;
	_attackDamage = f._attackDamage;
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout << "FragTrap " << _name << " is already dead." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " attacks " 
			<< target << ", causing " << _attackDamage
			<< " points of damage!" << std::endl;
	displayStatus();
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a positive high-five." << std::endl;
}

