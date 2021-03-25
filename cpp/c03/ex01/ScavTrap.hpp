#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include <random>

class ScavTrap
{
private:
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
	~ScavTrap();
	ScavTrap(const std::string src_name = "");
	ScavTrap(const ScavTrap& src);
	ScavTrap& operator=(const ScavTrap &src);
	void		rangeAttack(std::string const& target);
	void		meleeAttack(std::string const& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		challengeNewcomer(void);
	void		printMsg(std::string msg);
	void		printInt(int num);
};

#endif
