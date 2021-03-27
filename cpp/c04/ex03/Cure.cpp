#include "Cure.hpp"

/*
** Coplien's form
*/
Cure::Cure():AMateria("cure"){}

Cure::Cure(Cure const & src):AMateria(src){}

Cure::~Cure(){}

Cure& Cure::operator=(Cure const & src)
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
AMateria*	Cure::clone() const
{
	AMateria *copy = new Cure(*this);
	return (copy);
}

void		Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals ";
	std::cout << target.getName();
	std::cout << "'s wounds *";
	std::cout << std::endl;
}
