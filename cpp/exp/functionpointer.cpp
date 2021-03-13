#include <iostream>


void t1()
{
	std::cout << "t1" << std::endl;
}
void t2()
{
	std::cout << "t2" << std::endl;
}
int main()
{
	void (*arr[2])() = {t1, t2};
	void (*temp)() = t1;

	arr[0]();
	temp();
}
