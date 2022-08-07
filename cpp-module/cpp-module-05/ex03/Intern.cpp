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

ShrubberyCreationForm* newShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

Form*    Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (int i = 0; i < 3; i++){
        if (!formNames[i].compare(formName))
        {
            std::cout << "Intern creates " << formNames[i] << " form." << std::endl;
            switch (i)
            {
                case 0:
                    return new ShrubberyCreationForm(target);
                case 1:
                    return new RobotomyRequestForm(target);
                case 2:
                    return new PresidentialPardonForm(target);
                default:
                    break;
            }
        }
    }
    throw NonValidFormNameException();
}
