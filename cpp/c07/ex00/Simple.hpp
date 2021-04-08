#ifndef SIMPLE_HPP
# define SIMPLE_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T const & a, T const & b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T max(T const & a, T const & b)
{
	if (a > b)
		return (a);
	return (b);
}

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
