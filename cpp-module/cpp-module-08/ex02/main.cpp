#include "MutantStack.hpp"
#include <list>

int main(void)
{
	std::cout << "\n============ MutantStack =============\n" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		while (s.size()){
			std::cout << s.top() << std::endl;
			s.pop();
		}
	}
	std::cout << "\n================ List =================\n" << std::endl;
	{
		std::list<int> l;
		l.push_back(5);
		l.push_back(17);
		std::cout << l.back() << std::endl;
		l.pop_back();
		std::cout << l.size() << std::endl;
		l.push_back(3);
		l.push_back(5);
		l.push_back(737);
		//[...]
		l.push_back(0);
		std::list<int>::iterator it = l.begin();
		std::list<int>::iterator ite = l.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(l);
	}
	std::cout << "\n===================================\n" << std::endl;
	{
		MutantStack<int> m;
		for (int i = 0; i < 5; i++){
			m.push(i);
		}

		MutantStack<int>::iterator iter;
		for (iter = m.begin(); iter != m.end(); iter++){
			std::cout << *iter << std::endl;
		}
		
		std::cout << "\n===================================\n" << std::endl;
		
		MutantStack<int>::reverse_iterator riter;
		for (riter = m.rbegin(); riter != m.rend(); riter++){
			std::cout << *riter << std::endl;
		}
	}
}