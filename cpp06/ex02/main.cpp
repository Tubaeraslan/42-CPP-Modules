#include "Functions.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	for (int i = 0; i < 10; i++)
	{
		Base *ptr = generate();

		std::cout << "identify(Base*): ";
		identify(ptr);
		std::cout << "identify(Base&): ";
		identify(*ptr);

		delete ptr;
	}
	return 0;
}
