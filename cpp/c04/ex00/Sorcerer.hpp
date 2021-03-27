#ifndef SORCERER_HPP
# define SORCERER_HPP

#include "Victim.hpp"

class Sorcerer
{
private:
	Sorcerer();
	std::string name;
	std::string title;
public:
	Sorcerer(std::string name, std::string title);
	~Sorcerer();
	Sorcerer(const Sorcerer& src);
	Sorcerer& operator = (const Sorcerer& src);
	std::string	getName(void) const;
	std::string	getTitle(void) const;
	void		polymorph(const Victim& src) const;
};

std::ostream& operator << (std::ostream& os, const Sorcerer& src);
#endif
