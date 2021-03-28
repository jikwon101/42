#include "Character.hpp"

/*
** Coplien's form
*/
Character::Character(){}

Character::Character(std::string const name)
{
	this->_name = name;
	this->num_of_materia = 0;
	for (int i = 0; i < 4 ; i++)
	{
		this->_inventory[i] = 0;
	}
}

Character::Character(Character const & src)
{
	this->_name = src.getName();
	this->num_of_materia = src.num_of_materia;
	for (int i = 0; i < 4 ; i++)
	{
		this->_inventory[i] = src._inventory[i];
	}
}

Character& Character::operator=(Character const & src)
{ 
	if (this != &src)
	{	
		for (int i = 0 ; i < num_of_materia ; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
		}
		this->_name = src.getName();
		this->num_of_materia = src.num_of_materia;
		for (int i = 0; i < 4 ; i++)
		{
			this->_inventory[i] = src._inventory[i];
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0 ; i < num_of_materia ; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}


/*
** Getter
*/
std::string const & Character::getName() const
{
	return (this->_name);
}

int				Character::getNumOfMateria(void) const
{
	return (this->num_of_materia);
}
/*
** Member Function
*/
void Character::equip(AMateria *m)
{
	if (this->num_of_materia == 4 || !m)
		return ;
	if (isInInventory(m) == true)
		return ;
	this->_inventory[this->num_of_materia] = m;
	this->num_of_materia += 1;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= num_of_materia)
		return ;
	for (int i = idx ; i < num_of_materia ; i++)
	{
		if (i != num_of_materia - 1)
			this->_inventory[i] = this->_inventory[i + 1];
		else
			this->_inventory[i] = 0;
	}
	this->num_of_materia -= 1;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= num_of_materia)
		return ;
	this->_inventory[idx]->use(target);
}

bool Character::isInInventory(AMateria *m)
{
	for (int i = 0 ; i < num_of_materia ; i++)
	{
		if (_inventory[i] == m)
			return (true);
	}
	return (false);
}
