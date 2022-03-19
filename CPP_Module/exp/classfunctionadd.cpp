#include <iostream>

class My
{
public:
	int test(int a)
	{
		return (a + 3);	
	}
};

typedef int (My::*PTR)(int a);
int main()
{
	PTR f = &My::test;
}
