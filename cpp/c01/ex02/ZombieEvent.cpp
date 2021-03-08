#include "ZombieEvent.hpp"

//Store a type in the object
void ZombieEvent::setZombieType(int type)
{
	this->type = type;
}

//Create a Zombie with the chosen type, name it, and return it.
Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie *new_zombie;

	new_zombie = new Zombie(name, type);
	return (new_zombie);
}

//Create a name.
std::string ZombieEvent::RandomName(void)
{
	int namelen;
	std::string name;
	static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	namelen = 8;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 61);
	for (int i = 0 ; i < namelen ; i++)
		name += (alphanum[dis(gen)]);
	return (name);
};

//Create a 'Zombie' with a ramdom name and make if 'announce' it.
void ZombieEvent::randomChump(void)
{
	std::string name;
	Zombie *zombie;

	name = RandomName();
	zombie = newZombie(name);
	zombie->announce();
	delete zombie;
}


