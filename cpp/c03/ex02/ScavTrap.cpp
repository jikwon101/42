#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	printMsg("Halt, citizen! I've been chosen to stand out here to guard the main gate.\n");
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

ScavTrap::~ScavTrap()
{
	printMsg("I'm too pretty to die!\n");
}

ScavTrap::ScavTrap(const std::string src_name)
{
	printMsg("Halt, citizen! I've been chosen to stand out here to guard the main gate.\n");
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
	std::random_device rd;
	std::mt19937 gen(rd());
	std::string list[] = {
	"Find treasure map!",
	"Survive scavenger attacks: 0/3",
	"Don't hurt orphan rathyds!",
	"Kill adult threshere: 0/6",
	"Talk to Seymour.",
	"Follow Dr.Minte.",
	"Open Lab19 vault."
	};
	std::uniform_int_distribution<int> dis(0, 6);
	printMsg(list[dis(gen)]);
	printMsg(".");
	printMsg(" Then, if you live, return to me here, where I am standing\n");}

void ScavTrap::printMsg(std::string msg)
{
	std::cout << "\033[1m\033[36m" << msg << "\033[0m";
}

void ScavTrap::printInt(int num)
{
	std::cout << "\033[1m\033[36m" << num << "\033[0m";
}
