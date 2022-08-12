#include "easyfind.hpp"

#include <iostream>
#include <list>
#include <string>
#include <vector>

int main(void) {
	std::list<int> l;
	std::vector<int> v;

	for (int i = 0 ; i < 10 ; ++i) {
		l.push_back(i);
		v.push_back(i);
	}
	std::cout << "============ List ============\n" << std::endl;
	try {
		std::list<int>::iterator iter = easyfind(l, 6);
		std::cout << "found " << 6 << "(index : "
			<< std::distance(std::begin(l), iter) << ")" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n============ Vector ============\n" << std::endl;
	try {
		std::vector<int>::iterator iter = easyfind(v, 1);
		std::cout << "found " << 1 << "(index : "
			<< std::distance(std::begin(v), iter) << ")" << std::endl;
		std::cout << std::endl;
		iter = easyfind(v, 10);
		std::cout << "found " << 10 << "(index : "
			<< std::distance(std::begin(v), iter) << ")" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}