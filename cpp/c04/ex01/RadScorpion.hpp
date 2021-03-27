#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
	RadScorpion(void);
	virtual ~RadScorpion(void);
	RadScorpion(RadScorpion const & src);
	RadScorpion&		operator=(RadScorpion const &src);
};
#endif
