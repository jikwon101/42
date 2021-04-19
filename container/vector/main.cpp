#include "vector.hpp"
#include <vector>
#include "operator.hpp"


int main()
{
	/*
	bool a = ft::is_iterator<ft::vector<int>::iterator, ft::iterator_traits<ft::vector<int>::iterator>::value_type>::value;
	if (a == false)
		std::cout << "false\n";
	else
		std::cout << "true\n";
	*/
	//ft::enable_if<ft::is_iterator<ft::vector<int>::iterator, ft::iterator_traits<ft::vector<int>::iterator>::value_type>::value, ft::vector<int>::iterator::value_type>::type b;
//	std::cout << typeid(b).name() << std::endl;
	
	
	int arr[] = {1,2,3,4,5};
	ft::vector<int> v1(1);
	ft::vector<int> v(v1.begin(), v1.end());
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
	std::cout << "return\n";
}

