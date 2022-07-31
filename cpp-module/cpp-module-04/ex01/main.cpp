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
	{
		Dog* dog1 = new Dog();
		Dog* dog2 = new Dog(*dog1);

		dog1->setIdeas(0, "1st idea");
		std::cout << dog1->getIdeas(0) << std::endl;
		std::cout << dog2->getIdeas(0) << std::endl;

		delete dog1;
		delete dog2;
	}
	return 0;
}

int main(void)
{
	maintest();
	// system("leaks brain");
}
