#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *";
	std::cout << std::endl;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'll be back...";
	std::cout << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src)
{
	(void)src;
	std::cout << "* teleports form space *";
	std::cout << std::endl;
}

AssaultTerminator& AssaultTerminator::operator=(AssaultTerminator const & src)
{
	(void)src;
	return (*this);
}

/*
** Member Function
*/
ISpaceMarine* AssaultTerminator::clone() const
{
	ISpaceMarine *temp = new AssaultTerminator(*this);
	return (temp);
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!";
	std::cout << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *";
	std::cout << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *";
	std::cout << std::endl;
}
