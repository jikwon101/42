#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	//std::cout << "Recompiling my combat code!" << std::endl;
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
	//std::cout << "I'll stop talking when I'm dead!!" << std::endl;
}

ScavTrap::ScavTrap(const std::string src_name)
{
	//std::cout << "Recompiling my combat code!" << std::endl;
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
	//std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
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
	//std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
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
	/*
	std::cout << "Pop pop!" << std::endl;
	std::cout << "FR4G-TP " << name;
	std::cout << " attcks " << target << " at range, ";
	std::cout << "causing " << ranged_attack_damage << " points of damage";
	std::cout << std::endl;
	*/

}

void	ScavTrap::meleeAttack(std::string const& target)
{
		/*
	std::cout << "Take that!" << std::endl;
	std::cout << "FR4G-TP " << name;
	std::cout << " attcks " << target << " in melee, ";
	std::cout << "causing " << melee_attack_damage << " points of damage";
	std::cout << std::endl;
	*/

}

//armor damaget 처리해주기.
void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hp <= 0)
	{
		//std::cout << "[SYSTEM] Already been crippled" << std::endl;;
		return ;
	}
	/*
	std::cout << "Why do I even feel pain?!" << std::endl;
	std::cout << "FR4G-TP " << name;
	std::cout << " got attcked, ";
	std::cout << "lost " << amount << " points";
	std::cout << std::endl;
	*/
	this->hp -= amount;
	if (this->hp < 0)
		this->hp = 0;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	//std::cout << "I found health!" << std::endl;
	if (this->hp >= max_hp)
	{
		//std::cout << "[SYSTEM] Full." << std::endl;
		return ;
	}
	/*
	std::cout << "FR4G-TP " << name;
	std::cout << " has cured, ";
	std::cout << "restored " << amount << " points";
	*/
	std::cout << std::endl;
		this->hp += amount;
	if (this->hp > max_hp)
		this->hp = max_hp;
}

void	ScavTrap::challengeNewcommer(void)
{
}

void	ScavTrap::t1(void);
void	ScavTrap::t2(void);
void	ScavTrap::t3(void);
void	ScavTrap::t4(void);
void	ScavTrap::t5(void);