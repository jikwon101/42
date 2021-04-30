#include <iostream>

// 복사 생성자 인자 const& 확인하기 위함. 


template <typename T>
class test
{
public:
	test()
	{
		std::cout << "no : \n";
	}
	test(int b)
	{
		std::cout << "no : int\n";
	}
};

template <typename T>
class test<T *>
{
public:
	test()
	{
	}
	test(int a)
	{
		std::cout << "int\n";
	}

	//test(test const& src)
	//test(test &src)
	test(test  src)
	{
		std::cout << "copy\n";
	}
	test& operator=(test &src)
	{
		std::cout << "oper=\n";
		return (*this);
	}
};

template <typename T>
class my
{
public:
	typedef T* pointer;
	typedef test<pointer> test;

	test createTest(void)
	{
		int num = 1;
		test res(num);
		return (res);
		//return (num);
	}
};
int main()
{
	test<int *> a;
	my<int> v;
	v.createTest();
}
