#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\n========================================\n" << std::endl;
	{
		try{
			Span sp = Span(6);
			for(int i = 0; i < 7; i++){
				sp.addNumber(i);
			}
		} catch(std::exception & e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n========================================\n" << std::endl;
	{
		try{
			Span sp = Span(10);
			sp.addNumber(1);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch(std::exception & e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n========================================\n" << std::endl;
	{
		std::vector<int> v;
		for (int i = 0; i < 20000; i++){
			v.push_back(i);
		}
		Span sp = Span(20000);
		sp.addNumber(v.begin(), v.end());
		std::cout << "span size : " << sp.getSize() << std::endl;
		std::cout << "longest span : " << sp.longestSpan() << std::endl;
		std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
	}
}