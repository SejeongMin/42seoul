#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal{

public:
    Animal();
    Animal(const Animal& a);
    virtual ~Animal();
    Animal& operator=(const Animal& a);
    virtual void    makeSound() const = 0;

    const std::string& getType() const;

protected:
    std::string type;

};

#endif
