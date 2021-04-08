#include "Extra.hpp"

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
