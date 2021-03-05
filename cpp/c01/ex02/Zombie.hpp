#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
class Zombie
{
public:
	int type;
	std::string name;

	Zombie(std::string name);
	void announce(void);
};

#endif
