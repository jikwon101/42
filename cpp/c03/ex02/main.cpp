#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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
	std::cout << std::endl ;
	
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Scav TakeDamage / BeRepaired  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........TakeDamage : 70 (.)" << std::endl;
	s->takeDamage(70);
	std::cout << "..........BeRepaired : 50 (.)" << std::endl;
	s->beRepaired(50);
	std::cout << std::endl ;
	
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Frag TakeDamage / BeRepaired  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........TakeDamage : 70 (.)" << std::endl;
	f->takeDamage(70);
	std::cout << "..........BeRepaired : 50 (.)" << std::endl;
	f->beRepaired(50);
	std::cout << std::endl ;

	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Scav Attack (melee & ranged)  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........rangeAttack (clap)\n";
	s->ClapTrap::rangeAttack("robot");
	std::cout << "..........meleeAttack (clap)\n";
	s->ClapTrap::meleeAttack("robot");

	std::cout << "..........rangeAttack (virtual)\n";
	s->rangeAttack("robot");
	std::cout << "..........meleeAttack (virtual)\n";
	s->meleeAttack("robot");
	std::cout << std::endl ;
	
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Frag Attack (melee & ranged)  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........rangeAttack (clap)\n";
	f->ClapTrap::rangeAttack("robot");
	std::cout << "..........meleeAttack (clap)\n";
	f->ClapTrap::meleeAttack("robot");

	std::cout << "..........rangeAttack (virtual)\n";
	f->rangeAttack("robot");
	std::cout << "..........meleeAttack (virtual)\n";
	f->meleeAttack("robot");
	std::cout << std::endl ;

	std::cout << " -------------------------------" << std::endl;
	std::cout << "| challengeNewcomer             |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........First\n";
	s->challengeNewcomer();
	std::cout << "..........Second\n";
	s->challengeNewcomer();
	std::cout << std::endl;
	
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Vaulthunter_dot_exe           |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........First\n";
	f->vaulthunter_dot_exe("robot");
	std::cout << "..........Second\n";
	f->vaulthunter_dot_exe("robot");
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
	std::cout << std::endl;
}

