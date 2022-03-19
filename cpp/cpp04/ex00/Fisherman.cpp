#include "Fisherman.hpp"

/*
** Coplien's form
*/

Fisherman::Fisherman(void){}

Fisherman::Fisherman(std::string name)
{
	this->name = name;
	std::cout << "Some random victim called ";
	std::cout << this->name;
	std::cout << " just appeared!";
	std::cout << std::endl;
}

Fisherman::~Fisherman()
{
	std::cout << "ARrrrrr..." << std::endl;
}

Fisherman::Fisherman(const Fisherman& src)
{
	this->name = src.name;
	std::cout << "Some random victim called ";
	std::cout << this->name;
	std::cout << " just appeared!";
	std::cout << std::endl;
}

Fisherman& Fisherman::operator = (const Fisherman& src)
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
void	Fisherman::getPolymorphed(void) const
{
	std::cout << this->name;
	std::cout << " has been turned into a tree!";
	std::cout << std::endl;
}

/*
** Overload ostream operator
*/
std::ostream& operator << (std::ostream& os, const Fisherman& src)
{
	os << "I'm ";
	os << src.getName();
	os << " and I like fishes!\n";
	return (os);
}
