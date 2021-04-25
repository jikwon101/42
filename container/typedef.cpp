#include <iostream>


template <typename T>
struct test
{
	typedef T value;
};

template <typename T>
class iter : public test<T>
{
public:
	typedef typename test<T>::value value;
	const value func()
	{
		value a = value();
		return (a);
	}
};

int main()
{
	iter<int> it;

	iter<int>::value t = 3;
	int a = 3;
	const int & b = a;
	std::cout << b << std::endl;
	b = 10;
	std::cout << b << std::endl;
}
