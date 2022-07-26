#include "ClapTrap.hpp"
#include <iomanip>

int	main(void)
{
	{
		ClapTrap	clap("clap");

		clap.attack("trap");
		clap.takeDamage(5);
		clap.beRepaired(5);
		clap.beRepaired(5);
		clap.beRepaired(5);
		clap.beRepaired(5);
		clap.beRepaired(5);
		clap.beRepaired(5);
		clap.beRepaired(5);
		clap.beRepaired(5);
		clap.beRepaired(5);
		clap.beRepaired(10);
		clap.attack("trap");
	}
	std::cout << "\n" << std::setw(80) << std::setfill('=') << "\n" << std::endl;
	std::cout << "" << std::setfill(' ');
	{
		ClapTrap	trap("trap");

		trap.attack("clap");
		trap.takeDamage(5);
		trap.beRepaired(5);
		trap.takeDamage(10);
		trap.beRepaired(10);
		trap.attack("clap");
	}
}
