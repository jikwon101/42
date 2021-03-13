#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Recompiling my combat code!" << std::endl;
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
	std::cout << "I'll stop talking when I'm dead!!" << std::endl;
}

FragTrap::FragTrap(const std::string src_name)
{
	std::cout << "Recompiling my combat code!" << std::endl;
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
	std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
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
	std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
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
	std::cout << "Pop pop!" << std::endl;
	std::cout << "FR4G-TP " << name;
	std::cout << " attcks " << target << " at range, ";
	std::cout << "causing " << ranged_attack_damage << " points of damage";
	std::cout << std::endl;

}

void	FragTrap::meleeAttack(std::string const& target)
{
	std::cout << "Take that!" << std::endl;
	std::cout << "FR4G-TP " << name;
	std::cout << " attcks " << target << " in melee, ";
	std::cout << "causing " << melee_attack_damage << " points of damage";
	std::cout << std::endl;

}

//armor damaget 처리해주기.
void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->hp <= 0)
	{
		std::cout << "[SYSTEM] Already been crippled" << std::endl;;
		return ;
	}
	std::cout << "Why do I even feel pain?!" << std::endl;
	std::cout << "FR4G-TP " << name;
	std::cout << " got attcked, ";
	std::cout << "lost " << amount << " points";
	std::cout << std::endl;
	this->hp -= amount;
	if (this->hp < 0)
		this->hp = 0;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "I found health!" << std::endl;
	if (this->hp >= max_hp)
	{
		std::cout << "[SYSTEM] Full." << std::endl;
		return ;
	}
	std::cout << "FR4G-TP " << name;
	std::cout << " has cured, ";
	std::cout << "restored " << amount << " points";
	std::cout << std::endl;
		this->hp += amount;
	if (this->hp > max_hp)
		this->hp = max_hp;
}

void	FragTrap::vaulthunter_dot_exe(std::string const& target)
{
	void (FragTrap::*attack[5])(std::string const &target) = {&FragTrap::mechromagicianAttack, &FragTrap::minionTrapAttack, &FragTrap::meatUnicycleAttack, &FragTrap::blightBotAttack, &FragTrap::funzerkerAttack};

	(attack[0])(target);
}

void	FragTrap::mechromagicianAttack(std::string const& target)
{
	std::cout << "I have two robot arms!" << std::endl;

}
void	FragTrap::minionTrapAttack(std::string const& target)
{
	std::cout << "Mini-trap on the field!" << std::endl;
}
void	FragTrap::meatUnicycleAttack(std::string const& target)
{
	std::cout << "I AM ON FIRE!! OH GOD, PUT ME OUT!!!" << std::endl;
}
void	FragTrap::blightBotAttack(std::string const& target)
{
	std::cout << "Tell me i'm the prettiest!!" << std::endl;
}
void	FragTrap::funzerkerAttack(std::string const& target)
{
	std::cout << "Oh god I can't stop!" << std::endl;
}
