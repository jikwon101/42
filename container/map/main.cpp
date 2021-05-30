#include <iostream>
#include "ft_map.hpp"
#include <map>

int main(int ac, char *av[])
{	
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
}
