#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{

public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed &f);
	Fixed&		operator=(const Fixed &f);
	~Fixed();
	int	getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat(void) const;
	int		toInt(void) const;

	//comparision operators
	bool	operator>(const Fixed& f) const;
	bool	operator<(const Fixed& f) const;
	bool	operator>=(const Fixed& f) const;
	bool	operator<=(const Fixed& f) const;
	bool	operator==(const Fixed& f) const;
	bool	operator!=(const Fixed& f) const;

	//arithmetic oprators
	Fixed	operator+(const Fixed &f) const;
	Fixed	operator-(const Fixed &f) const;
	Fixed	operator*(const Fixed &f) const;
	Fixed	operator/(const Fixed &f) const;

	//increment/decrement operators
	Fixed&	operator++();
	Fixed&	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed&	min(Fixed& f1, Fixed& f2);
	const static Fixed&	min(const Fixed& f1, const Fixed& f2);
	static Fixed&	max(Fixed& f1, Fixed& f2);
	const static Fixed&	max(const Fixed& f1, const Fixed& f2);

private:
	int	value;
	static const int	N = 8;
};

std::ostream&	operator<<(std::ostream &os, const Fixed &f);

#endif
