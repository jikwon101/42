#ifndef TEST
#include "ft_queue.hpp"
#endif
#include <queue>
#include <list>
#include <iostream>


int main()
{
	{
		ft::queue<int, ft::list<int> > t1;
		std::cout << "isEmpty : " << t1.empty() << std::endl;
		std::cout << "size: " << t1.size() << std::endl;
		t1.push(10);
		t1.push(20);
		std::cout << "isEmpty : " << t1.empty() << std::endl;
		std::cout << "size: " << t1.size() << std::endl;
		t1.pop();
		std::cout << "isEmpty : " << t1.empty() << std::endl;
		std::cout << "size: " << t1.size() << std::endl;
	}
	std::cout << "----------------\n";
	{
		ft::queue<int> t1;
		int arr[] = {1,2,3,4,5};
		for (int i = 0; i < 5; i++)
			t1.push(arr[i]);
		std::cout << t1.front() << " : " << t1.back() << "\n";
		t1.front() = 10;
		t1.back() = 50;
		std::cout << t1.front() << " : " << t1.back() << "\n";
	}
	std::cout << "----------------\n";
	{
		ft::queue<int, ft::list<int> > t2;
		t2.push(10);
		t2.push(20);
		t2.push(30);
		t2.push(40);
		ft::queue<int, ft::list<int> > t1(t2);
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
