#include "ZombieEvent.hpp"

//Create a 'Zombie' with a ramdom name and make if 'announce' it.
void randomChump(void)
{
	Zombie *zombie;
	ZombieEvent event;

	std::string name;
	static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 61);
	for (int i = 0 ; i < 8 ; i++)
		name += (alphanum[dis(gen)]);
	zombie = event.newZombie(name);
}

int main()
{
	randomChump();
}
