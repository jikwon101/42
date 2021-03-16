#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Halt, citizen! I've been chosen to stand out here to guard the main gate." << std::endl;
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
	std::cout << "I'm too pretty to die!" << std::endl;
}

ScavTrap::ScavTrap(const std::string src_name)
{
	std::cout << "Halt, citizen! I've been chosen to stand out here to guard the main gate." << std::endl;
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
	std::cout << "I'm not to let ANYONE in through here!" << std::endl;
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
	std::cout << "I'm not to let ANYONE in through here!" << std::endl;
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
	std::cout << "WOW! I hit 'em!" << std::endl;
	std::cout << "SC4V-TP " << name;
	std::cout << " attcks " << target << " at range, ";
	std::cout << "causing " << ranged_attack_damage << " points of damage";
	std::cout << std::endl;

}

void	ScavTrap::meleeAttack(std::string const& target)
{
	std::cout << "Heyyah!" << std::endl;
	std::cout << "SC4V-TP " << name;
	std::cout << " attcks " << target << " in melee, ";
	std::cout << "causing " << melee_attack_damage << " points of damage";
	std::cout << std::endl;

}

void	ScavTrap::takeDamage(unsigned int amount)
{	
	int actual_damage;

	actual_damage = amount - armor_damage_reduction;
	if (this->hp <= 0)
	{
		std::cout << "[SYSTEM] Already been crippled" << std::endl;;
		return ;
	}
	this->hp -= actual_damage;
	if (this->hp < 0)
	{
		actual_damage += this->hp;
		this->hp = 0;
	}
	std::cout << "Oh hohoho, that hurts! Yipes!" << std::endl;
	std::cout << "SC4V-TP " << name;
	std::cout << " got attcked, ";
	std::cout << "lost " << actual_damage << " points";
	std::cout << std::endl;
	std::cout << "HP left " << hp << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	int actual_repaired;

	actual_repaired = amount;
	std::cout << "Healsies!" << std::endl;
	if (hp >= max_hp)
	{
		std::cout << "[SYSTEM] Full." << std::endl;
		return ;
	}
	hp += actual_repaired;
	if (hp > max_hp)
	{
		actual_repaired += (max_hp - hp);
		hp = max_hp;
	}
	std::cout << "SC4V-TP " << name;
	std::cout << " has repaired, ";
	std::cout << "restored " << actual_repaired << " points";
	std::cout << std::endl;
	std::cout << "HP left " << hp << std::endl;
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

	std::cout << list[dis(gen)] << " ";
	std::cout << "Then, if you live, return to me here, where I am standing" << std::endl;
}
