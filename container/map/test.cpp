#include <iostream>

void print(int nbr = 0)
{
	std::cout << nbr << std::endl;
}
int main()
{
	std::pair<int, int> mt(1,3);
	std::pair<const int, int> t(mt);
}
