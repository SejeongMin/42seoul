#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& c);
	~ClapTrap();
	ClapTrap&	operator=(const ClapTrap& c);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	displayStatus();

protected:
	std::string	_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

};

#endif
