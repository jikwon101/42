#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>
#include <string>

class Enemy
{
private:
	int			hp;
	std::string	type;

protected:
	void		setHP(int val);
	void		setType(const std::string val);
	Enemy(void);
	
public:
	Enemy(int hp, std::string const &type);
	virtual ~Enemy(void);
	Enemy(Enemy const & src);
	Enemy&				operator=(Enemy const &src);
	const std::string	getType(void) const;
	int					getHP(void) const;
	virtual void 		takeDamage(int amount);
};
#endif
