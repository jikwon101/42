#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fixed_point_val;
	static const int nbr_of_fractial;

public:
	Fixed();							
	~Fixed();
	Fixed(const int src);
	Fixed(const float src);
	Fixed(const Fixed &src);			
	Fixed& operator=(const Fixed &src);	
	int getRawBits(void) const;			
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed &src);
#endif
