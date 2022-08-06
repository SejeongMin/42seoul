#include "Conversion.hpp"

int	main(int ac, char **av)
{
	if (ac != 2){
		std::cout << "One argument required." << std::endl;
		return (0);
	}
	Conversion c(av[1]);

	c.toChar();
	c.toInt();
	c.toFloat();
	c.toDouble();
}