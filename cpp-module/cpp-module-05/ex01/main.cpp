#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Form f1("form1", 100, 100);
        Bureaucrat b1("b1", 0);
        Bureaucrat b2("b2", 110);
    
        b1.signForm(f1);
        b2.signForm(f1);
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
