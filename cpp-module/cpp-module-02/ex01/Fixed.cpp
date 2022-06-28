#include "Fixed.hpp"

/*
class Fixed{
private:
	int	value;
	static const int	N = 8;
public:
	Fixed(const int i);
	Fixed(const Fixed &f);
	Fixed	&operator=(const Fixed &f);
	Fixed	&operator<<(const Fixed &f);
	~Fixed();
	int	getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat(void) const;
	int		toInt(void) const;
};*/
Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	this->value = i;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
	this->value = f;
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	// Guard self assignment
	if (this == &f)
		return *this;
	// *this가 충분한 공간을 할당받았다고 가정?
	this->value = f.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->value;
}

int		Fixed::toInt(void) const
{
	return (int)this->value;
}
