#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <cstdlib>
#include <ctime>


class ScavTrap : public ClapTrap
{
public:
	virtual ~ScavTrap();
	ScavTrap(const std::string src_name = "");
	ScavTrap(const ScavTrap& src);
	ScavTrap& operator=(const ScavTrap &src);
	virtual void	rangeAttack(std::string const& target);
	virtual void	meleeAttack(std::string const& target);
	void			challengeNewcomer(void);
	void			printMsg(std::string msg);
	void			printInt(int num);
};

#endif
