#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	printMsg("Let's get this party started!\n");
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

ClapTrap::~ClapTrap()
{
	printMsg("No, nononono NO!\n");
}

ClapTrap::ClapTrap(const std::string src_name)
{
	printMsg("Let's get this party started!\n");
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

ClapTrap::ClapTrap(const ClapTrap& src)
{
	printMsg("Let's get this party started!\n");
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

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
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

void	ClapTrap::rangeAttack(std::string const& target)
{
	printMsg("Present for you!\n");	
	
	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg(" at range, causing ");
	printInt(ranged_attack_damage);
	printMsg(" points of damage\n");
}

void	ClapTrap::meleeAttack(std::string const& target)
{
	printMsg("Bop!\n");	

	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg(" in melee, causing ");
	printInt(melee_attack_damage);
	printMsg(" points of damage\n");
}

void	ClapTrap::takeDamage(unsigned int amount)
{	
	int actual_damage;

	actual_damage = amount - armor_damage_reduction;
	if (this->hp <= 0)
	{
		printMsg("[SYSTEM] Already been crippled\n");
		return ;
	}
	this->hp -= actual_damage;
	if (this->hp < 0)
	{
		actual_damage += this->hp;
		this->hp = 0;
	}
	printMsg(name);
	printMsg(" got attacked, lost ");
	printInt(actual_damage);
	printMsg(" points\n");
	printMsg("HP left ");
	printInt(hp);
	printMsg("\n");
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	int actual_repaired;

	actual_repaired = amount;
	printMsg("Healsies!\n");
	if (hp >= max_hp)
	{
		printMsg("[SYSTEM] Full.\n");
		return ;
	}
	hp += actual_repaired;
	if (hp > max_hp)
	{
		actual_repaired += (max_hp - hp);
		hp = max_hp;
	}
	printMsg(name);
	printMsg(" has repared, restored ");
	printInt(actual_repaired);
	printMsg(" points\n");
	printMsg("HP left ");
	printInt(hp);
	printMsg("\n");
}

void ClapTrap::printMsg(std::string msg)
{
	std::cout << "\033[1m\033[33m" << msg << "\033[0m";
}

void ClapTrap::printInt(int num)
{
	std::cout << "\033[1m\033[33m" << num << "\033[0m";
}

