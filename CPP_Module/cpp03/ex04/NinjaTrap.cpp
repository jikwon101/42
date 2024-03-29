#include "NinjaTrap.hpp"

NinjaTrap::~NinjaTrap()
{
	printMsg("What's happening t..o m....\n");
}

NinjaTrap::NinjaTrap(const std::string src_name)
{
	printMsg("Under the new regime, all claptraps will be given liberty!\n");
	hp = 60;
	max_hp = 60;
	ep = 120;
	max_ep = 120;
	level = 1;
	name = src_name;
	melee_attack_damage = 60;
	ranged_attack_damage = 5;
	armor_damage_reduction = 0;

}

NinjaTrap::NinjaTrap(const NinjaTrap& src)
{
	printMsg("Under the new regime, all claptraps will be given liberty!\n");
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

NinjaTrap& NinjaTrap::operator=(const NinjaTrap& src)
{
	printMsg("Under the new regime, all claptraps will be given liberty!\n");
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

void	NinjaTrap::rangeAttack(std::string const& target)
{	
	printMsg("HaHA!!\n");
	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg(" at range, causing ");
	printInt(ranged_attack_damage);
	printMsg(" points of damage\n");
}

void	NinjaTrap::meleeAttack(std::string const& target)
{	
	printMsg("Viva La Robolution!\n");
	printMsg(name);
	printMsg(" attacks ");
	printMsg(target);
	printMsg(" in melee, causing ");
	printInt(melee_attack_damage);
	printMsg(" points of damage\n");
}

void	NinjaTrap::ninjaShoebox(ClapTrap &object)
{
	object.meleeAttack(object.getName());
	object.takeDamage(object.getMeleeAttackDamage());
}

void	NinjaTrap::ninjaShoebox(NinjaTrap &object)
{
	int num;

	if (this == &object)
		printMsg("I don't want to hurt myself!\n");
	else
	{
		srand((unsigned int)time(NULL));
		num = rand() % 5;
		rangeAttack(object.getName());
		object.takeDamage(ranged_attack_damage);
		if (num == 1)
		{
			rangeAttack(name);
			takeDamage(ranged_attack_damage);
		}
	}
}

void	NinjaTrap::ninjaShoebox(FragTrap &object)
{
	for (int i = 0 ; i < 2 ; i++)
	{
		printMsg(name);
		printMsg(" attacks ");
		printMsg(object.getName());
		printMsg("\n");
		object.takeDamage(10);
		usleep(1 * 1000000);
	}
}
void	NinjaTrap::ninjaShoebox(ScavTrap &object)
{
	printMsg(name);
	printMsg(" attacks ");
	printMsg(object.getName());
	printMsg("\n");
	object.takeDamage(object.getMeleeAttackDamage() * 2);
}

void NinjaTrap::printMsg(std::string msg)
{
	std::cout << "\033[32m" << msg << "\033[1m\033[0m";
}

void NinjaTrap::printInt(int num)
{
	std::cout << "\033[32m" << num << "\033[1m\033[0m";
}
