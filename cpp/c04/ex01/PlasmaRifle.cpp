#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle():AWeapon("Plasma Rifle", 5, 21){}

PlasmaRifle::~PlasmaRifle(){}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src)
{
	setName(src.getName());
	setDamage(src.getDamage());
	setAPCost(src.getAPCost());
}

PlasmaRifle& PlasmaRifle::operator=(PlasmaRifle const &src)
{
	if (this != &src)
	{	
		setName(src.getName());
		setDamage(src.getDamage());
		setAPCost(src.getAPCost());
	}
	return (*this);
}

void	PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
