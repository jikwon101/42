#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Fisherman.hpp"

# define CL "\033[1m\033[36m"
# define RS "\033[0m"

//# define TEST

int main()
{
	#ifndef TEST
	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);
	#endif

	#ifdef TEST
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|                          Add Test                     |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;

	Sorcerer *jone = new Sorcerer("Jone", "the Magnificent");
	Sorcerer *tim = new Sorcerer("Tim", "the Magnificent");
	Victim *andrew = new Victim("Andrew");
	Victim *cathy = new Victim("Cathy");
	Peon *zen = new Peon("Zen");
	Peon *mattew = new Peon("Mattew");

	std::cout << CL << "[1]___New derived class_____\n" << RS;
	Fisherman *skinner = new Fisherman("Skinner");
	std::cout << *skinner;
	jone->polymorph(*skinner);

	std::cout << CL << "[2]___Assignment operator___\n" << RS;
	std::cout << *jone << *tim;
	*tim = *jone;
	std::cout << *tim ;

	std::cout << *andrew << *cathy;
	*cathy = *andrew;
	std::cout << *cathy;

	std::cout << *zen << *mattew;
	*mattew = *zen;
	std::cout << *zen;
	
	std::cout << CL << "[3]___Free____________________\n" << RS;
	delete jone;
	delete tim;
	delete andrew;
	delete cathy;
	delete zen;
	delete mattew;
	delete skinner;

	std::cout << CL << "---------------------------------------------------------\n" << RS;
	#endif
	return (0);
}
