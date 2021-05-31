#include <iostream>
#include "ft_map.hpp"
#include <map>
class test
{
public:
	int nbr;
	test(int a){nbr = a; std::cout << "here\n";}
	test(){ nbr  = 0;std::cout << "hi\n";}
	~test(){std::cout << "bye\n";}
	bool operator==(test const& x) const
	{
		return (this->nbr == x.nbr);
	}
	bool operator<(test const& x) const
	{
		return (this->nbr < x.nbr);
	}
	bool operator>(test const&x ) const
	{
		return (this->nbr > x.nbr);
	}
	bool operator!=(test const& x) const
	{
		return (this->nbr != x.nbr);
	}
};
std::ostream& operator<<(std::ostream& os, test & x)
{
	os << x.nbr;
	return (os);
}
int main(int ac, char *av[])
{
	int arr[] = {2,4,6,8,10,12,14};

	ft::map<int, int> m1;
	for (int i = 0; i < 7 ; i++)
		m1[arr[i]];
	std::map<int, int> test;
	for (int i = 0; i < 7 ; i++)
		test[arr[i]];
	std::cout << "-----------\n";
	m1.printinfo();
	std::cout << "-----------\n";

	int n = atoi(av[1]);
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> stdpair = test.equal_range(n);

	std::map<int, int>::iterator it1 = stdpair.first;
	if (it1 != test.end())
		std::cout << (*it1).first << std::endl;
	else
		std::cout << "lower : it1 is end\n";
  	std::map<int, int>::iterator it2 = stdpair.second;
	if (it2 != test.end())
		std::cout << (*it2).first << std::endl;
	else
		std::cout << "upper : it2 is end\n";
	std::cout << "-----------\n";

	ft::Pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator>ftpair = m1.equal_range(n);
	ft::map<int, int>::iterator i1 =ftpair.first ;
	if (i1 != m1.end())
		std::cout << (*i1).first << std::endl;
	else
		std::cout << "lower : i1 is end\n";
	ft::map<int, int>::iterator i2 = ftpair.second;
	if (i2 != m1.end())
		std::cout << (*i2).first << std::endl;
	else
		std::cout << "upper : i2 is end\n";
	/*
	ft::map<int, int> mt;
	for (int n = 0 ; n < 30 ; n++)
	{
		mt[rand() % 50];
	}
	mt.printinfo();
	std::cout << "-----------\n";
	ft::map<int, int>::iterator it;
	ft::map<int, int>::iterator it2;
	if (ac < 2)
		{std::cout << "Need Input\n"; return(0);}
	int nbr = atoi(av[1]);	int nbr2 = atoi(av[2]);
	std::cout << nbr << " ~ " << nbr2 << " are gonna be deleted\n";
	it = mt.find(nbr);
	it2 = mt.find(nbr2);
	mt.erase(it, it2);
	std::cout << "-----------\n";
	mt.printinfo();
	std::cout << "-----------\n";
	*/
}
