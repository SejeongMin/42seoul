template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0)
{
	std::cout << "Array default constructor called." << std::endl;
	_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	std::cout << "Array constructor called." << std::endl;
	_array = new T[n];
}

template <typename T>
Array<T>::Array(const Array& a)
{
	std::cout << "Array copy constructor called." << std::endl;
	_array = 0;
	*this = a;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& a)
{
	_size = a._size;
	if (_array)
		delete[] _array;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++){
		_array[i] = a._array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array destructed." << std::endl;
	delete[] _array;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
const char* Array<T>::IndexOutOfRangeException::what() const throw()
{
	return "EXCEPTION: Index out of range.";
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw IndexOutOfRangeException();
	return _array[index];
}
