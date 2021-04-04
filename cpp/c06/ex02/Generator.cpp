#include "Generator.hpp"

Base *generate(void)
{
	int num;

	num = rand() % 3;
	std::cout << num << std::endl;
	if (num == 0)
		return (new A);
	else if (num == 1)
		return (new B);
	return (new C);
}
