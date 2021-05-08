#include <iostream>
#include <list>
#include "list.hpp"
#include <memory>

class Test;
class Test
{
public:
	int nbr1;
	int nbr2;
	const char *_next;
	const char *_next2;
	//Test* _next;
	//Test* _next1;
	Test()
	{
		std::string test = "hi";
		std::string test1 = "hello";
		_next = test.c_str();
		_next2 = test1.c_str();

		std::cout << "construct...\n";
	}
	Test(int n) : _next(NULL)
	{	
		std::string test = "hi";
		std::string test1 = "hello";
		_next = test.c_str();
		_next2 = test1.c_str();


		std::cout << "construct with number....\n";
		nbr1 = nbr2 = n;
	}
	Test(const Test& src)
	{
		nbr1 = nbr2 = src.nbr1;
		std::string test = "hi";
		std::string test1 = "hello";
		_next = test.c_str();
		_next2 = test1.c_str();

		std::cout << "construct by copying.....\n";
	}
};

class alloc
{
public:
	std::allocator<int> t;
	int size;
	ft::Pair<char*, char*> ta;
};

std::ostream& operator<<(std::ostream& os, const Test& src)
{
	os << src.nbr1;
	return (os);
}

int main()
{
	ft::list<Test> l1(2, 10);
	ft::list<Test>::iterator myit = l1.begin();
	std::cout << "------\n";
	Test& temp = l1.back();
	std::cout << temp << std::endl;
	std::cout << "------\n";
	std::cout << "------\n";
	std::cout << l1.empty() << " : " << l1.size() <<std::endl;
	ft::list<char> t;
	std::list<char> tt;
	std::cout << t.max_size() << std::endl;
	std::cout << tt.max_size() << std::endl;
}
