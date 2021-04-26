#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;

	std::vector<int>::iterator it;
	it= v.begin();
	std::cout << *it << std::endl;
}
