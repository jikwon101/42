#include <iostream>
#include <vector>
#include <iterator>
#include <exception>
/*
template <typename T>
T  easyfind(T first, int n)
{
	for (int i = 0; i < first.size(); i++)
	{
		if (first[i] == n)
			return (first + i);
	}
	return (first + first.size());
}
*/
int main()
{
	size_t idx;
	std::vector<int> v(5, 3);
	std::vector<int>::iterator it = v.begin();
	std::cout << &it << std::endl;
	std::cout << &v << std::endl;
	v.push_back(23);
	for (size_t i = 0 ; i < v.size() ; i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << "\n----------------------\n";
	try
	{
		//it  = easyfind(v,3);
		//std::cout << *p << std::endl;
	}
	catch(...)
	{
		std::cout << "Can't found\n";
	}
}
