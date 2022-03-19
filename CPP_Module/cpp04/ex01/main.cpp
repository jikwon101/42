#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

# define CL "\033[1m\033[36m"
# define RS "\033[0m"

//# define TEST

int main()
{
	#ifndef TEST
	Character* me = new Character("me");

	std::cout << *me;
	
	Enemy* b = new RadScorpion();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);

	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	#endif

	#ifdef TEST
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|                          Add Test                     |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL<< "[1]___Max AP________________\n"<< RS ;
	Character *joe = new Character("Joe");
	Character *cathy = new Character("Cathy");
	AWeapon* wPr = new PlasmaRifle();
	AWeapon* wPf = new PowerFist();
	Enemy* rad = new RadScorpion();
	Enemy* rad2 = new RadScorpion();
	Enemy* sup = new SuperMutant();
	
	std::cout << *joe;
	joe->recoverAP();
	std::cout << *joe;
	joe->equip(wPr);
	std::cout << *joe;
	joe->attack(rad);
	std::cout << *joe;
	joe->recoverAP();
	std::cout << *joe;
	
	std::cout << CL<< "[2]___Assignment operation___\n"<< RS ;
	joe->attack(rad);
	joe->attack(rad);
	std::cout << *joe << *cathy;
	*cathy = *joe;
	std::cout << *cathy;

	std::cout << CL<< "[3]___AP & Damage_____________\n"<< RS ;
	joe->recoverAP();
	std::cout << *joe;
	std::cout << "rad2 HP : " << rad2->getHP() << std::endl;
	joe->equip(wPr);
	joe->attack(rad2);
	std::cout << "rad2 HP : " << rad2->getHP() << std::endl;
	
	std::cout << CL << "_______\n" << RS;
	joe->recoverAP();
	std::cout << *joe;
	std::cout << "sup HP : " << sup->getHP() << std::endl;
	joe->equip(wPr);
	joe->attack(sup);
	std::cout << *joe;
	std::cout << "sup HP : " << sup->getHP() << std::endl;
	
	std::cout << CL << "_______\n" << RS;
	joe->recoverAP();
	std::cout << *joe;
	std::cout << "sup HP : " << sup->getHP() << std::endl;
	joe->equip(wPf);
	joe->attack(sup);
	std::cout << *joe;
	std::cout << "sup HP : " << sup->getHP() << std::endl;


	std::cout << CL<< "[4]___Free____________________\n"<< RS ;
	delete joe;
	delete cathy;
	delete wPr;
	delete wPf;
	delete rad;
	delete sup;
	delete rad2;

	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	#endif
	return 0;
}
