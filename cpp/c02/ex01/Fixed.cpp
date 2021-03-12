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
	if (this != &src)
		this->fixed_point_val = src.getRawBits();
}

Fixed::Fixed(const int src)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point_val = src << Fixed::nbr_of_fractial;
}

Fixed::Fixed(const float src)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point_val = (int)(roundf(src * (1 << Fixed::nbr_of_fractial)));
}

/*
** Assignation operator overload
*/
Fixed&	Fixed::operator=(const Fixed &src)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
		setRawBits(src.getRawBits());
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->fixed_point_val);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point_val = raw;
}

float	Fixed::toFloat(void) const
{
	float res;
	res = (float)(fixed_point_val) / (1 << nbr_of_fractial);
	return (res);
}

int		Fixed::toInt(void)	const
{
	int	res;
	res = fixed_point_val >> nbr_of_fractial;
	return (res);
	
}

std::ostream& operator<<(std::ostream& os, const Fixed &src)
{
	os << src.toFloat();
	return (os);
}
