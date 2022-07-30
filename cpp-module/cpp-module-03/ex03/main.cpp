#include "DiamondTrap.hpp"
#include <iomanip>

int	main(void)
{
	{
		DiamondTrap	a("A");

		std::cout << std::endl;
		a.whoAmI();
		std::cout << std::endl;
		a.displayStatus();
	}

	std::cout << "\n" << std::setw(80) << std::setfill('=') << "\n" << std::endl;
	std::cout << "" << std::setfill(' ');

	{
		DiamondTrap b("B");
		DiamondTrap c("C");


		std::cout << std::endl;
		
		b.whoAmI();
		c.whoAmI();		
		c.highFivesGuys();
		
		std::cout << std::endl;
		
		b.attack("C");
		c.takeDamage(30);
		
		std::cout << std::endl;
		
		b.attack("C");
		c.takeDamage(30);
		
		std::cout << std::endl;
		
		b.guardGate();
		
		std::cout << std::endl;
	}
}
