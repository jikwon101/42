#include <iostream>

template <typename T>
class A
{
public:
	T nbr;
};

template <typename  T>
class B : public A<T>
{
public:
	void temp()
	{
		nbr = 10 ;
	}
};

int main()
{
	B<int> b;

}
