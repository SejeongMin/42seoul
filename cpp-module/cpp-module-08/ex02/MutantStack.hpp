#ifndef MUTANT_STACK
# define MUTANT_STACK

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	// typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

	MutantStack(){}

	MutantStack(const MutantStack& m){
		*this = m;
	}

	~MutantStack(){}

	MutantStack& operator=(const MutantStack& m){
		std::stack<T>::operator=(m);
		return *this;
	}

	iterator begin(){
		return this->c.begin();
	}

	iterator end(){
		return this->c.end();
	}

	const_iterator cbegin() const{
		return this->c.cbegin();
	}

	const_iterator cend() const{
		return this->c.cend();
	}

};

#endif