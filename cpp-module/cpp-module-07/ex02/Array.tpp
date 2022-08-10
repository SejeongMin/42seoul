template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0)
{
	_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_array = new T[n];
}

template <typename T>
Array<T>::Array(const Array& a)
{
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
	delete[] _array;
	_size = 0;
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

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw IndexOutOfRangeException();
	return _array[index];
}
