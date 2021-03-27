#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

# define CL "\033[1m\033[36m"
# define RS "\033[0m"

//# define TEST

int main()
{
	#ifndef TEST
	ISpaceMarine *bob = new TacticalMarine;
	ISpaceMarine *jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	
	for (int i = 0; i < vlc->getCount(); i++)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
	#endif

	#ifdef TEST
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|                          Add Test                     |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	ISpaceMarine *bob = new TacticalMarine;
	ISpaceMarine *jim = new AssaultTerminator;
	ISpaceMarine *cho = new AssaultTerminator;
	ISquad *vlc = new Squad;

	std::cout << CL<< "[1]___getCount / push_________\n"<< RS ;
	std::cout << "There are " << vlc->getCount() << " in squad vlc\n";
	std::cout << vlc->push(bob) << std::endl;
	std::cout << vlc->push(jim) << std::endl;
	std::cout << vlc->push(cho) << std::endl;
	std::cout << vlc->push(cho) << std::endl;
	std::cout << "There are " << vlc->getCount() << " in squad vlc\n";

	std::cout << CL<< "[2]___getUnit_________________\n"<< RS ;
	std::cout << "There are " << vlc->getCount() << " in squad vlc\n";
	if (vlc->getUnit(vlc->getCount() + 1) == nullptr)
		std::cout << "Returned nullptr\n";
	if (vlc->getUnit(-1) == nullptr)
		std::cout << "Returned nullptr\n";

	std::cout << CL<< "[3]___Assignment operator_____\n"<< RS ;
	Squad *old = new Squad;
	Squad *new_1 = new Squad;
	Squad *new_2 = new Squad;	
	ISpaceMarine *t1 = new TacticalMarine;
	ISpaceMarine *t2 = new TacticalMarine;
	ISpaceMarine *t3 = new AssaultTerminator;
	std::cout << CL << "________\n" << RS;
	old->push(t1);
	old->push(t2);
	old->push(t3);
	std::cout << "There are " << old->getCount() << " in squad old\n";
	std::cout << "There are " << new_1->getCount() << " in squad new_1\n";
	std::cout << "There are " << new_2->getCount() << " in squad new_2\n";
	std::cout << CL << "________\n" << RS;
	*new_1 = *old;
	*new_2 = *old;
	std::cout << CL << "________\n" << RS;
	std::cout << "There are " << new_1->getCount() << " in squad new_1\n";
	std::cout << "There are " << new_2->getCount() << " in squad new_2\n";
	std::cout << CL << "________\n" << RS;
	delete new_1;
	delete new_2;

	std::cout << CL<< "[4]___Clone___________________\n"<< RS ;
	ISpaceMarine *marine = new TacticalMarine;
	ISpaceMarine *clone = marine->clone();
	std::cout << "marine : " << marine << std::endl;
	std::cout << "clone  : " << clone << std::endl;
	std::cout << CL << "________\n" << RS;
	delete marine;
	delete clone;

	std::cout << CL<< "[5]___Free____________________\n"<< RS ;
	delete vlc;
	#endif
	return 0;
}
