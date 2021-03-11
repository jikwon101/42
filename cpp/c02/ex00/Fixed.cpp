#include "Fixed.hpp"

const int Fixed::nbr_of_fractial = 8;

/*
** Default constructor
*/
Fixed::Fixed():fixed_point_val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*
** Destructor
*/
Fixed::~Fixed()
{
	std::cout << "Desturcotr called" << std::endl;
}

/*
** Copy constructor
*/
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor clled" << std::endl;
	*this = src;
}

/*
** Assignation operator overload
*/
Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
		setRawBits(src.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_val);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_val = raw;
}
