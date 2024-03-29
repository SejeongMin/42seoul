#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int maintest()
{
	{
		const Animal* meta = new Animal();
		std::cout << std::endl;
		const Animal* j = new Dog();
		std::cout << std::endl;
		const Animal* i = new Cat();

		std::cout << std::endl;
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		std::cout << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		std::cout << std::endl;

		delete meta;
		std::cout << std::endl;
		delete j;
		std::cout << std::endl;
		delete i;
	}
	std::cout << "\n===========================================\n" << std::endl;
	{
		const WrongAnimal* wa = new WrongAnimal();
		std::cout << std::endl;
		const WrongAnimal* wc = new WrongCat();

		std::cout << std::endl;

		wa->makeSound();
		wc->makeSound();

		std::cout << std::endl;

		delete wa;
		std::cout << std::endl;
		delete wc;
	}
	return 0;
}

int main(void)
{
	maintest();
	system("leaks animal");
}
