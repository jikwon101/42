#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	std::vector<int> v2;

	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;

	std::cout << "push --------------\n";
	v2.push_back(30);
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;
	v = v2;
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;


	std::cout << "push --------------\n";
	v2.push_back(50);
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;


	std::cout << "push --------------\n";
	v2.push_back(20);
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;


	std::cout << "push --------------\n";
	v2.push_back(10);
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;
	v = v2;
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;


	std::cout << "push --------------\n";
	v2.push_back(10);
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;
	v = v2;

	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
}
