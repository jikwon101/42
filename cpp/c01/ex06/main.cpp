#include <iostream>
#include <string>

class Weapon
{
private:
	std::string type;
public:
	void setType(std::string type);
	const std::string &getType();
	Weapon(std::string type);
};

Weapon::Weapon(std::string type)
{
	this->type = type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string& Weapon::getType()
{
	return (this->type);
}


class HumanA
{
private:
	Weapon &weapon;
	std::string name;

public:
	void attack();
	HumanA(std::string name, Weapon &weapon);
};

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

class HumanB
{
public:
	Weapon *weapon;
	std::string name;
	void attack();
	HumanB(std::string name);
	void setWeapon(Weapon &weapon);

};

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

int main()
{	
	{
			Weapon  club = Weapon("11");

			HumanA bob("Bob", club);
			bob.attack();
			club.setType("22");
			bob.attack();
	}
	{

			Weapon  club = Weapon("11");

			HumanB jim("Jim");
			jim.setWeapon(club);
			jim.attack();
			club.setType("22");
			jim.attack();
			std::cout << "문구 수정필요\n";
	}
}
