#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	FragTrap f("frag");

	f.displayStatus();
	f.attack("scav");
	f.highFivesGuys();
}
