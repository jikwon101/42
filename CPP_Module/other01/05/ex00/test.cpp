#include <iostream>
#include <exception>

void print(int n) throw (std::exception)
{
	throw (2);
}
int main()
{
	try
	{
		print(2);
	}
	catch (int n)
	{
		std::cout << "E\n";
	}
	catch (...)
	{
		std::cout << "w\n";
	}
	std::cout << "st\n";
}
