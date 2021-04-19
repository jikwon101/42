#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v(3);
	std::cout << "size : " << v.size() << ", capaticy : " << v.capacity() << std::endl;
	v.push_back(2);
	std::cout << "size : " << v.size() << ", capaticy : " << v.capacity() << std::endl;
	v.push_back(2);
	std::cout << "size : " << v.size() << ", capaticy : " << v.capacity() << std::endl;
	v.push_back(2);
	std::cout << "size : " << v.size() << ", capaticy : " << v.capacity() << std::endl;
	v.push_back(2);
	std::cout << "size : " << v.size() << ", capaticy : " << v.capacity() << std::endl;
}
