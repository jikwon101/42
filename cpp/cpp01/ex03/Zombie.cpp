#include "Zombie.hpp"

Zombie::Zombie(){}

void Zombie::setType(int type)
{
	this->type = type;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << "<" << this->name << " (" << this->type << ")> " << "Eeeeeeeeeeeek......." << std::endl;
	
}
