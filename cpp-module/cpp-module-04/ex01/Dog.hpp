#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

public:
    Dog();
    Dog(const Dog& d);
    Dog(const Brain& b);
    ~Dog();
    Dog& operator=(const Dog& d);
    virtual void    makeSound() const;
    void    setIdeas(int idx, std::string txt);
    const std::string& getIdeas(int idx) const;

private:
    Brain* brain;

};

#endif
