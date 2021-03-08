#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <random>

class ZombieHorde
{
private:
	Zombie *horde;
	int size;
	int type;
	std::string RandomName(void);

public:
	~ZombieHorde();
	ZombieHorde(int n);
	void setType(int type);
	void announce(void);
};
#endif
