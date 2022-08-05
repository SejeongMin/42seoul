#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

Intern::Intern()
{
    std::cout << "Intern constructed." << std::endl;
}

Intern::Intern(const Intern& i)
{
    std::cout << "Intern copy constructor called." << std::endl;
    *this = i;
}

Intern::~Intern()
{
    std::cout << "Intern destructed." << std::endl;
}

Intern& Intern::operator=(const Intern& i)
{
    (Intern)i;
    return *this;
}

const char*    Intern::NonValidFormNameException::what() const throw()
{
    return "form name is not valid.";
}

Form*    Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (int i = 0; i < 3; i++){
        if (!formNames[i].compare(formName))
        {
            switch (i)
            {
                case 0:
                {
                    std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
                    return new ShrubberyCreationForm(target);
                }
                case 1:
                {
                    std::cout << "Intern creates RobotomyRequestForm" << std::endl;
                    return new RobotomyRequestForm(target);
                }
                case 2:
                {
                    std::cout << "Intern creates PresidentialPardonForm" << std::endl;
                    return new PresidentialPardonForm(target);
                }
                default:
                    break;
            }
        }
    }
    throw NonValidFormNameException();

}
