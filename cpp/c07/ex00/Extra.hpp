#ifndef EXTRA_HPP
# define EXTRA_HPP

#include <iostream>

class A
{
public:
	int nbr;
	A(){}
	A(int nbr)
	{
		this->nbr = nbr;
	}
	A& operator=(A const & a1)
	{
		if (this != &a1)
			this->nbr = a1.nbr;
		return (*this);
	}
};

bool operator>(A const & a1, A const & a2)
{
	return a1.nbr > a2.nbr;
}

bool operator<(A const & a1, A const & a2)
{
	return a1.nbr < a2.nbr;
}

std::ostream& operator << (std::ostream &os, A const & a1)
{
	os << a1.nbr;
	return (os);
}

#endif
