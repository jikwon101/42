#include "PowerFist.hpp"

PowerFist::PowerFist():AWeapon("Power Fist", 8, 50){}

PowerFist::~PowerFist(){}

PowerFist::PowerFist(PowerFist const & src)
{	
	setName(src.getName());
	setDamage(src.getDamage());
	setAPCost(src.getAPCost());
}

PowerFist& PowerFist::operator = (PowerFist const &src)
{
	if (this != &src)
	{	
		setName(src.getName());
		setDamage(src.getDamage());
		setAPCost(src.getAPCost());
	}
	return (*this);
}

void	PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
