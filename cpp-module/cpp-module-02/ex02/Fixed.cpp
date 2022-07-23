#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	this->value = i << this->N;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
	this->value = roundf(f * (1 << this->N));
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

std::ostream&	operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return os;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return this->value;
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return((float)this->value / (1 << this->N));
}

int		Fixed::toInt(void) const
{
	return (this->value >> this->N);
}

bool	Fixed::operator>(const Fixed& f) const
{
	return this->value > f.getRawBits();
}

bool	Fixed::operator<(const Fixed& f) const
{
	return this->value < f.getRawBits();
}

bool	Fixed::operator>=(const Fixed& f) const
{
	return this->value >= f.getRawBits();
}

bool	Fixed::operator<=(const Fixed& f) const
{
	return this->value <= f.getRawBits();
}

bool	Fixed::operator==(const Fixed& f) const
{
	return this->value == f.getRawBits();
}

bool	Fixed::operator!=(const Fixed& f) const
{
	return this->value != f.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	return Fixed(this->toFloat() + f.toFloat());
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	return Fixed(this->toFloat() - f.toFloat());
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	return Fixed(this->toFloat() * f.toFloat());
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	return Fixed(this->toFloat() / f.toFloat());
}

// pre-increment
Fixed&	Fixed::operator++()
{
	this->value++;
	return (*this);
}

// pre-decrement
Fixed&	Fixed::operator--()
{
	this->value--;
	return (*this);
}

// post-increment
Fixed	Fixed::operator++(int)
{
	Fixed f(*this);
	this->value++;
	return f;
}

//post-decrement
Fixed	Fixed::operator--(int)
{
	Fixed f(*this);
	this->value--;
	return f;
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	return f1 < f2 ? f1 : f2;
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	return f1 < f2 ? f1 : f2;
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	return f1 > f2 ? f1 : f2;
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	return f1 > f2 ? f1 : f2;
}
