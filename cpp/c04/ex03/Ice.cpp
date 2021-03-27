#include "Ice.hpp"

/*
** Coplien's form
*/
Ice::Ice():AMateria("ice"){}

Ice::Ice(Ice const & src):AMateria(src){}

Ice::~Ice(){}

Ice& Ice::operator=(Ice const & src)
{
	AMateria *original;
	AMateria *reference;

	original = (AMateria *)(this);
	reference = (AMateria *)(&src);
	*original = *reference;
	return (*this);
}

/*
** Member function
*/
AMateria*	Ice::clone() const
{
	AMateria *copy = new Ice(*this);
	return (copy);
}

void		Ice::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.getName();
	std::cout << " *" << std::endl;
}
