#include "Extra.hpp"

My::My(int n)
{
	this->num = n;
}

My::My(My const & src)
{
	this->num = src.num;
}

My::~My(){}

My& My::operator=(My const & src)
{
	this->num = src.num;
	return (*this);
}

std::ostream& operator<<(std::ostream &os, My const & src)
{
	os << src.num;
	return (os);
}
