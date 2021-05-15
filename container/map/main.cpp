#include <iostream>
#include "ft_map.hpp"
#include <map>

int main()
{
	ft::map<int, int> mt;
	
	std::cout << "10 : " ; mt[10];
	std::cout << "20 : " ; mt[20];
	std::cout << "30 : " ; mt[30];
	std::cout << "16 : " ; mt[16];
	std::cout << "09 : " ; mt[9];
	std::cout << "07 : " ; mt[7];
	std::cout << "08 : " ; mt[8];
	mt.printinfo();
	std::cout << "-----------\n";
}


