#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <random>

class ZombieHorde
{
private:
	int	type;
	std::string RandomName(void);
	Zombie* newZombie(std::string name);

public:
	void setZombieType(int type);
};
#endif
