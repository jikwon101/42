
#ifndef TEST
#include "list.hpp"
#endif

#include <iostream>
#include <list>

class Test;
struct is_odd
{
	bool operator() (const int& value)
	{
		return ((value % 2) == 1);
	}
};

bool mycomparison(double first, double second)
{
	return (int(first) < int(second));
}
bool same_integral_part(double first, double second)
{
	return (int(first) == int(second));
}

int main()
{
	std::cout << "std::list hello\n";
}

class Test
{
public:
	int nbr1;
	Test()
	{
		nbr1 = 100;
		std::cout << "construct...\n";
	}
	Test(int n)
	{	
		nbr1 = n;
		std::cout << "construct with number....\n";
	}
	Test(const Test& src)
	{
		nbr1 =src.nbr1;
		std::cout << "construct by copying.....\n";
	}
	~Test()
	{
		std::cout << "Bye bye...\n";
	}
};

bool operator<(Test const &lhs, Test const &rhs)
{
	return (lhs.nbr1 < rhs.nbr1);
}
bool operator==(Test const& lhs, Test const& rhs)
{
	return (lhs.nbr1 == rhs.nbr1);
}
bool operator!=(Test const& lhs, Test const& rhs)
{
	return (lhs.nbr1 != rhs.nbr1);
}
std::ostream& operator<<(std::ostream& os, const Test& src)
{
	os << src.nbr1;
	return (os);
}

