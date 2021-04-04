#include <iostream>
#include <string>

template <typename T1>
void iter(T1 *array, int length, void (*f)(T1 const &elt))
{
	for (int i = 0; i < length ; i++)
	{
		(*f)(array[i]);
	}
}

template <typename T1>
void print(T1 const & elem)
{
	std::cout << elem << std::endl;
}

int main()
{
	int arr[] = {1,2,3,4,5};
	std::string  arr1[] = {"my", "hello", "first", "this", "end"};
	int length = 5;
	
	iter(arr, length, &print);
	iter(arr1, length, &print);
}
