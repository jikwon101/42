#include <iostream>

class Test
{
public:
	int num;
	int& ref;
	int* ptr;
	Test();
	~Test();
};

Test::Test():ref(num)
{
	num = 3;

	ptr = new int;
	*ptr = 5;
}

Test::~Test()
{
	if (ptr)
	{
		std::cout << "NOT NULL\n";
		delete ptr;
	}
}

int main()
{
	Test *t = new Test;

	Test n = *t;
	std::cout << n.ref << std::endl;
	t->num = 10;
	std::cout << n.ref << std::endl;
	//delete t;

}
