#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>
#include <string>

class AWeapon
{
private:	
	std::string name;
	int damage;
	int apcost;

protected:
	AWeapon(void);	
	void setDamage(int val);
	void setAPCost(int val);
	void setName(const std::string val);

public:
	AWeapon(std::string const &name, int apcost, int damage);
	virtual ~AWeapon(void);
	AWeapon(AWeapon const & src);
	AWeapon&			operator=(AWeapon const &src);
	const std::string	getName() const;
	int 				getAPCost() const;
	int 				getDamage() const;
	virtual void 		attack() const = 0;
};
#endif
