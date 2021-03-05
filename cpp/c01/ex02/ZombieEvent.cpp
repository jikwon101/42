#include "ZombieEvent.hpp"

//Store a type in the object
void ZombieEvent::setZombieType(Zombie *zombie)
{
	std::random_device rd;

	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 5);
	zombie->type = dis(gen);
}

//Create a Zombie with the chosen type, name it, and return it.
Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie *new_zombie;

	new_zombie = new Zombie(name);
	setZombieType(new_zombie);
	new_zombie->announce();
	return (new_zombie);
}
