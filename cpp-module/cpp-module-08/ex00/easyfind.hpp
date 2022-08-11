#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T& c, int value)
{
	typename T::iterator iter = std::find(c.begin(), c.end(), value);
	if (iter == c.end())
		throw std::runtime_error("not found");
	return iter;
}

#endif