#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <random>

class ZombieEvent
{
private:
public:
	void setZombieType(Zombie *zombie);
	Zombie* newZombie(std::string name);
};
#endif
