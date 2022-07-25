#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{

public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed &f);
	Fixed&	operator=(const Fixed &f);
	~Fixed();
	int	getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int	value;
	static const int	N = 8;
};

std::ostream&	operator<<(std::ostream &os, const Fixed &f);

#endif
