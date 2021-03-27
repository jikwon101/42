#ifndef FISHERMAN_HPP
# define FISHERMAN_HPP

#include "Victim.hpp"

class Fisherman : public Victim
{	
private:
	Fisherman();
public:
	Fisherman(std::string name);
	virtual ~Fisherman();
	Fisherman(const Fisherman& src);
	Fisherman& operator = (const Fisherman& src);
	virtual void	getPolymorphed(void) const;
};

std::ostream& operator << (std::ostream& os, const Fisherman& src);
#endif
