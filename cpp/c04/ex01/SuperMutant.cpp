#include "SuperMutant.hpp"

SuperMutant::SuperMutant():Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & src)
{	
	setType(src.getType());
	setHP(src.getHP());
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant& SuperMutant::operator=(SuperMutant const &src)
{
	if (this != &src)
	{		
		setType(src.getType());
		setHP(src.getHP());
	}
	return (*this);
}

void	SuperMutant::takeDamage(int amount)
{
	int actual_amount;

	if (amount < 0)
		return ;
	actual_amount = (amount - 3 < 0) ? 0 : (amount - 3);
	Enemy::takeDamage(actual_amount);
}
