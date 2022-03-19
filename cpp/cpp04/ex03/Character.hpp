#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria*	_inventory[4];
	int			num_of_materia;
	Character();
	bool		isInInventory(AMateria *m);
public:
	Character(std::string const name);
	Character(Character const & src);
	Character& operator=(Character const & src);
	virtual ~Character();
	virtual std::string const &	getName() const;
	virtual void				equip(AMateria *m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& target);
	virtual	int					getNumOfMateria(void) const;
};
#endif
