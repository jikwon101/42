#include <list>
#include <iostream>


int main()
{
	int a = 3;
	int b = 2;
	

	//read only
	const int& ref1 = a;
	ref1 = 5;

	//read only
	int const& ref2 = a;
	ref2 = 4;

	// not allowed form
	//int & const ref3 = a;

	// read & write;
	int &ref4 = a;
}
/*
int main()
{
	
	const int a = 3;
	int b = 4;
	std::cout << "[ptr1]-------------------\n";

	// read & write
	int * ptr1 = &a;

	// const value : read only
	std::cout << "[ptr2]-------------------\n";
	const int *ptr2 = &a;
	std::cout << *ptr2 << std::endl;
	ptr2 = &b;
	*ptr2 = 10;

	// const pointer : assign once & read
	std::cout << "[ptr3]-------------------\n";
	int *const ptr3 = &a;
	std::cout << *ptr3 << std::endl;
//	ptr3 = &b;
	*ptr3 = 10;

	// const valule : read only
	std::cout << "[ptr4]-------------------\n";
	int const *ptr4 = &a;
	std::cout << *ptr4 << std::endl;
	ptr4 = &b;
	*ptr4 = 10;
}
*/

