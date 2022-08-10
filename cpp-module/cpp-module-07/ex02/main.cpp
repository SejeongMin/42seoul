#include <iostream>
#include "Array.hpp"

int main(void)
{
    Array<int> a(5);
    std::cout << "size of a = " << a.size() << std::endl;
    for (int i = 0; i < 5; i++){
        a[i] = i;
    }
    std::cout << std::endl;
    std::cout << "a : ";
    for (int i = 0; i < 5; i++){
        std::cout << " " << a[i];
    }
    std::cout << std::endl;
    std::cout << "\n===========================\n" << std::endl;
    Array<int>  b(a);
    std::cout << "size of b = " << b.size() << std::endl;
    std::cout << std::endl;
    std::cout << "b : ";
    for (int i = 0; i < 5; i++){
        std::cout << " " << b[i];
    }
    std::cout << std::endl;
    std::cout << "\n===========================\n" << std::endl;
    try{
        std::cout << a[-1];
    } catch(std::exception & e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    try{
        std::cout << b[6];
    } catch(std::exception & e){
        std::cout << e.what() << std::endl;
    }
}
