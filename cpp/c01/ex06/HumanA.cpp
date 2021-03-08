#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << this->name;
	std::cout << " attacks with his ";
	std::cout << this->weapon.getType();
	std::cout << std::endl;

}

HumanA::HumanA(std::string name, Weapon &weapon):weapon(weapon)
{
	this->name = name;
	this->weapon = weapon;
}
