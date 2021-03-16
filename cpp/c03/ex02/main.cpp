#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap *f = new FragTrap("FRAG-TP");
	f->takeDamage(20);
	f->rangeAttack("t1");
	f->beRepaired(50);
	f->vaulthunter_dot_exe("t1");
	delete f;
	
	std::cout << "-----------------" << std::endl;

	ScavTrap *s = new ScavTrap("SCAV-TP");
	s->takeDamage(40);
	s->rangeAttack("t2");
	s->beRepaired(20);
	s->challengeNewcomer();
	delete s;
	return (0);
}
