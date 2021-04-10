#include "Generator.hpp"

Base *generate(void)
{
	int num;

	num = rand() % 3;
	if (num == 0)
	{
		std::cout << "Generatre A type\n";
		return (new A);
	}
	else if (num == 1)
	{
		std::cout << "Generatre B type\n";
		return (new B);
	}
	std::cout << "Generatre C type\n";
	return (new C);
}
