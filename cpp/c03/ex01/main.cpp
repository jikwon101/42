#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap *t1 = new ScavTrap("01");
	FragTrap *t2 = new FragTrap("02");
	
	t2->beRepaired(30);
	t1->challengeNewcomer();
	delete t1;
	delete t2;
}
