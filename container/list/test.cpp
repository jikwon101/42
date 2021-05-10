#include <list>
#include <iostream>

int main()
{
	std::list<int> t(1);
	std::list<int>::reverse_iterator it1 = t.rbegin();
	it1 = it1 + 3;
}
