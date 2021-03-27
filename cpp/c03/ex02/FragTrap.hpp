#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <random>

class FragTrap : public ClapTrap
{
private:
	void		mechromagicianAttack(std::string const& target);
	void		minionTrapAttack(std::string const& target);
	void		meatUnicycleAttack(std::string const& target);
	void		blightBotAttack(std::string const& target);
	void		funzerkerAttack(std::string const& target);

public:
	virtual ~FragTrap();
	FragTrap(const std::string src_name = "");
	FragTrap(const FragTrap& src);
	FragTrap& operator=(const FragTrap &src);
	virtual void	rangeAttack(std::string const& target);
	virtual void	meleeAttack(std::string const& target);
	void			vaulthunter_dot_exe(std::string const& target);
	void			printMsg(std::string msg);
	void			printInt(int num);
};

#endif
