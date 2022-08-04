#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try
    {
        Bureaucrat b("b", 1);
        std::cout << "ShrubberyCreationForm Test!!!" << std::endl;
        ShrubberyCreationForm s("home");
        b.executeForm(s);
        std::cout << std::endl;
        b.signForm(s);
        b.executeForm(s);
        std::cout << std::endl;
        std::cout << s << std::endl << std::endl;;

    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
