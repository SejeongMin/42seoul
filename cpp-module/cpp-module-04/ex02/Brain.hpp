#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {

public:
	Brain();
	Brain(const Brain& b);
	~Brain();
	Brain& operator=(const Brain& b);

	void	setIdeas(int idx, std::string txt);
	const std::string&	getIdeas(int idx) const;

private:
	std::string	ideas[100];

};

#endif