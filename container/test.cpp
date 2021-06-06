#include <deque>
#include <iostream>
int main()
{
	std::deque<int> t1(1, 1);
	std::deque<int>::iterator it = t1.begin();
	t1.push_back(2);
	t1.push_back(3);
	t1.push_back(4);
	t1.insert(t1.begin(), 10, 9);
}
