#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data data;
	data._data = 42;
	Data *data2;

	data2 = deserialize(serialize(&data));

	std::cout << &data << std::endl;
	std::cout << data2 << std::endl;

	std::cout << data._data << std::endl;
	std::cout << data2->_data << std::endl;

	return (0);
}
