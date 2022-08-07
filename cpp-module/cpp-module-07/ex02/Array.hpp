#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template <typename T>
class Array{
public:
	Array();
	Array(unsigned int n);
	Array(const &Array c);
	~Array();
	Array& operator=(const Array& a);

	class IndexOutOfRangeException : public std::exception{
	public:
		virtual const char* what() const throw();
	}

	unsigned int size() const;

private:
	T* _array;

};

#endif