#include "Enemy.hpp"

/*
** Coplien's Form
*/
Enemy::Enemy(){}

Enemy::~Enemy(){}

Enemy::Enemy(int hp, std::string const &type)
{
	setType(type);
	setHP(hp);
}

Enemy::Enemy(Enemy const & src)
{
	setType(src.getType());
	setHP(src.getHP());
}

Enemy& Enemy::operator = (Enemy const &src)
{
	if (this != &src)
	{	
		setType(src.getType());
		setHP(src.getHP());
	}
	return (*this);
}

/*
** Getter
*/
const std::string Enemy::getType(void) const
{
	return (this->type);
}

int Enemy::getHP() const
{
	return (this->hp);
}

/*
** Setter
*/
void Enemy::setHP(int val)
{
	if (val < 0)
		val = 0;
	this->hp = val;
}

void Enemy::setType(std::string val)
{
	this->type = val;
}

/*
** Member Function
*/
void	Enemy::takeDamage(int amount)
{
	if (amount < 0)
		return ;
	if (hp < 0)
	{
		std::cout << "It's already died" << std::endl;
		return ;
	}
	hp -= amount;
	if (hp < 0)
		hp = 0;
}
