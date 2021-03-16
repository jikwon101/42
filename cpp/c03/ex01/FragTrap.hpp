#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include <random>
class FragTrap
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
	FragTrap();
	~FragTrap();
	FragTrap(const std::string src_name);
	FragTrap(const FragTrap& src);
	FragTrap& operator=(const FragTrap &src);
	void		rangeAttack(std::string const& target);
	void		meleeAttack(std::string const& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		vaulthunter_dot_exe(std::string const& target);
	void		printMsg(std::string msg);
	void		printInt(int num);
};

#endif
