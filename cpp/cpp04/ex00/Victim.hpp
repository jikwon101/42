#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>
#include <string>

class Victim
{
protected:
	Victim();
	std::string name;
public:
	Victim(std::string name);
	virtual ~Victim();
	Victim(const Victim& src);
	Victim& operator = (const Victim& src);
	std::string		getName(void) const;
	virtual void	getPolymorphed(void) const;
};

std::ostream& operator << (std::ostream& os, const Victim& src);
#endif
