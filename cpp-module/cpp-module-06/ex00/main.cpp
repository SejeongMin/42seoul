#include <iostream>
#include <sstream>
#include <string>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Put only one argument." << std::endl;
		return (0);
	}
	int a = 1;
	// std::cout << reinterpret_cast<char*>(&a) << std::endl;
	std::string value = "d1e2.1";
	std::stringstream dStream(value);
	// float f = stof(value);
	// std::cout << f;
    int d;
    dStream >> d;
	std::cout << dStream.fail() << std::endl;
    std::cout << d;
}