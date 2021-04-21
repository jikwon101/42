#include <vector>
#include <iostream>
#include <list>
int main()
{
	std::list<int> v(3, 4);
	std::list<int>::iterator it ;

	for (it = v.begin() ; it < v.end() ; ++it)
	{
		std::cout << *it << std::endl;
	}
}
