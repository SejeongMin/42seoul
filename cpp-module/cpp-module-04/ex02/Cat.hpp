#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

public:
    Cat();
    Cat(const Cat& c);
    ~Cat();
    Cat& operator=(const Cat& c);
    virtual void    makeSound() const;

    void    setIdeas(int idx, std::string txt);
    const std::string& getIdeas(int idx) const;

private:
    Brain* brain;

};

#endif
