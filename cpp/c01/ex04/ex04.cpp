#include <iostream>

void print_ptr(std::string *str)
{
	std::cout << *str << std::endl;
}
void print_reference(std::string &str)
{
	std::cout << str << std::endl;
}

int main()
{
	std::string str = "HI THIS IS BRAIN";

	print_ptr(&str);
	print_reference(str);
	return (0);
}
