#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"
#include <iostream>
#include <string>

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine();
	TacticalMarine(TacticalMarine const  & src);
	virtual ~TacticalMarine();
	TacticalMarine& operator=(TacticalMarine const & src);
	virtual ISpaceMarine*	clone() const;
	virtual void			battleCry() const;
	virtual void			rangedAttack() const;
	virtual void			meleeAttack() const;
};
#endif
