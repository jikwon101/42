#include <iostream>

int main()
{
	int num;

	try
	{
		std::cin >> num;
		if (num == 1)
			throw 0;
	}
	catch (int )
	{
		std::cout << "ERROR\n";
	}
}
