#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iomanip>
# include <iostream>

class Contact
{
private:
	int	index;
	std::string	field[5];
public:
	Contact();

	void	setIndex(int idx);
	void	setField();
	void	PrintField(std::string value);
	void	PrintFields();
	void	PrintContact();
};

#endif
