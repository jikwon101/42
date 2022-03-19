#include <iostream>

class Test
{
public:
	static int num;
	Test();
	Test& operator=(const Test &t);
};

int	Test::num = 3;

Test& Test::operator=(const Test &t)
{
	return (*this);
}


Test::Test()
{
}

int main()
{
	Test t;
	std::cout << t.num << std::endl;

	Test n;
	n = t;

	n,num = 10;
	std::cout << n.num << std::endl;
	std::cout << t.num << std::endl;


}
