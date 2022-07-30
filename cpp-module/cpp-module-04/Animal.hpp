#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal{

public:
    Animal();
    Animal(std::string t);
    Animal(const Animal& a);
    ~Animal();
    Animal& operator=(const Animal& a);
    void    makeSound();

protected:
    std::string type;

};

#endif
