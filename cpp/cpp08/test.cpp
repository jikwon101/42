#include <iostream>

template <typename T>
class deque
{
public:
	T temp;
	int n1;
	int n2;

	deque() : n1(20), n2(50) {}
	void printnbr()
	{
		std::cout << n1 << "," <<n2 << std::endl;
	}
};

template <typename T>
class stack
{
protected:
	deque<T> c;
};

template <typename T>
class My : public stack<T>
{
public:
	T a;
	void print()
	{
		c.printnbr();      // compile error
		this->c.printnbr() // ok
	}
};
int main()
{
	My<int> n1;
	stack<int> *temp = new My<int>;
	My<int> *temp1 = static_cast<My<int> *>(temp);
	n1.print();

}
