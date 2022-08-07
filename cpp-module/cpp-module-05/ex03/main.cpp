#include <iostream>
#include "Intern.hpp"

int main() {
    {
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
    }
    std::cout << "\n==============================================\n" << std::endl;
    {
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        delete rrf;
    }
    std::cout << "\n==============================================\n" << std::endl;
    {
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        delete rrf;
    }
    std::cout << "\n==============================================\n" << std::endl;
    {
        try{
            Intern someRandomIntern;
            Form* f;
            f = someRandomIntern.makeForm("not valid form name", "home");
            delete f;
        } catch(std::exception & e){
            std::cout << e.what() << std::endl;
        }
    }
}
