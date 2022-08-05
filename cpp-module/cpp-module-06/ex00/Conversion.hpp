#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <exception>

class Conversion {

public:
	Conversion();
	Conversion(std::string& value);
	Conversion(const Conversion& c);
	~Conversion();
	Conversion& operator=(const Conversion& c);

	class NonDisplayableException : public std::exception{
	public:
		virtual const char* what() const throw();
	};

	class ImpossibleException : public std::exception{
	public:
		virtual const char* what() const throw();
	};

	class OverflowException : public std::exception{
	public:
		virtual const char* what() const throw();
	};

	void	toChar();
	void	toInt();
	void	toFloat();
	void	toDouble();

private:
	std::string _value;

};

#endif