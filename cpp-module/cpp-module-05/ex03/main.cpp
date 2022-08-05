#include <iostream>
#include "Intern.hpp"

int main() {
    {
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
    }
}
