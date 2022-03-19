#include <iostream>

class Test
{
public:
	int num1;
	int num2;
	Test(int n1, int n2)
	{
		num1 = n1;
		num2 = n2;
	}
};

extern Test g_t;

int getNum1()
{
	return (g_t.num1);
}

