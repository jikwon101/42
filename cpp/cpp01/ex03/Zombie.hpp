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
	Zombie();
	void setType(int type);
	void setName(std::string name);
	void announce(void);
};

#endif
