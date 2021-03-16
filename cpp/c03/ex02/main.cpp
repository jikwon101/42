#include <iostream>
#include <string>

class ClapTrap
{
//private:
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
	/*
	ScavTrap();
	~ScavTrap();
	ScavTrap(const std::string src_name);
	ScavTrap(const ScavTrap& src);
	ScavTrap& operator=(const ScavTrap &src);
	void		rangeAttack(std::string const& target);
	void		meleeAttack(std::string const& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	*/
/*
	int			getHP();
	int			getMaxHP();
	int			getEP();
	int			getMaxEp();
	int			getMeleeAttackDamage();
	int			getRangedAttackDamage();
	int			getArmorDamageReduction();
*/
};

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
