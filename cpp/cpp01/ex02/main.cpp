#include "ZombieEvent.hpp"

int main()
{
	Zombie *new_zombie;
	ZombieEvent event;

	std::cout << "Create type 1 zombie" << std::endl;
	event.setZombieType(1);
	new_zombie = event.randomChump();
	new_zombie->announce();
	delete new_zombie;
	std::cout << "Create type 2 zombie" << std::endl;
	event.setZombieType(2);
	new_zombie = event.randomChump();
	new_zombie->announce();
	delete new_zombie;
}
