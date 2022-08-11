#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int> m;
	for (int i = 0; i < 5; i++){
		m.push(i);
	}

	MutantStack<int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++){
		std::cout << *iter << std::endl;
	}
	
	std::cout << "================================" << std::endl;
	
	MutantStack<int>::const_iterator citer;
	for (citer = m.begin(); citer != m.end(); citer++){
		std::cout << *citer << std::endl;
	}
}