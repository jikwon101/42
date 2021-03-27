#include "RadScorpion.hpp"

RadScorpion::RadScorpion():Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & src)
{	
	setType(src.getType());
	setHP(src.getHP());
	std::cout << "* click click click *" << std::endl;
}

RadScorpion& RadScorpion::operator=(RadScorpion const &src)
{
	if (this != &src)
	{	
		setType(src.getType());
		setHP(src.getHP());
	}
	return (*this);
}
