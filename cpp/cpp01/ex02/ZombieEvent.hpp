#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <random>

class ZombieEvent
{
private:
	int	type;
	std::string RandomName(void);
	Zombie* newZombie(std::string name);

public:
	void setZombieType(int type);
	Zombie* randomChump(void);
};
#endif
