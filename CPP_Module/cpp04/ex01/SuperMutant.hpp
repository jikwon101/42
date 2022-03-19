#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant(void);
	virtual ~SuperMutant(void);
	SuperMutant(SuperMutant const & src);
	SuperMutant&		operator=(SuperMutant const &src);
	virtual void 		takeDamage(int amount);
};
#endif
