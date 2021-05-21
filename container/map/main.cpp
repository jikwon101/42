#include <iostream>
#include "ft_map.hpp"
#include <map>

int main()
{
	ft::map<int, int> mt;
	mt[0]; 
	mt[2];
	mt[5];
	mt[1];
	mt[6];
	mt[4];
	std::cout << "-----------\n";
	mt.printinfo();
	std::cout << "-----------\n";
	ft::map<int, int>::iterator it;
	it = mt.begin();
	while (it != mt.end())
	{
		std::cout << (*it).first << std::endl;
		++it;
		std::cout << "---\n";
	}
}
