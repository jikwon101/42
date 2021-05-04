#include <iostream>
#include <vector>

template <typename T>
class Test  : public std::vector<T>
{
public:
	Test() : std::vector<T>(1)
	{
	}
	Test(int n) : std::vector<T>(n)
	{
	}
	void print()
	{
		std::cout << "size : " << this->size() << std::endl;
	}

};
int main()
{
	Test<std::vector<int> > t1(4);
	t1.print();
}
