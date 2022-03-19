#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle!";
	std::cout << std::endl;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh...";
	std::cout << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const & src)
{
	(void)src;
	std::cout << "Tactical Marine ready for battle!";
	std::cout << std::endl;
}

TacticalMarine& TacticalMarine::operator=(TacticalMarine const & src)
{
	(void)src;
	return (*this);
}

/*
** Member Function
*/
ISpaceMarine* TacticalMarine::clone() const
{
	ISpaceMarine *temp = new TacticalMarine(*this);
	return (temp);
}

void TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT!";
	std::cout << std::endl;
}

void TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *";
	std::cout << std::endl;
}

void TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with a chainsword *";
	std::cout << std::endl;
}

