#include <iostream>
#include <string>

class Test
{
public:
	std::string type;
	const std::string &getType();
	Test();
	Test(std::string type);
};
Test::Test(){}
Test::Test(std::string type)
{
	this->type = type;
}

 const std::string & Test::getType()
{
	return (this->type);
}

class Human
{
public:
	Test test;
	Human(Test &test);
};

Human::Human(Test &test)
{
	//this->test.type = "hello";
	this->test = test;
}
int main()
{
	Test test("hi");

	Human human(test);
	std::cout << human.test.getType() << std::endl;
}

