#include <iostream>

int main()
{
	int num = 3;

	double r1 = num;
	std::cout << r1 << std::endl;
	double r2 = (double)num;
	std::cout << r2 << std::endl;
	double r3 = (double &)num;
	std::cout << r3 << std::endl;
	double& r4 = num;
	std::cout << r4 << std::endl;
}
