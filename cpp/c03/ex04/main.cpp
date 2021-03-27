#include "SuperTrap.hpp"

int main()
{
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
	std::cout << "..........Create SuperTrap" << std::endl;
	SuperTrap *sp = new SuperTrap("SUPER");
	std::cout << std::endl ;
	
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Super TakeDamage / BeRepaired |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........TakeDamage : 45 (damage_reduction)" << std::endl;
	sp->takeDamage(45);
	std::cout << "..........TakeDamage : 300 (.)" << std::endl;
	sp->takeDamage(300);
	std::cout << "..........TakeDamage : 100 (min_hp)" << std::endl;
	sp->takeDamage(100);
	std::cout << "..........BeRepaired : 100 (.)" << std::endl;
	sp->beRepaired(100);
	std::cout << "..........BeRepaired : 300 (max_hp)" << std::endl;
	sp->beRepaired(300);
	std::cout << std::endl ;

	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Super Attack (melee & ranged)  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........rangeAttack (Clap)\n";
	sp->ClapTrap::rangeAttack("robot");
	std::cout << "..........meleeAttack (Clap)\n";
	sp->ClapTrap::meleeAttack("robot");

	std::cout << "..........rangeAttack (Frag)\n";
	sp->FragTrap::rangeAttack("robot");
	std::cout << "..........meleeAttack (Frag)\n";
	sp->FragTrap::meleeAttack("robot");
	
	std::cout << "..........rangeAttack (Ninja)\n";
	sp->NinjaTrap::rangeAttack("robot");
	std::cout << "..........meleeAttack (Ninja)\n";
	sp->NinjaTrap::meleeAttack("robot");
	
	std::cout << "..........rangeAttack (Virtual)\n";
	sp->rangeAttack("robot");
	std::cout << "..........meleeAttack (Virtual)\n";
	sp->meleeAttack("robot");

	std::cout << std::endl ;
	
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Vaulthunter_dot_exe           |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........First\n";
	sp->vaulthunter_dot_exe("robot");
	std::cout << "..........Second\n";
	sp->vaulthunter_dot_exe("robot");
	std::cout << std::endl;
	

	std::cout << " -------------------------------" << std::endl;
	std::cout << "| ninjaShoebox                  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........type claptrap : 대상이 대상의 meleeAttack\n";
	sp->ninjaShoebox(*c);
	std::cout << "..........type FragTrap : 10 * 2times\n";
	sp->ninjaShoebox(*f);
	std::cout << "..........type Scavtrap : 대상의 meleeAttackDamage * 2\n";
	sp->ninjaShoebox(*s);
	std::cout << "..........type Ninjatrap : rangeAttack & 0.2반사\n";
	sp->ninjaShoebox(*n);

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
	std::cout << "..........Free SuperTrap" <<std::endl;
	delete sp;

	std::cout << std::endl;
}

