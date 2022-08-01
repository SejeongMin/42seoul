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
	std::cout << "\n====================================\n" << std::endl;
	{
		Dog* dog1 = new Dog();
		Dog* dog2 = new Dog(*dog1);

		std::cout << std::endl;

		dog1->setIdeas(0, "1st idea");
		std::cout << "dog1->brain[0] : " << dog1->getIdeas(0) << std::endl;
		std::cout << "dog2->brain[0] : " << dog2->getIdeas(0) << std::endl;

		std::cout << std::endl;

		delete dog1;
		delete dog2;
	}
	std::cout << "\n====================================\n" << std::endl;
	{
		Animal* animal[10];
		std::cout << std::endl;

		for (int i = 0; i < 5; i++) {
			animal[i] = new Dog();
			std::cout << std::endl;
		}
		std::cout << std::endl;

		for (int i = 5; i < 10; i++) {
			animal[i] = new Cat();
			std::cout << std::endl;
		}
		std::cout << std::endl;

		for (int i = 0; i < 10; i++) {
			delete animal[i];
			std::cout << std::endl;
		}

		// Cat c;
		// Cat c2;
		// c2 = c;
		// std::cout << std::endl;

		// Dog d;
		// Dog d2;
		// d2 = d;
		// std::cout << std::endl;
	}
	return 0;
}

int main(void)
{
	maintest();
	// system("leaks brain");
}
