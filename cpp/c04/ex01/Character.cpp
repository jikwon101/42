#include "Character.hpp"

/*
** Coplien's form
*/
Character::Character(void){}

Character::~Character(void){}

Character::Character(std::string const & name)
{
	this->name = name;
	this->ap = 40;
	this->weapon = nullptr;
}

Character::Character(const Character& src)
{
	this->name = src.name;
	this->ap = src.ap;
	this->weapon = src.weapon;
}

Character& Character::operator=(Character const & src)
{
	if (this != &src)
	{
		this->name = src.name;
		this->ap = src.ap;
		this->weapon = src.weapon;
	}
	return (*this);
}


/*
** Getter
*/
const std::string	Character::getName(void) const
{
	return (this->name);
}

int					Character::getAP(void) const
{
	return (this->ap);
}

const std::string	Character::getWeaponName(void) const
{
	return (this->weapon->getName());
}


/*
** Member Function
*/
void	Character::recoverAP(void)
{
	ap += 10;
	if (ap > 40)
		ap = 40;
}

void	Character::equip(AWeapon *src)
{
	if (src == nullptr)
		return ;
	weapon = src;
}

void	Character::attack(Enemy *enemy)
{
	if (ap < 0 || weapon == nullptr || enemy == nullptr)
		return ;
	if (ap - weapon->getAPCost() < 0)
		return ;
	ap -= weapon->getAPCost();
	std::cout << name << " attacks " << enemy->getType() << " with a " << getWeaponName() << std::endl;
	weapon->attack();
	enemy->takeDamage(weapon->getDamage());
	if (enemy->getHP() <= 0)
		delete enemy;
}

bool	Character::isArmed(void) const
{
	if (this->weapon == nullptr)
		return (false);
	else
		return (true);
}


/*
** Overload ostream operator
*/
std::ostream& operator << (std::ostream& os, const Character& src)
{	
	os << src.getName();
	os << " has ";
	os << src.getAP();

	if (src.isArmed() == true)
	{
		os << " AP and wields a ";
		os << src.getWeaponName();
		os << std::endl;
	}
	else
	{
		os << " AP and is unarmed";
		os << std::endl;
	}
	return (os);
}
