#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class AMateria;
#include "ICharacter.hpp"
#include <string>
#include <iostream>

class AMateria
{
private:
	AMateria();
	std::string		_type;
	unsigned int	_xp;
public:
	AMateria(std::string const & type);
	AMateria(AMateria const & src);
	AMateria& operator=(AMateria const & src);
	virtual ~AMateria();
	std::string const &	getType() const;
	unsigned int		getXP() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif
