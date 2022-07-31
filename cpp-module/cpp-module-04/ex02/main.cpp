#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int maintest()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	return 0;
}

int main(void)
{
	maintest();
	// system("leaks brain");
}
