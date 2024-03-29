#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "unistd.h"

class NinjaTrap : virtual public ClapTrap
{
public:
	virtual ~NinjaTrap();
	NinjaTrap(const std::string src_name = "");
	NinjaTrap(const NinjaTrap& src);
	NinjaTrap& operator=(const NinjaTrap &src);
	void			printMsg(std::string msg);
	void 			printInt(int num);
	virtual void	rangeAttack(std::string const& target);
	virtual void	meleeAttack(std::string const& target);
	void			ninjaShoebox(ClapTrap &object);
	void			ninjaShoebox(NinjaTrap &object);
	void			ninjaShoebox(FragTrap &object);
	void			ninjaShoebox(ScavTrap &object);
};

#endif
