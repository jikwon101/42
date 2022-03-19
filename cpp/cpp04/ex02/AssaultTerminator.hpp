#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"
#include <iostream>
#include <string>

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(AssaultTerminator const  & src);
	virtual ~AssaultTerminator();
	AssaultTerminator& operator=(AssaultTerminator const & src);
	virtual ISpaceMarine*	clone() const;
	virtual void			battleCry() const;
	virtual void			rangedAttack() const;
	virtual void			meleeAttack() const;
};
#endif
