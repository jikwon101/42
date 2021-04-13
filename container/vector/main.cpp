#include "vector.hpp"
#include <vector>


int main()
{
	std::vector<int> test1(10);
	ft::vector<int> test2;

	std::cout << test1.max_size() << std::endl;
	std::cout << test2.max_size() << std::endl;

	ft::vector<int> j;
	(void)j;

	ft::vector<int>::value_type a;
	a = 3;

	ft::vector<int> test(4, 4);
	ft::vector<int> v3(0);
	v3= test;


	ft::vector<int> v1(3);
	
//	std::cout << &v1[0] << std::endl;

	v1.reserve(3);
//	std::cout << &v1[0] << std::endl;

	v1.reserve(1);
//	ft::cout << &v1[0] << std::endl;

	ft::vector<int> v(5, 5);
//	std::cout << &v[0] << std::endl;
	v.reserve(8);
//	std::cout << &v[0] << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
}

