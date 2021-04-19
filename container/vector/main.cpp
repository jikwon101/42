#include "vector.hpp"
#include <vector>
#include "operator.hpp"


int main()
{
	ft::vector<int> v(4);
	ft::vector<int>::iterator it = v.begin();
	v.erase(it);
	for (it = v.begin() ; it != v.end() ; ++it)
	{
		std::cout << *it << std::endl;
	}
	//ft::vector<int> v(arr, arr+5);
	//ft::vector<int>::iterator it5  = vv1.begin();
	
	//std::cout << typeid(it3).name() <<std::endl;
	//std::cout << typeid(vv1.begin()).name() << std::endl;
	/*
	std::cout << *it3 << std::endl;
	int arr[] = {1,2,3,4,5, 6, 7};
	std::vector<int> testit1(arr, arr+7);
	std::vector<int>::iterator it1 = testit1.begin();
	std::cout << &it1 << std::endl;
	std::vector<int>::iterator it2 = it1 + 3;
	std::cout << *it2 << std::endl;
	*it2 = 10;
	std::cout << *it2 << std::endl;
	//operator < > <= >=
	std::vector<int> h1(1,6);
	std::vector<int> h2(2,1);
	
	if (h1 == h2)
		std::cout << "==\n";
	if (h1 != h2)
		std::cout << "!=\n";
	if (h1 < h2)
		std::cout << "<\n";
	if (h1 <= h2)
		std::cout << "<=\n";
	if (h1 > h2)
		std::cout << ">\n";
	if (h1 >= h2)
		std::cout << ">=\n";
	std::cout << "-------------------\n";
	std::cout << "-------------------\n";
	ft::vector<int> t1(1, 6);
	ft::vector<int> t2(2, 1);
	if (t1 == t2)
		std::cout << "==\n";
	if (t1 != t2)
		std::cout << "!=\n";
	if (t1 < t2)
		std::cout << "<\n";
	if (t1 <= t2)
		std::cout << "<=\n";
	if (t1 > t2)
		std::cout << ">\n";
	if (t1 >= t2)
	*/		
}

