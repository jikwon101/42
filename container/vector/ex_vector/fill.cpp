#include <iostream>
#include <vector>

int main()
{
	int arr[] = {1,2,3,4,5};

	std::vector<int> v(arr, arr+5);
	std::vector<int>::iterator it = v.begin();

	for (it = v.begin() ; it != v.end()  ; it++)
	{
		std::cout << *it << std::endl;
	}

}
