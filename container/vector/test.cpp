#include <iostream>
template <typename T>
struct my
{
	typedef T value_type;
};

template <typename T, typename = void>
struct test
{
	static const bool value = false;
};


template <typename T>
struct test<T, typename my<T>::value_type>
{
	static const bool value = true;
};

int main()
{
	bool a = test<int,my<int>::value_type>::value;
	if (a == true)
		std::cout << "true\n";
	else
		std::cout << "false\n";
}
