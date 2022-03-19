#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"
#include <string>
#include <iostream>

class Squad : public ISquad
{
private:
	int				num_of_units;
	ISpaceMarine	**units;
	bool			isInUnits(ISpaceMarine *unit);

public:
	Squad();
	Squad(Squad const & src);
	virtual ~Squad();
	Squad& operator=(Squad const & src);
	virtual int				getCount() const;
	virtual ISpaceMarine*	getUnit(int) const;
	virtual int				push(ISpaceMarine *);
};

#endif
