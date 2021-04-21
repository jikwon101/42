#include "testvector.hpp"
#include <vector>
#include "operator.hpp"


int main()
{
	ft::is_iterator<std::vector<int>::iterator>::value a;
	//ft::vector<int>::iterator::value_type a;
	//std::cout << typeid(a).name() << std::endl;
	/*
	bool a = ft::is_iterator<ft::vector<int>::iterator, ft::iterator_traits<ft::vector<int>::iterator>::value_type>::value;
	if (a == false)
		std::cout << "false\n";
	else
		std::cout << "true\n";
	*/
	//ft::enable_if<ft::is_iterator<ft::vector<int>::iterator, ft::iterator_traits<ft::vector<int>::iterator>::value_type>::value, ft::vector<int>::iterator::value_type>::type b;
//	std::cout << typeid(b).name() << std::endl;
	
	
	//char arr[] = {'1','2','3','4','5'};
	//ft::vector<int> v1(arr, arr + 5);
	//ft::vector<char> v2(3, 10);
	//ft::vector<int> v1(1);
	//ft::vector<int> v2(v1.begin(), v2.end());
	//ft::vector<int>::iterator it;
	/*
	for (it = v1.begin() ; it != v1.end() ; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
	swap(v1, v2);
	for (it = v1.begin() ; it != v1.end() ; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
	//ft::vector<int> v(v1.begin(), v1.end());
	*/
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

