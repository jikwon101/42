#include "iter.hpp"

int main()
{
	int arr[] = {1,2,3,4,5};
	std::string  arr1[] = {"my", "hello", "first", "this", "end"};
	int length = 5;
	
	iter(arr, length, &print);
	iter(arr1, length, &print);
}
