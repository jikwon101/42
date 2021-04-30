#include "vector.hpp"
#include <vector>
#include "operator.hpp"
#include <iostream>

template <typename T>
void print(T)
{
	std::cout << typeid(T).name() << std::endl;
}

int main()
{
	ft::vector<int> test(3,4);
	ft::vector<int>::iterator i3 = test.begin();
	ft::vector<int>::iterator i5 = i3;
	i5 = i3;
	ft::vector<int>::const_iterator i4 =  test.end();
	ft::vector<int>::const_iterator i6 = i4;
	ft::vector<int>::const_iterator i7 = i3;
	i6 = i4;
	i7 = i3;
	ft::vector<int>::reverse_iterator rit1 = test.rbegin();
	ft::vector<int>::reverse_iterator rit2(rit1);
	ft::vector<int>::reverse_iterator rit3 = rit2;
	rit1 = rit2;
	
	ft::vector<int>::const_reverse_iterator rr1 = rit1;
	ft::vector<int>::const_reverse_iterator rr2(rr1);
	ft::vector<int>::const_reverse_iterator rr3 = rr2;
	ft::vector<int>::const_reverse_iterator rr4;
	rr4 = rr3;
	print(rit1);
	print(rr4);
	std::cout << "len : " << (rit1 - rr4) << std::endl;

	int arr[] = {0,1,2,3,4};
	ft::vector<int> v(arr, arr + 5);
	ft::vector<int>::reverse_iterator it2 = v.rbegin();
	ft::vector<int>::reverse_iterator it3 = v.rend();
	std::cout << (it2 - it3) << std::endl;

	for (; it2 != it3 ; ++it2)
	{
			std::cout << *it2 << " " ;
	}
	std::cout << "\n";
	
	/*
	ft::vector<int>::iterator it;
	it = rit.base();
	std::cout << *rit << std::endl;
	if (it == v.end())
		std::cout << "erwl\n";
	*/
	/*
	int arr[] = {0,1,2,3};
	ft::vector<int> v(arr, arr+4);
	std::cout << "size : " << v.size() << std::endl;
	std::cout << "capacity : " << v.capacity() << std::endl;
	ft::vector<int>::const_iterator it;
	ft::vector<int>::iterator it2;
	std::cout << typeid(it).name() << std::endl;
	std::cout << typeid(it2).name() << std::endl;

	std::vector<int>::const_iterator it3;
	std::vector<int>::iterator it4;
	std::cout << typeid(it3).name() << std::endl;
	std::cout << typeid(it4).name() << std::endl;

	//for (it = v.begin() ; it != v.end() ; ++it)
	{
		//std::cout << *it << " " ;
	}
	std::cout << std::endl;
	*/
	/*
	char arr[] = {'1','2','3','4','5'};
	ft::vector<float> v1(arr, arr + 5);
	std::cout << "error : arrya\n";
	std::cout << "------------\n";
	ft::vector<int> v2(3, 10);
	std::cout << "------------\n";
	ft::vector<int> v3(1);
	std::cout << "------------\n";
	ft::vector<int> v5(v3.begin(), v3.end());
	std::cout << "------------\n";

	ft::vector<int>::const_iterator it;
	for (it = v2.cbegin() ; it != v2.cend() ; ++it)
	{
		it[0] = 3;
		std::cout << it[0] << std::endl;
	}
*/
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

