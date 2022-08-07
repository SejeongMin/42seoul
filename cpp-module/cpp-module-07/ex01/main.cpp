#include "iter.hpp"

void func(int& i)
{
	std::cout << i << std::endl;
}

template <typename T>
void func2(T& t)
{
	std::cout << t << std::endl;
}

int main(void)
{
	{
		int arr[] = {1,2,3};

		iter(arr, 3, func);

		const int arr2[] = {4,5,6};

		iter(arr2, 3, func2);
	}
	std::cout << "\n==============================\n" << std::endl;
	{
		std::string arr[] = {"1", "2", "3"};

		iter(arr, 3, func2);
	}
}
