#include <iostream>
#include <exception>

int func(int val)
{
	if (val == 1)
		throw 0;
	std::cout << "func\n";
	return (1);
}

int main()
{
	std::cout << "1\n";
	try
	{
		std::cout << "2\n";
		func(1);
	}
	catch(int)
	{
		std::cout << "ERR\n";
	}
	std::cout << "3\n";

}
