#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v3(3, 3);
	std::cout << v3.size() << std::endl;
	std::cout << v3.capacity() << std::endl;
	std::cout << &v3[0] << std::endl;
	v3.resize(3);
	std::cout << v3.size() << std::endl;
	std::cout << v3.capacity() << std::endl;
	std::cout << &v3[0] << std::endl;
	std::cout << "---------------\n";
	std::vector<int>::iterator it;
	for (it = v3.begin() ; it != v3.end() ; it++)
	{
		std::cout << *it << std::endl;
	}
	/*
	std::vector<int> v(20, 4);
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	v.resize(4);
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;

	std::vector<int> v2;
	v2 =v;
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;
	v.resize(7);
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;

	v.resize(20);
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	*/
}
