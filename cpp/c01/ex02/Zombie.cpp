#include "Zombie.hpp"

//Output something along the lines of: at least the name and type.
Zombie::Zombie(std::string name)
{
	this->name = name;
}
void Zombie::announce(void)
{
	std::cout << "<" << this->name << " (" << this->type << ")> " << "Eeeeeeeeeeeek......." << std::endl;
	
}
