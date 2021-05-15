#include <iostream>

void print(int nbr = 0)
{
	std::cout << nbr << std::endl;
}
int main()
{
	print();
	print(3);
}
