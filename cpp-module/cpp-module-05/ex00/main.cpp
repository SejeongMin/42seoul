#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat b("b", 2);
        std::cout << std::endl;
        b.upGrade();
        std::cout << b << std::endl;
        b.upGrade();
        std::cout << b << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "==================================" << std::endl;
    try
    {
        Bureaucrat b("b", 149);
        std::cout << std::endl;
        b.downGrade();
        std::cout << b << std::endl;
        b.downGrade();
        std::cout << b << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "==================================" << std::endl;
    try
    {
        Bureaucrat b("b", 151);
        std::cout << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "==================================" << std::endl;
    try
    {
        Bureaucrat b("b", 0);
        std::cout << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}
