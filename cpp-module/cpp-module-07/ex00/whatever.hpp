#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& x, T& y)
{
	T tmp;
	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T& min(T& x, T& y)
{
	return x >= y ? y : x;
}

template <typename T>
const T& min (const T& x, const T& y)
{
	return x >= y ? y : x;
}

template <typename T>
T& max(T& x, T& y)
{
	return x <= y ? y : x;
}

template <typename T>
const T& max(const T& x, const T& y)
{
	return x <= y ? y : x;
}

#endif