#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n):size(n), type(-1)
{
	std::string name;

	if (n < 0)
	{
		std::cout << "Error in horde size." << std::endl;
		std::cout << "It will reset to 0." << std::endl;
		this->size = 0;
	}
	this->horde = new Zombie[this->size];
	for (int i = 0 ; i < this->size ; i++)
	{
		name = RandomName();
		this->horde[i].setName(name);
	}

}

ZombieHorde::~ZombieHorde()
{
	delete[] horde;
}

std::string ZombieHorde::RandomName(void)
{
	int namelen;
	std::string name;
	const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	namelen = 8;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 61);
	for (int i = 0 ; i < namelen ; i++)
		name += (alphanum[dis(gen)]);
	return (name);
}

void ZombieHorde::setType(int type)
{
	if (this->type != -1)
	{
		std::cout << "Error: They are already allocated in " << this->type << "." << std::endl;
		return ;
	}
	this->type = type;
	for (int i = 0; i < this->size ; i++)
	{
		this->horde[i].setType(this->type);
	}
}

void ZombieHorde::announce(void)
{
	if (this->size == 0)
	{
		std::cout << "Error: There are no horde." << std::endl;
		return ;
	}
	if (this->type == -1)
	{
		std::cout << "Error: Set type first before make them announce." << std::endl;
		std::cout << "Use setType([type])" << std::endl;
		return ;
	}
	for (int i = 0; i < this->size ; i++)
	{
		this->horde[i].announce();
	}
}


