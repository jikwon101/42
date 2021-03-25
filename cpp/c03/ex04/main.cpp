#include "SuperTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Create Traps                  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..............Create SuperTrap\n";
	SuperTrap *sp = new SuperTrap("SUPER");
	std::cout << "..............Create ClapTrap\n";
	ClapTrap *c = new ClapTrap("CLAP");
	std::cout << "..............Create FragTrap\n";
	FragTrap *f = new FragTrap("FRAG");
	std::cout << "..............Create ScavTrap\n";
	ScavTrap *s = new ScavTrap("SCAV");
	std::cout << "..............Create NinjaTrap\n";
	NinjaTrap *n = new NinjaTrap("NINJA");

	std::cout << std::endl ;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Color info                    |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	sp->printMsg("SUPERTRAP\n");
	f->printMsg("FRAG_TRAP\n");
	s->printMsg("SCAV_TRAP\n");
	c->printMsg("CLAP_TRAP\n");
	n->printMsg("NINJATRAP\n");

	std::cout << std::endl ;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Basic attack                  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;

	sp->rangeAttack("t1");
	sp->FragTrap::rangeAttack("t1");
	sp->NinjaTrap::rangeAttack("t1");
	sp->meleeAttack("t1");

	std::cout << std::endl ;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| vaulthunter_dot_exe           |" << std::endl;
	std::cout << " -------------------------------" << std::endl;

	std::cout << "..........First try" << std::endl;
	sp->vaulthunter_dot_exe("t1");
	std::cout << "..........Second try" << std::endl;
	sp->vaulthunter_dot_exe("t1");
	std::cout << "..........Third try" << std::endl;
	sp->vaulthunter_dot_exe("t1");

	std::cout << std::endl ;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| ninjashoebox                  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;

	std::cout << "..........Attack FragTrap" << std::endl;
	sp->ninjaShoebox(*f);
	std::cout << "..........Attack ClapTrap" << std::endl;
	sp->ninjaShoebox(*c);
	std::cout << "..........Attack ScavTrap" << std::endl;
	sp->ninjaShoebox(*s);
	std::cout << "..........Attack NinjaTrap" << std::endl;
	sp->ninjaShoebox(*n);
	
	std::cout << std::endl ;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| free                          |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	
	std::cout << "..............Delete SuperTrap\n";
	delete sp;
	std::cout << "..............Create FragTrap\n";
	delete f;
	std::cout << "..............Create ClapTrap\n";
	delete c;
	std::cout << "..............Create ScavTrap\n";
	delete s;
	std::cout << "..............Create NinjaTrap\n";
	delete n;

}

