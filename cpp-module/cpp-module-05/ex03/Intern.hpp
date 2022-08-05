#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

# include "Form.hpp"

class Intern {

public:
    Intern();
    Intern(const Intern& i);
    ~Intern();
    Intern& operator=(const Intern& i);

    Form*    makeForm(const std::string& formName, const std::string& target);

    class NonValidFormNameException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

};

#endif