#include "FragTrap.hpp"

int main()
{
	FragTrap t1("01");

	t1.rangeAttack("t2");
	t1.meleeAttack("t3");
	t1.takeDamage(30);
	t1.takeDamage(100);
	t1.takeDamage(10);
}
