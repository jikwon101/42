#ifndef TEST
#include "ft_stack.hpp"
#endif

#ifdef TEST
#include <stack>
#include <list>
#include <vector>
#endif

#include <iostream>


int main()
{
	{
		std::stack<int, std::list<int> > t1;
		std::cout << "isEmpty : " << t1.empty() << std::endl;
		std::cout << "size: " << t1.size() << std::endl;
		t1.push(10);
		t1.push(20);
		t1.push(30);
		t1.push(40);
		std::cout << t1.top() << std::endl;
		t1.pop();
		std::cout << t1.top() << std::endl;
		t1.pop();
		std::cout << t1.top() << std::endl;
		t1.pop();
		std::cout << t1.top() << std::endl;
		t1.pop();
		std::cout << t1.top() << std::endl;
	}
	std::cout << "----------------\n";
	{
		std::stack<int, std::list<int> > t2;
		t2.push(10);
		t2.push(20);
		t2.push(30);
		t2.push(40);
		std::stack<int, std::list<int> > t1(t2);
		std::cout << "t1 == t2  ?  " ;
		if (t1 == t2) std::cout << "true\n"; else std::cout << "false\n";
		std::cout << "t1 != t2 ?  ";
		if (t1 != t2) std::cout << "true\n"; else std::cout << "false\n";
		std::cout << "t1 < t2  ?  ";
		if (t1 < t2) std::cout << "true\n"; else std::cout << "false\n";
		std::cout << "t1 <= t2  ?  ";
		if (t1 <= t2) std::cout << "true\n"; else std::cout << "false\n";
		std::cout << "t1 > t2  ?  ";
		if (t1 > t2) std::cout << "true\n"; else std::cout << "false\n";
		std::cout << "t1 >= t2  ?  ";
		if (t1 >= t2) std::cout << "true\n"; else std::cout << "false\n";
	}
	std::cout << "----------------\n";
}
