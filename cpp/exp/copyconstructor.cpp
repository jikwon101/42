#include <iostream>

class Test
{
private:
	int num;
	std::string *string;
public:
	Test(int n, std::string test);
	int getNum();
	Test();
	~Test();
	Test(const Test &org);
	//Test& operator=(const Test &old);
};
Test::Test():num(5)
{};
Test::~Test()
{
	std::cout << "destructor" << ": " << *string << std::endl;;
	delete string;
}
Test::Test(int n, std::string test)
{
	std::cout << "default\n";
	num = n;
	string = new std::string(test);
}

int Test::getNum()
{
	std::cout << *string << " : " << num << std::endl;
	return (true);
}

Test::Test(const Test &org)
{
	std::cout << "copy\n";
	num = org.num;
	string = new std::string(*org.string);
}
/*
Test& Test::operator=(const Test& old)
{
	std::cout << "operator .." << std::endl;
	this->num = old.num;
	this->string = new std::string(*old.string);
	return (*this);
}*/

int main()
{
	Test(5, "s");
	std::cout << "main" << std::endl;
		/*
	Test a = Test(4, "a");
	a.getNum();
	Test b(a);
	*/
	/*
	Test a;
	a = Test(4, "a");
	a.getNum();
	*/
	/*
	Test a(3, "A");
	Test b = a;
	b.getNum();
	*/
	/*
	std::cout << b.getNum() << std::endl;
	a.setNum(10);
	std::cout << a.getNum() << std::endl;
	std::cout << b.getNum() << std::endl;
	*/
	std::cout << "return main\n";
}
