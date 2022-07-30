#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap{

public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& d);
    ~DiamondTrap();
    DiamondTrap& operator=(const DiamondTrap& d);

    void    attack(const std::string& target);
    void    whoAmI();

private:
    std::string _name;

};

#endif