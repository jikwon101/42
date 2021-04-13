#include <vector>
#include <iostream>
int main()
{
	std::vector<int> a;

	std::cout << a.capacity() << std::endl;
	std::cout << a.size() << std::endl;
	*(a.begin()) = 3;
	std::cout << a.capacity() << std::endl;
	std::cout << a.size() << std::endl;
}
