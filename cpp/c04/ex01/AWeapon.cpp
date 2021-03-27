#include "AWeapon.hpp"

AWeapon::AWeapon(){}

AWeapon::~AWeapon(){}

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
{
	setName(name);
	setAPCost(apcost);
	setDamage(damage);
}

AWeapon::AWeapon(AWeapon const & src)
{
	setName(src.getName());
	setAPCost(src.getAPCost());
	setDamage(src.getDamage());
}

AWeapon& AWeapon::operator = (AWeapon const &src)
{
	if (this != &src)
	{	
		setName(src.getName());
		setAPCost(src.getAPCost());
		setDamage(src.getDamage());	
	}
	return (*this);
}

const std::string AWeapon::getName(void) const
{
	return (this->name);
}

int AWeapon::getAPCost() const
{
	return (this->apcost);
}
int AWeapon::getDamage() const
{
	return (this->damage);
}

void AWeapon::setDamage(int val)
{
	if (val < 0)
		val = 0;
	this->damage = val;
}
void AWeapon::setAPCost(int val)
{
	if (val < 0)
		val = 0;
	this->apcost = val;
}
void AWeapon::setName(std::string val)
{
	this->name = val;
}

