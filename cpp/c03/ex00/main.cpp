#include "FragTrap.hpp"

int main()
{
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| Create Traps                  |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	FragTrap *f = new FragTrap("FRAG");
	std::cout << std::endl ;
	
	std::cout << " -------------------------------" << std::endl;
	std::cout << "| TakeDamage / BeRepaired       |" << std::endl;
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
	std::cout << "| Attack (melee & ranged)       |" << std::endl;
	std::cout << " -------------------------------" << std::endl;
	
	std::cout << "..........rangeAttack\n";
	f->rangeAttack("robot");
	std::cout << "..........meleeAttack\n";
	f->meleeAttack("robot");
	std::cout << std::endl ;
	
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
	delete f;
	std::cout << std::endl;
}

