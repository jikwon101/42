#include "Sorcerer.hpp"

/*
** Coplien's form
*/
Sorcerer::Sorcerer(){}

Sorcerer::Sorcerer(std::string name, std::string title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", " << this->title;
	std::cout << ", is dead. Consequences will never be the same!";
	std::cout << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer& src)
{
	this->name = src.name;
	this->title = src.title;
	std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer& Sorcerer::operator = (const Sorcerer& src)
{
	if (this != &src)
	{
		this->name = src.name;
		this->title = src.title;
	}
	return (*this);
}

/*
** Getter
*/
std::string Sorcerer::getName(void) const
{
	return (this->name);
}

std::string Sorcerer::getTitle(void) const
{
	return (this->title);
}

/*
** Member Function
*/
void	Sorcerer::polymorph(const Victim& src) const
{
	src.getPolymorphed();
}


/*
** Overload ostream operator
*/
std::ostream& operator << (std::ostream& os, const Sorcerer& src)
{
	os << "I am ";
	os << src.getName();
	os << ", ";
	os << src.getTitle();
	os << ", and I like ponies!\n";
	return (os);
}
