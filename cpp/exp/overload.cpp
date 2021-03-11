#include <iostream>
#include <string>

class Test
{
public:
	int num;
	std::string name;
	std::ostream& operator<<(std::ostream& os, const Test &src);
	Test();
};

Test::Test():num(3),name("hi"){}

std::ostream& Test::operator<<(std::ostream& os, const Test &src)
{
	//os << src.name << std::endl;
	return (os);
}
int main()
{
	Test test;

	std::cout << test;
}
