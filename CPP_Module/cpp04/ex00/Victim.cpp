#include "Victim.hpp"

/*
** Coplien's forn
*/
Victim::Victim(){};

Victim::Victim(std::string name)
{
	this->name = name;
	std::cout << "Some random victim called ";
	std::cout << this->name;
	std::cout << " just appeared!";
	std::cout << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim ";
	std::cout << this->name;
	std::cout << " just died for no apparent reason!";
	std::cout << std::endl;
}

Victim::Victim(const Victim& src)
{
	this->name = src.name;
	std::cout << "Some random victim called ";
	std::cout << this->name;
	std::cout << " just appeared!";
	std::cout << std::endl;
}

Victim& Victim::operator = (const Victim& src)
{
	if (this != &src)
	{
		this->name = src.name;
	}
	return (*this);
}

/*
** Getter
*/
std::string Victim::getName(void) const
{
	return (this->name);
}

/*
** Member Function
*/
void	Victim::getPolymorphed(void) const
{
	std::cout << this->name;
	std::cout << " has been turned into a cute little sheep!";
	std::cout << std::endl;
}

/*
** Overload ostream operator
*/
std::ostream& operator << (std::ostream& os, const Victim& src)
{
	os << "I'm ";
	os << src.getName();
	os << " and I like otters!\n";
	return (os);
}
