#include <iostream>

int test1(void)
{
	std::cout << "1\n";
	return (0);
}

void test1(void)
{
	std::cout << "2\n" ;
	
}
int main()
{
	test1();
}
