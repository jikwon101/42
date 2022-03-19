#include "Character.hpp"
#include "MateriaSource.hpp"

#define CL "\033[1m\033[36m"
#define RS "\033[0m"

//#define TEST

int main()
{
	#ifndef TEST
	IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	#endif

	#ifdef TEST
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|                          Add Test                     |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	IMateriaSource* src = new MateriaSource();
	Ice *m1 = new Ice;
	Ice *m2 = new Ice;
	Ice *m3 = new Ice;
	Ice *m4 = new Ice;
	Ice *m5 = new Ice;

	std::cout << CL << "[1]__Learn Materia___________\n" << RS;
	std::cout << "MateriaSource leared " << src->getBuffersize()  << " materias\n";
    src->learnMateria(m1);
    src->learnMateria(m2);
    src->learnMateria(m3);
    src->learnMateria(m4);
    src->learnMateria(m5);
	std::cout << "MateriaSource leared " << src->getBuffersize()  << " materias\n";
	
	std::cout << CL << "[2]___Create Materia_________\n" << RS;
	AMateria *n_ice = src->createMateria("ice");
	AMateria *n_cure = src->createMateria("cure");
	std::cout << "n_ice : " << n_ice << std::endl;
	std::cout << "n_cure : " << n_cure << std::endl;
	delete src;
	delete n_ice;
	delete m1;
	delete m2;
	delete m3;
	delete m4;
	delete m5;
	
	std::cout << CL << "[3]____Equip_________________\n" << RS;
	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria *t1 = src->createMateria("ice");
	AMateria *t2 = src->createMateria("cure");
	AMateria *t3 = src->createMateria("ice");
	AMateria *t4 = src->createMateria("cure");
	AMateria *t5 = src->createMateria("ice");

	std::cout << "Character me has " << me->getNumOfMateria() << " materias\n";
	me->equip(t1);
	std::cout << "Character me has " << me->getNumOfMateria() << " materias\n";
	me->equip(t1);
	std::cout << "Character me has " << me->getNumOfMateria() << " materias\n";
	me->equip(t2);
	me->equip(t3);
	me->equip(t4);
	me->equip(t5);
	me->equip(0);
	std::cout << "Character me has " << me->getNumOfMateria() << " materias\n";

	std::cout << CL << "[4]____Unequip_________________\n" << RS;
	me->unequip(5);
	me->unequip(-1);
	me->unequip(3);
	me->unequip(2);
	std::cout << "Character me has " << me->getNumOfMateria() << " materias\n";
	

	std::cout << CL << "[5]____Use______________________\n" << RS;
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(4, *bob);


	std::cout << CL << "[6]____Free______________________\n" << RS;
	delete src;
	delete me;
	delete bob;
	delete t3;
	delete t4;
	delete t5;
	std::cout << CL << "---------------------------------------------------------\n" << RS;

	#endif
	return 0;
}
