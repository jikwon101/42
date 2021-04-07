#include <set>
#include <iostream>

int main()
{
	std::set<int> s;
	s.insert(3);
	if (s.find(3) != s.end())
		std::cout << "ji";
	if (s.find(4) == s.end())
		std::cout << "no\n";
	s.insert(3);
	s.insert(2);
	s.insert(10);
	std::set<int> newset;
	newset = s;
	std::cout << "new : " << newset.size() << std::endl;
	std::cout << s.size() << std::endl;
	s.insert(22);
	std::cout << s.size() << std::endl;
	std::set<int>::value_compare mycomp = s.value_comp();
	std::set<int>::iterator bound = s.upper_bound(3);
	std::cout << *bound << std::endl;
	std::set<int>::iterator it1 = s.begin();
	std::set<int>::iterator it2 = s.end();
	std::cout << *it1 << " " << *(--it2) << std::endl;
	std::cout << mycomp(*it1, *it2) << std::endl;
}
