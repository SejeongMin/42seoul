#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try
    {
        Bureaucrat b("b", 0);
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
