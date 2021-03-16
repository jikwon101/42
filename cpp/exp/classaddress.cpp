#include <iostream>
#include <string>
#include <iomanip>
class A
{
public:
	static int val;
	const int type;
	int age;
	std::string name;
	A();
	void print();
	std::string getName();
};

int A::val = 4;

A::A():type(4)
{
	age = 10;
	name = "JJ";
}

std::string A::getName()
{
	return (this->name);
}
void A::print()
{
	std::cout << "hello" << std::endl;
}

int main()
{
	A a;
	A *tmp;
	void (A::*ptr)(void);
	std::string (A::*ptr2)(void);

	tmp = &a;
	ptr = &A::print;
	ptr2 = &A::getName;
	std::cout << std::setw(30) << "Value of pointer A : "  << tmp << std::endl;
	std::cout << std::setw(30) << "Address of a : " << &a << std::endl;
	std::cout << std::setw(30) << "Address of static a.val : " << &a.val << std::endl;
	std::cout << std::setw(30) << "Address of const a.type : " << &a.type << std::endl;
	std::cout << std::setw(30) <<  "Address of a.age : " << &a.age << std::endl;
	std::cout << std::setw(30) << "Address of a.name : " << &a.name << std::endl;
	std::cout << std::setw(30) << "Address of print() : " << std::hex <<ptr << std::endl;
	std::cout << std::setw(30) << "Address of print() : " << &A::print << std::endl;
	std::cout << std::setw(30) << "Address of getName() : " << std::hex<< ptr2 << std::endl;
}
