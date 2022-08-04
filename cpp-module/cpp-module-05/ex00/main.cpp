#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat b0("b0", 2);
        Bureaucrat b1("b1", 100);
        Bureaucrat b2("b2", 160);
        Bureaucrat b3("b3", 1);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
