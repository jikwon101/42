#include <iostream>
#include "../iterator/iterator.hpp"

template <typename T>
struct A
{
	typedef T type;
	A(){}
};
template <typename T>
struct B
{
};


template <typename T>
class test
{
public:
	T tmp;
	explicit test(size_t a, int const &b = int()) {std::cout << "size_t\n";}
	template <typename U>
	test(U tmp, U tmp2, int a = int(), typename ft::enable_if<false, typename U::type>::type = U::type())
	{
		std::cout << "iter\n";
	}
	template <typename I>
	test(I temp, I tmp2, int b  = int(), typename ft::enable_if<false, int >::type = int())
	{
		std::cout << "test\n";
	}
};


int main()
{
	A<char> t;
	B<char> k;
	test<char> a(3, 4);
}
