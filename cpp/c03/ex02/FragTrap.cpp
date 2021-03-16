#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	printMsg("Recompiling my combat code!\n");
	hp = 100;
	max_hp = 100;
	ep = 100;
	max_ep = 100;
	level = 1;
	name = "";
	melee_attack_damage = 30;
	ranged_attack_damage = 20;
	armor_damage_reduction = 5;
}

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
	printMsg("Look out everybody! Things are about to get awesome!\n");
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

void	FragTrap::vaulthunter_dot_exe(std::string const& target)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::string list[] = {
	"I have two robot arms!",
	"Mini-trap on the field!",	
	"I AM ON FIRE!! OH GOD, PUT ME OUT!!!",
	"Tell me i'm the prettiest!!",
	"Oh god I can't stop!",
	"I am rubber, and you are so dead!",
	"Love bullets!"
	};
	std::uniform_int_distribution<int> dis(0, 6);
	
	printMsg(list[dis(gen)]);
	printMsg("\n");
	printMsg(name);
	printMsg(" attacked ");
	printMsg(target);
	printMsg("\n");
}

void FragTrap::printMsg(std::string msg)
{
	std::cout << "\033[1m\033[35m" << msg << "\033[0m";
}

void FragTrap::printInt(int num)
{
	std::cout << "\033[1m\033[35m" << num << "\033[0m";
}


