#include "Extra.hpp"

My::My(int nbr)
{
	this->nbr = nbr;
}

My::My(My const & src)
{
	this->nbr = src.nbr;
}

My& My::operator=(My const &src)
{
	if (this != &src)
	{
		this->nbr = src.nbr;
	}
	return (*this);
}

My::~My(){}

bool My::operator>(My const & src) const
{
	return (this->nbr > src.nbr);
}

bool My::operator<(My const & src) const
{
	return (this->nbr < src.nbr);
}

bool My::operator==(My const & src) const
{
	return (this->nbr == src.nbr);
}

bool My::operator!=(My const & src) const
{
	return (this->nbr != src.nbr);
}

bool My::operator>=(My const & src) const
{
	return (this->nbr >= src.nbr);
}

bool My::operator<=(My const & src) const
{
	return (this->nbr <= src.nbr);
}

int My::getNbr(void) const
{
	return (this->nbr);
}
std::ostream& operator << (std::ostream &os, My const & src)
{
	os << src.getNbr();
	return (os);
}

