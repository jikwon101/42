#include "Pony.hpp"

Pony::Pony(int num)
{
	this->num = num;
	std::cout << "The " << num << " is created" << std::endl;
}

Pony::~Pony()
{
	std::cout << "The " << num << " is destoryed" << std::endl;
}

void Pony::Sing(void)
{
	for (int i = 0; i < this->num ; i++)
	{
		std::cout << "I am " << this->num << " ~." << std::endl;
	}
}
