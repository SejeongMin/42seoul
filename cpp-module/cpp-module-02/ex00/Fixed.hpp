#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
public:
	Fixed();
	Fixed(const Fixed &f);
	~Fixed();
	Fixed	&operator=(const Fixed &f);
	int	getRawBits( void ) const;
	void	setRawBits( int const raw );
private:
	int	value;
	static const int	N = 8;
};

#endif
