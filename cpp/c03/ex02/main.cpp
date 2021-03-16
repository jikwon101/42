#include <iostream>
#include <string>

class ClapTrap
{
protected:
	int			hp;
	int			max_hp;
	int		 	ep;
	int			max_ep;
	int 		level;
	std::string	name;
	int 		melee_attack_damage;
	int			ranged_attack_damage;
	int			armor_damage_reduction;

public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const std::string src_name);
	ClapTrap(const ClapTrap& src);
	ClapTrap& operator=(const ClapTrap &src);
	void		rangeAttack(std::string const& target);
	void		meleeAttack(std::string const& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};

ClapTrap::ClapTrap()
{
	//std::cout << "Halt, citizen! I've been chosen to stand out here to guard the main gate." << std::endl;
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
	//std::cout << "I'm too pretty to die!" << std::endl;
}

ClapTrap::ClapTrap(const std::string src_name)
{
	//std::cout << "Halt, citizen! I've been chosen to stand out here to guard the main gate." << std::endl;
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
	//std::cout << "I'm not to let ANYONE in through here!" << std::endl;
	this->hp = src.hp;
	this->max_hp = src.max_hp;
	this->ep = src.ep;
	this->max_ep = src.max_ep;
	this->level = src.level;
	this->n:ame = src.name;
	this->melee_attack_damage = src.melee_attack_damage;
	this->ranged_attack_damage = src.ranged_attack_damage;
	this->armor_damage_reduction = src.armor_damage_reduction;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	//std::cout << "I'm not to let ANYONE in through here!" << std::endl;
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
	//std::cout << "WOW! I hit 'em!" << std::endl;
	std::cout << "CL4T-TP " << name;
	std::cout << " attcks " << target << " at range, ";
	std::cout << "causing " << ranged_attack_damage << " points of damage";
	std::cout << std::endl;

}

void	ClapTrap::meleeAttack(std::string const& target)
{
	std::cout << "Heyyah!" << std::endl;
	std::cout << "CL4T-TP " << name;
	std::cout << " attcks " << target << " in melee, ";
	std::cout << "causing " << melee_attack_damage << " points of damage";
	std::cout << std::endl;

}

void	ClapTrap::takeDamage(unsigned int amount)
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



class FragTrap : public ClapTrap
{
private:
public:
	FragTrap();
};
FragTrap::FragTrap()
{
	hp = 10;	
	std::cout << hp << std::endl;
}
int main()
{
	FragTrap t1;
	
	t1.
}
