#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int fixed_point_val;
	static const int nbr_of_fractial;

public:
	Fixed();							
	~Fixed();	
	Fixed(const Fixed &src);			
	Fixed& operator=(const Fixed &src);	
	int getRawBits(void) const;			
	void setRawBits(int const raw);
};

#endif
