#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <random>

class FragTrap : virtual public ClapTrap
{
public:
	~FragTrap();
	FragTrap(const std::string src_name = "");
	FragTrap(const FragTrap& src);
	FragTrap& operator=(const FragTrap &src);
	void		printMsg(std::string msg);
	void		printInt(int num);
    void		rangeAttack(std::string const& target);
	void		meleeAttack(std::string const& target);
	void		vaulthunter_dot_exe(std::string const& target);
};

#endif
