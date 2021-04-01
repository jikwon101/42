#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

int main()
{
	float x = 1234;
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(std::cout.precision()) << x;
	std::string str = ss.str();
	std::cout << std::setprecision(4) << str <<std::endl;
	std::cout << std::setprecision(4) << x << std::endl;
	float  y = x;
	std::cout << y << std::endl;
}
