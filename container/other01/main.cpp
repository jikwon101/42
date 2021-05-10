#include "utils.hpp"

int main()
{
	ft::vector<int> v1(3, 10);
	ft::vector<int>::iterator it;

	for (it = v1.begin() ; it != v1.end() ; ++it)
	{
		std::cout << *it << " " ;
	}
	std::cout << std::endl;

}
