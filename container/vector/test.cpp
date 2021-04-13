#include <iostream>
#include <cmath>

int main()
{
	std::cout.precision(10);

	std::cout << std::fixed<< (static_cast<unsigned int>(pow(2, 64) / sizeof(int)))<< std::endl;
}
