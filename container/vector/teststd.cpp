#include "vector.hpp"
#include <vector>
#include "operator.hpp"

#include <list>
int main()
{
	std::vector<int> v(2, 3);
	std::vector<int>::iterator it;

	std::cout << v.capacity() << std::endl;
	v.reserve(5);
	std::cout << v.capacity() << std::endl;
	for (it = v.begin() ; it != v.end() ; ++it)
	{
		std::cout << *it << std::endl;
	}
	/*
	char arr[] = {'1','2','3','4','5'};
	std::vector<float> v1(arr, arr + 5);
	std::cout << "error : arrya\n";
	std::cout << "------------\n";
	std::vector<int> v2(3, 10);
	std::cout << "------------\n";
	std::vector<int> v3(1);
	std::cout << "------------\n";
	std::vector<int> v5(v3.begin(), v3.end());
	std::cout << "------------\n";

	std::vector<int>::const_iterator it;
	for (it = v2.cbegin() ; it != v2.cend() ; ++it)
	{
		it[0] = 3;
		std::cout << it[0] << std::endl;
	}
*/
	//std::vector<int>::iterator it;
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
	//std::vector<int> v(v1.begin(), v1.end());
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
	std::vector<int> t1(1, 6);
	std::vector<int> t2(2, 1);
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

