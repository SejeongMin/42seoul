#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>

class Span {

public:
	Span(unsigned int n);
	Span(const Span& s);
	Span& operator=(const Span& s);
	~Span();

	void	addNumber(int value);

	template <typename T>
	void	addNumber(T begin, T end)
	{
		if (std::distance(begin, end) < static_cast<long>(getCapacity() - getSize()))
			throw NoSpaceException();
		while (begin != end)
		{
			_vector.push_back(*begin);
			begin++;
		}
	}

	int shortestSpan();
	int longestSpan();

	class NoSpaceException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	size_t	getCapacity() const;
	size_t	getSize() const;
	std::vector<int>	getVector() const;

private:
	Span();
	std::vector<int> _vector;

};

#endif
