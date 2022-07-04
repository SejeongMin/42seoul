#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{
private:
	int	value;
	static const int	N = 8;
public:
	Fixed();
	Fixed(const Fixed &f);
	Fixed	&operator=(const Fixed &f);
	~Fixed();
	int	getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif
