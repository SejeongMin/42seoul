#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data data;
	data._data = 1;
	data._str = std::string("data string");

	uintptr_t	dataPtr = serialize(&data);

	std::cout << "serialized data(dec): " << dataPtr << std::endl;
	std::cout << std::endl;

	Data* data2  = deserialize(dataPtr);

	std::cout << "_data: " << data2->_data << std::endl;
	std::cout << "_str: " << data2->_str << std::endl;

	std::cout << std::endl;

	std::cout << "original Data :		" << &data << std::endl;
	std::cout << "deserialized Data :	" << data2 << std::endl;

	return (0);
}
