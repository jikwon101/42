#include "ZombieHorde.hpp"

int main()
{
	std::cout << "First horde......" << std::endl ;
	ZombieHorde horde1(5);

	horde1.announce();
	
	std::cout << std::endl << "Second horde......" << std::endl ;
	ZombieHorde horde2(3);

	horde2.setType(1);
	horde2.announce();

	std::cout << std::endl << "Third horde......" << std::endl ;
	ZombieHorde horde3(5);

	horde3.setType(2);
	horde3.announce();

	std::cout << std::endl << "Fourth horde......" << std::endl ;
	ZombieHorde horde4(-3);
	horde4.announce();
}
