#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    {
        Form f1("form1", 100, 100);
        std::cout << std::endl;
        Bureaucrat b1("b1", 1);
        std::cout << std::endl;
        Bureaucrat b2("b2", 110);
        std::cout << std::endl;
        b1.signForm(f1);
        std::cout << std::endl;
        b2.signForm(f1);
        std::cout << std::endl;
    }
    std::cout << "\n==================================\n" << std::endl;
    {
        try{
            Form f2("form2", 0, 1);
        }
        catch(std::exception & e){
            std::cerr << e.what() << std::endl;
        }
    }
}
