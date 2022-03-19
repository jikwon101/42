#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{	
private:
	Peon();
public:
	Peon(std::string name);
	virtual ~Peon();
	Peon(const Peon& src);
	Peon& operator = (const Peon& src);
	virtual void	getPolymorphed(void) const;
};

std::ostream& operator << (std::ostream& os, const Peon& src);
#endif
