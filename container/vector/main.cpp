#include "vector.hpp"
#include <vector>
#include "operator.hpp"


int main()
{
	try
	{
		char arr[] = {'1','2','3','4','5'};
		ft::vector<float> v1(arr, arr + 5);
	}
	catch(...)
	{
		std::cout << "error : arrya\n";
	}
	std::cout << "------------\n";
	ft::vector<int> v2(3, 10);
	std::cout << "------------\n";
	ft::vector<int> v3(1);
	std::cout << "------------\n";
	ft::vector<int> v4(v3.begin(), v3.end());
	std::cout << "------------\n";
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

