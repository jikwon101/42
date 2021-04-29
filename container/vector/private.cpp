#include <iostream>

template <typename T>
class Test
{
private:
	T *arr;
public:
	Test() : arr(0) {}
	Test(Test & src) : arr(src.arr) {}
};

int main()
{
	Test<const int>t1;
	Test<int> t2(t1);
}
