#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{

public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& c);
	~ClapTrap();
	ClapTrap&	operator=(const ClapTrap& c);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	displayStatus();

private:
	std::string	_name;
	int	_hitPoints;
	int	_energyPoints;
	int	_attackDamage;

};

#endif
