#include "NinjaTrap.hpp"

int main()
{
	srand((unsigned int)time(NULL));
	std::cout << "\033[1m\033[0m";
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Create Traps                  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........Create ClapTrap" << std::endl;
	ClapTrap *c = new ClapTrap("CLAP");
	std::cout << "..........Create FragTrap" << std::endl;
	FragTrap *f = new FragTrap("FRAG");
	std::cout << "..........Create ScavTrap" << std::endl;
	ScavTrap *s = new ScavTrap("SCAV");
	std::cout << "..........Create NinjaTrap1" << std::endl;
	NinjaTrap *n = new NinjaTrap("NINJA");
	std::cout << "..........Create NinjaTrap2" << std::endl;
	NinjaTrap *n2 = new NinjaTrap("Other_NINJA");
	std::cout << std::endl ;
	
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Ninja TakeDamage / BeRepaired |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........TakeDamage : 45 (damage_reduction)" << std::endl;
	n->takeDamage(45);
	std::cout << "..........TakeDamage : 300 (.)" << std::endl;
	n->takeDamage(300);
	std::cout << "..........TakeDamage : 100 (min_hp)" << std::endl;
	n->takeDamage(100);
	std::cout << "..........BeRepaired : 100 (.)" << std::endl;
	n->beRepaired(100);
	std::cout << "..........BeRepaired : 300 (max_hp)" << std::endl;
	n->beRepaired(300);
	std::cout << std::endl ;

	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Ninja Attack (melee & ranged) |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........rangeAttack\n";
	n->ClapTrap::rangeAttack("robot");
	std::cout << "..........meleeAttack\n";
	n->ClapTrap::meleeAttack("robot");

	std::cout << "..........rangeAttack (virtual)\n";
	n->rangeAttack("robot");
	std::cout << "..........meleeAttack (virtual)\n";
	n->meleeAttack("robot");
	std::cout << std::endl ;
	
	
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| ninjaShoebox                  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........type claptrap\n";
	n->ninjaShoebox(*c);
	std::cout << "..........type FragTrap\n";
	n->ninjaShoebox(*f);
	std::cout << "..........type Scavtrap\n";
	n->ninjaShoebox(*s);
	std::cout << "..........type Ninjatrap\n";
	n->ninjaShoebox(*n2);
	std::cout << "..........type self\n";
	n->ninjaShoebox(*n);


	std::cout << std::endl;
	

	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Free                          |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........Free ClapTrap" <<std::endl;
	delete c;
	std::cout << "..........Free FragTrap" <<std::endl;
	delete f;
	std::cout << "..........Free ScavTrap" <<std::endl;
	delete s;
	std::cout << "..........Free NinjaTrap" <<std::endl;
	delete n;
	std::cout << std::endl;
}

