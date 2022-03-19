#include "AMateria.hpp"

/*
** Coplien's form
*/
AMateria::AMateria(){}

AMateria::~AMateria(){}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	this->_xp = 0;
}

AMateria::AMateria(AMateria const & src)
{
	this->_type = src.getType();
	this->_xp = src.getXP();
}

AMateria& AMateria::operator=(AMateria const & src)
{
	if (this != &src)
	{
		this->_type = src.getType();
		this->_xp = src.getXP();
	}
	return (*this);
}

/*
** Member Function
*/
std::string const& AMateria::getType() const
{
	return (this->_type);
}

unsigned int AMateria::getXP() const
{
	return (this->_xp);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	this->_xp += 10;
}
