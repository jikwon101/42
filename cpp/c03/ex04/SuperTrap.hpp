#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include "NinjaTrap.hpp"
#include "FragTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
	~SuperTrap();
	SuperTrap(const std::string src_name = "");
	SuperTrap(const SuperTrap& src);
	SuperTrap& operator=(const SuperTrap &src);
	void		printMsg(std::string msg);
	void 		printInt(int num);
	void		rangeAttack(std::string const& target);
	void		meleeAttack(std::string const& target);
};

#endif
