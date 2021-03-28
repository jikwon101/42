#include "ScavTrap.hpp"

ScavTrap::~ScavTrap()
{
	printMsg("I'm too pretty to die!\n");
}

ScavTrap::ScavTrap(const std::string src_name)
{
	printMsg("I'm not to let ANYONE in through here!\n");
	hp = 100;
	max_hp = 100;
	ep = 50;
	max_ep = 50;
	level = 1;
	name = src_name;
	melee_attack_damage = 20;
	ranged_attack_damage = 15;
	armor_damage_reduction = 3;
}

ScavTrap::ScavTrap(const ScavTrap& src)
{
	printMsg("I'm not to let ANYONE in through here!\n");
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

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	printMsg("I'm not to let ANYONE in through here!\n");
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

void	ScavTrap::rangeAttack(std::string const& target)
{	
	printMsg("WOW! I hit 'em!\n");
	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg(" at range, causing ");
	printInt(ranged_attack_damage);
	printMsg(" points of damage\n");
}

void	ScavTrap::meleeAttack(std::string const& target)
{	
	printMsg("Heyyah!\n");
	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg(" in melee, causing ");
	printInt(melee_attack_damage);
	printMsg(" points of damage\n");
}

void	ScavTrap::challengeNewcomer(void)
{
	std::string list[] = {
	"Find treasure map!",
	"Survive scavenger attacks: 0/3",
	"Don't hurt orphan rathyds!",
	"Kill adult threshere: 0/6",
	"Talk to Seymour.",
	"Follow Dr.Minte.",
	"Open Lab19 vault."
	};

	printMsg(list[rand() % 7]);
	printMsg("\n");
	printMsg("Then, if you live, return to me here, where I am standing\n");}

void ScavTrap::printMsg(std::string msg)
{
	std::cout << "\033[36m" << msg << "\033[1m\033[0m";
}

void ScavTrap::printInt(int num)
{
	std::cout << "\033[36m" << num << "\033[1m\033[0m";
}

