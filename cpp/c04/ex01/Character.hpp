#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <string>

class Character
{
private:
	std::string		name;
	int				ap;
	AWeapon			*weapon;
	Character(void);

public:
	Character(std::string const & name);
	~Character(void);
	Character(const Character& src);
	Character&			operator=(const Character& src);
	void				recoverAP(void);
	void				equip(AWeapon *);
	void				attack(Enemy *);
	const std::string	getName(void) const;
	int					getAP(void) const;
	const std::string	getWeaponName(void) const;
	bool				isArmed(void) const;
};

std::ostream& operator << (std::ostream& os, const Character& src);
#endif
