#ifndef TEST
#include "ft_stack.hpp"
#endif
#include <stack>
#include <list>
#include <iostream>


int main()
{
	{
		ft::stack<int, ft::list<int> > t1;
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
		ft::stack<int, ft::list<int> > t2;
		t2.push(10);
		t2.push(20);
		t2.push(30);
		t2.push(40);
		ft::stack<int, ft::list<int> > t1(t2);
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
