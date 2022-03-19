#include "Peon.hpp"

/*
** Coplien's form
*/

Peon::Peon(void){}

Peon::Peon(std::string name)
{
	this->name = name;
	std::cout << "Some random victim called ";
	std::cout << this->name;
	std::cout << " just appeared!";
	std::cout << std::endl;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(const Peon& src)
{
	this->name = src.name;
	std::cout << "Some random victim called ";
	std::cout << this->name;
	std::cout << " just appeared!";
	std::cout << std::endl;
	std::cout << "Zog zog." << std::endl;
}

Peon& Peon::operator = (const Peon& src)
{
	if (this != &src)
	{
		this->name = src.name;
	}
	return (*this);
}

/*
** Member Function
*/
void	Peon::getPolymorphed(void) const
{
	std::cout << this->name;
	std::cout << " has been turned into a pink pony!";
	std::cout << std::endl;
}

/*
** Overload ostream operator
*/
std::ostream& operator << (std::ostream& os, const Peon& src)
{
	os << "I'm ";
	os << src.getName();
	os << " and I like otters!\n";
	return (os);
}
