#include <iostream>
#include <string>

class FragTrap
{
private:
	int			hitpoint;
	int			max_hitpoint;
	int		 	energy_point;
	int 		level;
	std::string	name;
	int 		melee_attack_damage;
	int			ranged_attack_damage;
	int			armor_damage_reduction;

public:
	FragTrap();
	~FragTrao();
	FragTrap(const std::string name);
	FragTrap(const FragTrap& src);
	Fixed& operator=(const FragTrap &src);
	rangetAttack(std::string const& target);
	meleeAttack(std::string const& target);
	takeDamage(unsigned int amount);
	beRepaired(unsigned int amount);
};

FragTrap::FragTrap()
{
}

FragTrap::~FragTrap()
{
}

FragTrap::FragTrap(const std::stirng name)
{
}

FragTrap::FragTrap(const FragTrap& src)
{
}
Fixed& FragTrap::operator=(const FragTrap& src)
{
}
FragTrap::rangetAttack(std::string const& target)
{
}
FragTrap::meleeAttack(std::string const& target)
{
}
FragTrap::takeDamage(unsigned int amount)
{
}
FragTrap::beRepaired(unsigned int amount)
{
}
