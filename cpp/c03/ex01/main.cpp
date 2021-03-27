#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "\033[1m\033[0m";
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Create Traps                  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........Create FragTrap" << std::endl;
	FragTrap *f = new FragTrap("FRAG");
	std::cout << "..........Create ScavTrap" << std::endl;
	ScavTrap *s = new ScavTrap("SCAV");
	std::cout << std::endl ;
	
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Scav TakeDamage / BeRepaired  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........TakeDamage : 45 (damage_reduction)" << std::endl;
	s->takeDamage(45);
	std::cout << "..........TakeDamage : 300 (.)" << std::endl;
	s->takeDamage(300);
	std::cout << "..........TakeDamage : 100 (min_hp)" << std::endl;
	s->takeDamage(100);
	std::cout << "..........BeRepaired : 100 (.)" << std::endl;
	s->beRepaired(100);
	std::cout << "..........BeRepaired : 300 (max_hp)" << std::endl;
	s->beRepaired(300);
	std::cout << std::endl ;
	
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Frag TakeDamage / BeRepaired  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........TakeDamage : 45 (damage_reduction)" << std::endl;
	f->takeDamage(45);
	std::cout << "..........TakeDamage : 300 (.)" << std::endl;
	f->takeDamage(300);
	std::cout << "..........TakeDamage : 100 (min_hp)" << std::endl;
	f->takeDamage(100);
	std::cout << "..........BeRepaired : 100 (.)" << std::endl;
	f->beRepaired(100);
	std::cout << "..........BeRepaired : 300 (max_hp)" << std::endl;
	f->beRepaired(300);
	std::cout << std::endl ;

	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Scav Attack (melee & ranged)  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	
	std::cout << "..........rangeAttack\n";
	s->rangeAttack("robot");
	std::cout << "..........meleeAttack\n";
	s->meleeAttack("robot");
	std::cout << std::endl ;
	
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Frag Attack (melee & ranged)  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	
	std::cout << "..........rangeAttack\n";
	f->rangeAttack("robot");
	std::cout << "..........meleeAttack\n";
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
	std::cout << "| Free                          |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	std::cout << "..........Free FragTrap" <<std::endl;
	delete f;
	std::cout << "..........Free ScavTrap" <<std::endl;
	delete s;
	std::cout << std::endl;
}

