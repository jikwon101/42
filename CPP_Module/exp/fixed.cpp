#include <iostream>

int main()
{
	float a = 100;
	std::cout.precision(20);
	std::cout << a << std::endl;
	int b;
	b = a / (1 << 4);
	//b = a >> (float)4;
	std::cout << b << std::endl;
}
