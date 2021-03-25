#include "NinjaTrap.hpp"

int main()
{
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Create Traps                  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	
	NinjaTrap *n = new NinjaTrap("Ninja1");
	std::cout << ".........." << n->getName() << "(NinjaTrap) is created" << std::endl;
	FragTrap *f = new FragTrap("Frag1");
	std::cout << ".........." << f->getName() << "(FragTrap) is created" << std::endl;
	ScavTrap *s = new ScavTrap("Scav1");
	std::cout << ".........." << s->getName() << "(ScavTrap) is created" << std::endl;
	NinjaTrap *n2 = new NinjaTrap("Ninja2");
	std::cout << ".........." << n2->getName() << "(NinjaTrap) is created" << std::endl;
	ClapTrap *c = new ClapTrap("Clap1");
	std::cout << ".........." << c->getName() << "(ClapTrap) is created" << std::endl;

	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Basic attack                  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;

	std::cout << "..........NinjaTrap is going to attack t1" << std::endl;
	n->rangeAttack("t1");
	std::cout << "..........NinjaTrap is going to attack t2" << std::endl;
	n->meleeAttack("t2");


	std::cout << " -------------------------------" << std::endl;
	std::cout << "| takedamage & repair           |" << std::endl;
	std::cout << " -------------------------------" << std::endl;

	std::cout << "..........NinjaTrap is getiing attack 50 damage, 3times" << std::endl;
	n->takeDamage(50);
	n->takeDamage(50);
	n->takeDamage(50);

	std::cout << "..........NinjaTrap is being repired 50 points, 3times" << std::endl;
	n->beRepaired(50);
	n->beRepaired(50);
	n->beRepaired(50);

	std::cout << " -------------------------------" << std::endl;
	std::cout << "| ninjashoebox                  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;

	std::cout << "..........NinjaShoebox(self)" << std::endl;
	n->ninjaShoebox(*n);
	std::cout << "..........NinjaShoebox(FragTrap)" << std::endl;
	n->ninjaShoebox(*f);
	std::cout << "..........NinjaShoebox(ScavTrap)" << std::endl;
	n->ninjaShoebox(*s);
	std::cout << "..........NinjaShoebox(ClapTrap)" << std::endl;
	n->ninjaShoebox(*c);
	std::cout << "..........NinjaShoebox(NinjaTrap)" << std::endl;
	n->ninjaShoebox(*n2);

	
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| free                          |" << std::endl;
	std::cout << " -------------------------------" << std::endl;

	delete c;
	delete n2;
	delete f;
	delete s;
	delete n;
}
