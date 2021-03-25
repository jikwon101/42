#include "SuperTrap.hpp"

SuperTrap::~SuperTrap()
{
	//printMsg("I'm too pretty to die!\n");
}

SuperTrap::SuperTrap(const std::string src_name)
{
	printMsg("Halt, citizen! I've been chosen to stand out here to guard the main gate.\n");
	hp = 100;
	max_hp = 100;
	ep = 120;
	max_ep = 120;
	level = 1;
	name = src_name;
	melee_attack_damage = 60;
	ranged_attack_damage = 20;
	armor_damage_reduction = 5;
}

SuperTrap::SuperTrap(const SuperTrap& src)
{
	//printMsg("I'm not to let ANYONE in through here!\n");
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

SuperTrap& SuperTrap::operator=(const SuperTrap& src)
{
	//printMsg("I'm not to let ANYONE in through here!\n");
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

void	SuperTrap::rangeAttack(std::string const& target)
{	
	//printMsg("WOW! I hit 'em!\n");
	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg(" at range, causing ");
	printInt(ranged_attack_damage);
	printMsg(" points of damage\n");
}

void	SuperTrap::meleeAttack(std::string const& target)
{	
	//printMsg("Heyyah!\n");
	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg(" in melee, causing ");
	printInt(melee_attack_damage);
	printMsg(" points of damage\n");
}

void SuperTrap::printMsg(std::string msg)
{
	std::cout << "\033[1m\033[34m" << msg << "\033[0m";
}

void SuperTrap::printInt(int num)
{
	std::cout << "\033[1m\033[34m" << num << "\033[0m";
}
