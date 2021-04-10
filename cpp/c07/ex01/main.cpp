#include "iter.hpp"
#include "Extra.hpp"

int main()
{
	int arr[] = {1,2,3,4,5};
	std::string  arr1[] = {"my", "hello", "first", "this", "end"};
	char arr2[] = {'s','e','o','u','l'};
	My *arr3 = new My[5];
	float arr4[] = {2.34, 21.2, -3.3, 4.0, -23};
	int length = 5;

	for (int i = 0 ; i < length ; i++)
	{
		arr3[i] = i;
	}
	std::cout << "-----int arr -------------\n";
	iter(arr, length, &print);
	std::cout << "-----string arr -------------\n";
	iter(arr1, length, &print);
	std::cout << "-----char arr -------------\n";
	iter(arr2, length, &print);
	std::cout << "-----class arr -------------\n";
	iter(arr3, length, &print);
	std::cout << "-----float arr -------------\n";
	iter(arr4, length, &print);
}
