#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	std::cout << this->name;
	std::cout << " attacks with his ";
	std::cout << this->weapon->getType();
	std::cout << std::endl;

}

HumanB::HumanB(std::string name)
{
	this->name = name;
}
