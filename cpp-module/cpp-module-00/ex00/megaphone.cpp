#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int	i = 1;
	while (i < ac)
	{
		std::cout << av[i] << "";
		i++;
	}
	std::cout << "" << std::endl;
}
