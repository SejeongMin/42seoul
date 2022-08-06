#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>

struct Data{
	int _data;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
