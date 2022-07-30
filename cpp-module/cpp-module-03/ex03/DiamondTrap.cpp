#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name(ClapTrap::_name)
{
    ClapTrap::_name += "_clap_name";
    _energyPoints = 50;
    std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), _name(ClapTrap::_name)
{
    ClapTrap::_name += "_clap_name";
    _energyPoints = 50;
    std::cout << "DiamondTrap " << _name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& d) : ClapTrap(d), ScavTrap(d), FragTrap(d), _name(d._name)
{
    ClapTrap::_name += "_clap_name";
    _energyPoints = 50;
    std::cout << "DiamondTrap " << _name << " constructed.(copy constructor)" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " destructed." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& d)
{
    _name = d._name;
	_hitPoints = d._hitPoints;
	_energyPoints = d._energyPoints;
	_attackDamage = d._attackDamage;
	return (*this);
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
