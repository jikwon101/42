#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string name;
	int type;

public:
	Zombie(std::string name, int type);
	void announce(void);
};

#endif
