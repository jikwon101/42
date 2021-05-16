#include <iostream>
#include "ft_map.hpp"
#include <map>

int main()
{
	std::map<int, int> s;
	s[1];
	s[0];
	std::map<int, int>::iterator sit = s.end();
	ft::map<int, int> mt;
	mt[0]; mt[1]; /*mt[2]; mt[3]; mt[4]; mt[5]; mt[6]; mt[7]; mt[8]; mt[9]; 
	mt[10]; mt[11]; mt[12]; mt[13]; mt[14]; mt[15]; mt[16]; mt[17]; mt[18];*/
	std::cout << "-----------\n";
	//mt.printinfo();
	std::cout << "-----------\n";
	ft::map<int, int>::iterator it = mt.begin();
	std::cout << mt.size() << std::endl;
	for (int i = 0; i < mt.size() ; ++i)
	{
		std::cout << "[" << i << "] " << (*it).first << std::endl;
		++it;
	}
	std::cout << "-----------\n";
}



