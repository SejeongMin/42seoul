#include "Span.hpp"
#include <numeric>

Span::Span()
{
	_vector = std::vector<int>(0);
	_vector.reserve(0);
}

Span::Span(unsigned int n)
{
	_vector = std::vector<int>(0);
	_vector.reserve(n);
}

Span::Span(const Span& s)
{
	_vector = std::vector<int>(s.getVector());
	_vector.reserve(s.getCapacity());
}

Span::~Span()
{}

Span& Span::operator=(const Span& s)
{
	if (this == &s)
		return *this;
	_vector.clear();
	_vector.reserve(s.getCapacity());
	std::copy(s.getVector().begin(), s.getVector().end(), std::back_inserter(_vector));
	return *this;
}

size_t	Span::getCapacity() const
{
	return _vector.capacity();
}

size_t	Span::getSize() const
{
	return _vector.size();
}

std::vector<int>	Span::getVector() const
{
	return _vector;
}

void	Span::addNumber(int value)
{
	if (getCapacity() == getSize())
		throw NoSpaceException();
	_vector.push_back(value);
}

int Span::longestSpan()
{
	if (_vector.size() < 2)
		throw NoSpanException();
	std::vector<int> v(_vector);
	std::sort(v.begin(), v.end());
	return v.back() - v.front();
}

int Span::shortestSpan()
{
	if (_vector.size() < 2)
		throw NoSpanException();
	std::vector<int> v(_vector);
	std::sort(v.begin(), v.end());
	std::adjacent_difference(v.begin(), v.end(), v.begin());
	std::sort(v.begin() + 1, v.end());
	return v.at(1);
}

const char* Span::NoSpaceException::what() const throw()
{
	return "No capacity";
}

const char* Span::NoSpanException::what() const throw()
{
	return "Not enough numbers";
}
