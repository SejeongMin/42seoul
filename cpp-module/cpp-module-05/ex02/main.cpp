#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "\n==================ShrubberryCreation=====================\n" << std::endl;
    try
    {
        Bureaucrat b("b", 1);
        ShrubberyCreationForm s("home");
        b.executeForm(s);
        std::cout << std::endl;
        b.signForm(s);
        std::cout << std::endl;
        b.executeForm(s);
        std::cout << std::endl;
        std::cout << s << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n====================RobotomyRequest=====================\n" << std::endl;
    try
    {
        Bureaucrat b("b", 1);
        RobotomyRequestForm r("school");
        b.executeForm(r);
        std::cout << std::endl;
        b.signForm(r);
        std::cout << std::endl;
        b.executeForm(r);
        std::cout << std::endl;
        std::cout << r << std::endl;
        std::cout << std::endl;
        b.setGrade(150);
        b.executeForm(r);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n==================PresidentialPardon=====================\n" << std::endl;
    try
    {
        Bureaucrat b("b", 1);
        std::cout << std::endl;
        PresidentialPardonForm p("cluster");
        std::cout << std::endl;
        b.executeForm(p);
        std::cout << std::endl;
        b.signForm(p);
        std::cout << std::endl;
        b.executeForm(p);
        std::cout << std::endl;
        std::cout << p << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}
