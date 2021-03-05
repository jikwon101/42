//Store a type in the object
void setZombieType(Zombie &zombie)
{
	std::cout << "[1] Supernatural Zombies." << std::endl;
	std::cout << "    They are created in a supernatural way." << std::endl;
	std::cout << "[2] Magic Zombies." << std::endl;
	std::cout << "    They comes as a result of the powers possessed by witches." << std::endl;
}

//Create a Zombie with the chosen type, name it, and return it.
Zombie* newZombie(std::string name)
{
	Zombie *new_zombie;

	new_zomebie = new Zombie;
	setZombieType(new_zombie);
	new_zombie.announce();
	return (new_zombie);
}
