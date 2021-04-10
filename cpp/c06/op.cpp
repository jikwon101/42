#include <iostream>

class A
{
public:
	int b;
	A(int n)
	{
		b = n;
	}
};
std::ostream& operator<<(std::ostream & os , A const & a)
{
	os << a.b << std::endl;
	return (os);
}
class B
{
public:
	operator A()
	{
		return (A(2));
	}
};

int main()
{
	B b;

	std::cout << static_cast<A>(b) << std::endl;

}
