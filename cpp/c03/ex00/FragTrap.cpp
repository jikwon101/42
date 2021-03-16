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
	std::cout << "Argh arghargh death gurgle gurglegurgle urgh... death" << std::endl;
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
	std::cout << " attcked " << target << " at range, ";
	std::cout << "causing " << ranged_attack_damage << " points of damage";
	std::cout << std::endl;

}

void	FragTrap::meleeAttack(std::string const& target)
{
	std::cout << "Take that!" << std::endl;
	std::cout << "FR4G-TP " << name;
	std::cout << " attcked " << target << " in melee, ";
	std::cout << "causing " << melee_attack_damage << " points of damage";
	std::cout << std::endl;

}

void	FragTrap::takeDamage(unsigned int amount)
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
	std::cout << "Why do I even feel pain?!" << std::endl;
	std::cout << "FR4G-TP " << name;
	std::cout << " got attcked, ";
	std::cout << "lost " << actual_damage << " points";
	std::cout << std::endl;
	std::cout << "HP left " << hp << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	int actual_repaired;

	actual_repaired = amount;
	std::cout << "I found health!" << std::endl;
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
	std::cout << "FR4G-TP " << name;
	std::cout << " has repaired, ";
	std::cout << "restored " << amount << " points";
	std::cout << std::endl;
	std::cout << "HP left " << hp << std::endl;
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
	
	std::cout << list[dis(gen)] << std::endl;
	std::cout << "FR4G-TP " << name;
	std::cout << " attacked " << target << std::endl;

}

/*
void	FragTrap::vaulthunter_dot_exe(std::string const& target)
{
	int random_number;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 5);
	if (ep < 25)
	{
		std::cout << "[SYSTEM] Out of energy." << std::endl;
		return ;
	}
	ep -= 25;
	random_number = dis(gen);
	switch(random_number)
	{
		default:
			mechromagicianAttack(target);
			break;
		case 2:
			minionTrapAttack(target);
			break;
		case 3:
			meatUnicycleAttack(target);
			break;
		case 4:
			blightBotAttack(target);
			break;
		case 5:
			funzerkerAttack(target);
			break;
	}
	  //void (FragTrap::*attack[])(std::string const &target) = { &FragTrap::mechromagicianAttack, &FragTrap::minionTrapAttack, &FragTrap::meatUnicycleAttack, &FragTrap::blightBotAttack, &FragTrap::funzerkerAttack};
//	(*attack[0])(target);
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
	std::cout << "Tell me i'm the prettiest!!" << std::endl;
	std::cout << "Oh god I can't stop!" << std::endl;
}

void	FragTrap::blightBotAttack(std::string const& target)
{
}

void	FragTrap::funzerkerAttack(std::string const& target)
{
}
*/
