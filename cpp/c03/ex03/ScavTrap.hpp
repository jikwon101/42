#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <random>

class ScavTrap : public ClapTrap
{
public:
	~ScavTrap();
	ScavTrap(const std::string src_name = "");
	ScavTrap(const ScavTrap& src);
	ScavTrap& operator=(const ScavTrap &src);
	void		printMsg(std::string msg);
	void 		printInt(int num);
	void		rangeAttack(std::string const& target);
	void		meleeAttack(std::string const& target);
	void		challengeNewcomer(void);
};

#endif
