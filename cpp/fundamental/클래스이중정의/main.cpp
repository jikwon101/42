#include <iostream>

class Test
{
public:
	int num2;
	int num1;
	Test(int n1, int n2)
	{
		num1 = n1;
		num2 = n2;
	}
};

int getNum1();

Test g_t(3,5);
int main()
{
	std::cout << getNum1() << std::endl;
}

