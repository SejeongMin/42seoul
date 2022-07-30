#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap s("scav");

	s.displayStatus();
	s.attack("trap");
	s.guardGate();
}
