#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : virtual public ClapTrap {

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& f);
	~FragTrap();
	FragTrap&	operator=(const FragTrap& f);
	void	attack(const std::string& target);
	void	highFivesGuys(void);

};

#endif