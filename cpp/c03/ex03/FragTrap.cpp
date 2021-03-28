#include "FragTrap.hpp"

FragTrap::~FragTrap()
{
	printMsg("Argh arghargh death gurgle gurglegurgle urgh... death\n");
}

FragTrap::FragTrap(const std::string src_name)
{
	printMsg("Recompiling my combat code!\n");
	hp = 100;
	max_hp = 100;
	ep = 100;
	max_ep = 100;
	level = 1;
	name = src_name;
	melee_attack_damage = 30;
	ranged_attack_damage = 20;
	armor_damage_reduction = 5;
}

FragTrap::FragTrap(const FragTrap& src)
{
	printMsg("Recompiling my combat code!\n");
	this->hp = src.hp;
	this->max_hp = src.max_hp;
	this->ep = src.ep;
	this->max_ep = src.max_ep;
	this->level = src.level;
	this->name = src.name;
	this->melee_attack_damage = src.melee_attack_damage;
	this->ranged_attack_damage = src.ranged_attack_damage;
	this->armor_damage_reduction = src.armor_damage_reduction;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	printMsg("Recompiling my combat code!\n");
	if (this != &src)
	{
		this->hp = src.hp;
		this->max_hp = src.max_hp;
		this->ep = src.ep;
		this->max_ep = src.max_ep;
		this->level = src.level;
		this->name = src.name;
		this->melee_attack_damage = src.melee_attack_damage;
		this->ranged_attack_damage = src.ranged_attack_damage;
		this->armor_damage_reduction = src.armor_damage_reduction;
	}
	return (*this);
}

void	FragTrap::rangeAttack(std::string const& target)
{	
	printMsg("Pop pop!\n");
	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg(" at range, causing ");
	printInt(ranged_attack_damage);
	printMsg(" points of damage\n");
}

void	FragTrap::meleeAttack(std::string const& target)
{	
	printMsg("Take that!\n");
	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg(" in melee, causing ");
	printInt(melee_attack_damage);
	printMsg(" points of damage\n");
}

typedef void (FragTrap::*ATTACK)(std::string const &target);

void	FragTrap::vaulthunter_dot_exe(std::string const& target)
{
	int num;
	ATTACK attack[] = {&FragTrap::mechromagicianAttack, &FragTrap::minionTrapAttack, &FragTrap::meatUnicycleAttack, &FragTrap::blightBotAttack, &FragTrap::funzerkerAttack};
	
	if (ep < 25)
	{
		printMsg("[SYSTEM] Out of energy.\n");
		return ;
	}
	ep -= 25;
	num = (unsigned int)time(NULL) * rand();
	srand(num);
	(this->*attack[rand() % 5])(target);
}

void	FragTrap::mechromagicianAttack(std::string const& target)
{
	printMsg("I have two robot arms!\n");
	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg("\n");
}

void	FragTrap::minionTrapAttack(std::string const& target)
{
	printMsg("Mini-trap on the field!\n");	
	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg("\n");
}

void	FragTrap::meatUnicycleAttack(std::string const& target)
{
	printMsg("Oh god I can't stop!\n");
	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg("\n");
}

void	FragTrap::blightBotAttack(std::string const& target)
{
	printMsg("I AM ON FIRE!! OH GOD, PUT ME OUT!!!\n");
	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg("\n");
}

void	FragTrap::funzerkerAttack(std::string const& target)
{
	printMsg("Tell me i'm the prettiest!!\n");
	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg("\n");
}

void FragTrap::printMsg(std::string msg)
{
	std::cout << "\033[35m" << msg << "\033[1m\033[0m";
}

void FragTrap::printInt(int num)
{
	std::cout << "\033[35m" << num << "\033[1m\033[0m";	
}

