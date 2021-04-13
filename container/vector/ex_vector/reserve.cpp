#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1(3);
	
	std::cout << &v1[0] << std::endl;

	v1.reserve(3);
	std::cout << &v1[0] << std::endl;

	v1.reserve(1);
	std::cout << &v1[0] << std::endl;

	std::vector<int> v(5, 5);
	std::cout << &v[0] << std::endl;
	v.reserve(8);
	std::cout << &v[0] << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;

}
