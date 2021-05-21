#include <iostream>
#include "ft_map.hpp"
#include <map>

int main()
{
	ft::map<int, int> mt;
	mt[5];
	mt[2];
	mt[7];
	std::cout << "-----------\n";
	mt.printinfo();
	ft::map<int, int> m;
	std::cout << "cout : " << m.count(3) << std::endl;
}
