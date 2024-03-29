#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
	int				hp;
	int				max_hp;
	int		 		ep;
	int				max_ep;
	int 			level;
	std::string		name;
	int 			melee_attack_damage;
	int				ranged_attack_damage;
	int				armor_damage_reduction;

public:
	virtual ~ClapTrap();
	ClapTrap(const std::string src_name = "");
	ClapTrap(const ClapTrap& src);
	ClapTrap& operator=(const ClapTrap &src);
	virtual void	rangeAttack(std::string const& target);
	virtual void	meleeAttack(std::string const& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			printMsg(std::string msg);
	void			printInt(int num);
	std::string		getName(void);
	int				getMeleeAttackDamage();
	int				getRangedAttackDamage();
};

#endif
