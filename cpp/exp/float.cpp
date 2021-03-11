#include <iostream>

int main()
{
	float a = 0.1;
	float b = 0.01;
	std::cout.precision(50);
	std::cout << a << std::endl;
	std::cout << a * a << std::endl;
	std::cout << b << std::endl;
	std::cout << 0.1 << std::endl;
	double c = 0.1;
	std::cout << c << std::endl;
	std::cout << 0.1f << std::endl;
}
