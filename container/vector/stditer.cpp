#include <iostream>
#include <vector>
class test : public std::vector<int>::iterator
{
public:
	test()
	{
		//ptr = std::vector<int>::iterator::item;
	}
};


class T
{
	int nbr;
};

class C : public T
{
};
int main()
{
	test t;
	C c;
	int a = 0;
	int b = 0;
	std::vector<int> v(1);
	v.push_back(3);
	std::vector<int>::iterator it =  v.begin();
	std::vector<int>::const_iterator it2 = v.begin() + 1;
	int d = 0;
}
