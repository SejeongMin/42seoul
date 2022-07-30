#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : virtual public ClapTrap {

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& s);
	~ScavTrap();
	ScavTrap&	operator=(const ScavTrap& s);
	void	attack(const std::string& target);
	void	guardGate();

};

#endif