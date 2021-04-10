#ifndef EXTRA_HPP
# define EXTRA_HPP

#define CL "\033[1m\33[36m"
#define RS "\033[0m"
#include "Array.hpp"

template <typename T1, typename T2>
void init(T1 &arr, T2 value)
{
	std::cout <<CL <<  "INIT with " << RS << value << std::endl;
	for (int i = 0; i < static_cast<int>(arr.size()) ; i++)
	{
		arr[i] = value;
	}
}

template <typename T1>
void print(T1 &arr)
{
	for (int i = 0; i < static_cast<int>(arr.size()) ; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

class A
{
public:
	int nbr;
	A()
	{
		nbr = 0;
	}
	A(int a);
	A& operator=(int n)
	{
		this->nbr = n;
		return (*this);
	}
};

std::ostream& operator<<(std::ostream& os, A const & src)
{
	os << src.nbr;
	return (os);
}

#endif
