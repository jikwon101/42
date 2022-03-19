#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle(void);
	virtual ~PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const &src);
	PlasmaRifle&	operator=(PlasmaRifle const & src);
	virtual void	attack(void) const;
};

#endif
