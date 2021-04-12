#include <iostream>

class deque
{
public:
	int n1;
	int n2;

	deque() : n1(20), n2(50) {}
	void printnbr()
	{
		std::cout << n1 << "," <<n2 << std::endl;
	}
};

class stack
{
protected:
	deque c;
};

class My : public stack
{
public:
	void print()
	{
		c.printnbr();         // ok
		this->c.printnbr();   // ok
	}
};
int main()
{
	My n1;

	n1.print();

}
