#include <iostream>
#include <fstream>
// #include <string>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Enter a filename and two strings" << std::endl;
		return (1);
	}
	std::ifstream	readfile(av[1]);
	if (readfile.is_open())
	{
		std::string	filetxt((std::istreambuf_iterator<char>(readfile)),
							(std::istreambuf_iterator<char>()));
		int	length = strlen(av[2]);
		int	i = 0;
		int	idx = 0;
		while (filetxt[i])
		{
			idx = filetxt.find(av[2], i);
			if (idx < 0)
				break ;
			filetxt.erase(idx, length);
			filetxt.insert(idx, av[3]);
			i += idx;
		}
		readfile.close();
		std::ofstream	writefile((std::string)av[1] + ".replace");
		if (writefile.is_open())
		{
			writefile << filetxt;
			writefile.close();
		}
	}
	else
		std::cout << "There is no file." << std::endl;
}
