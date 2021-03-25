#include <iostream>

class Fruit
{
public:
	Fruit();
};

Fruit::Fruit()
{
	std::cout << "Consturctor of Fruit" << std::endl;
}

class Stroberi : virtual public Fruit
{
public:
	Stroberi();
};

Stroberi::Stroberi()
{
	std::cout << "Constructor of Stroberi" << std::endl;
}

class Banana : virtual public Fruit
{
public:
	Banana();
};

Banana::Banana()
{
	std::cout << "Constructor of Banana" << std::endl;
}

class Juice : public Stroberi, public Banana
{
public:
	Juice();
};

Juice::Juice()
{
	std::cout << "Constructor of Juice" << std::endl;
}
int main()
{
	std::cout << "-----------" << std::endl;
	Fruit f;

	std::cout << "-----------" << std::endl;
	Stroberi s;

	std::cout << "-----------" << std::endl;
	Banana b;
	
	std::cout << "-----------" << std::endl;
	Juice j;
}
