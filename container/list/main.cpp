#include <iostream>
#include <list>
#include "list.hpp"
#include <memory>

class Test;
class Test
{
public:
	int nbr1;
	int nbr2;
	const char *_next;
	const char *_next2;
	Test()
	{
		nbr1 = nbr2 = 100;
		std::cout << "construct...\n";
	}
	Test(int n) : _next(NULL)
	{	
		nbr1 = nbr2 = n;
		std::cout << "construct with number....\n";
	}
	Test(const Test& src)
	{
		nbr1 = nbr2 = src.nbr1;
		std::cout << "construct by copying.....\n";
	}
	~Test()
	{
		std::cout << "Bye bye...\n";
	}
};
bool operator<(Test const &lhs, Test const &rhs)
{
	return (lhs.nbr1 < rhs.nbr1);
}
bool operator==(Test const& lhs, Test const& rhs)
{
	return (lhs.nbr1 == rhs.nbr2);
}
bool operator!=(Test const& lhs, Test const& rhs)
{
	return (lhs.nbr1 != rhs.nbr2);
}
std::ostream& operator<<(std::ostream& os, const Test& src)
{
	os << src.nbr1;
	return (os);
}
template <typename T>
void	print(const std::list<T>& list)
{
	typename std::list<T>::const_iterator it;

	std::cout << "list : ";
	for (it = list.begin() ; it != list.end() ; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}
template <typename T>
void	print(const ft::list<T>& list)
{
	typename ft::list<T>::const_iterator it;

	std::cout << "list : ";
	for (it = list.begin() ; it != list.end() ; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}
struct is_odd
{
	bool operator() (const int& value)
	{
		return ((value % 2) == 1);
	}
};

bool mycomparison(double first, double second)
{
	return (int(first) < int(second));
}
bool same_integral_part(double first, double second)
{
	return (int(first) == int(second));
}
void testprint(ft::list_const_iterator<int> const& it)
{
	(void)it;
	std::cout << "here\n";
}
int main()
{	
	ft::list<int> t1(1);
	t1.push_back(10);
	print(t1);
	ft::list<int> t2;
	t2 = t1;
	print(t2);
	{
			ft::list<int> tt;
			ft::list<int> ttt;
			tt.sort();
			ttt.sort();
			ft::list<int> t1(1, 3);
			t1.push_back(4);
			t1.push_back(8);
			t1.push_back(1);
			t1.push_back(8);
			t1.push_back(0);
			t1.push_back(9);
			t1.push_back(2);
			print(t1);
			std::cout << "---------\n";
			t1.sort();
			print(t1);
		}
		std::cout << "--------------------\n";
		{
			std::list<int> t1(1, 3);
			t1.push_back(4);
			t1.push_back(8);
			t1.push_back(1);
			t1.push_back(8);
			t1.push_back(0);
			t1.push_back(9);
			t1.push_back(2);
			print(t1);
			std::cout << "---------\n";
			t1.sort();
			print(t1);
		}
		std::cout << "--------------------\n";
		std::cout << "--------------------\n";
		{
			ft::list<float> t1(1, 2.6);
			t1.push_back(2.3);
			t1.push_back(4.1);
			t1.push_back(2.4);
			t1.push_back(2.1);
			t1.push_back(1.8);
			print(t1);
			std::cout << "----------\n";
			t1.sort(mycomparison);
			print(t1);
		}
	std::cout << "-----------------------------\n";

		{
			std::list<float> t1(1, 2.6);
			t1.push_back(2.3);
			t1.push_back(4.1);
			t1.push_back(2.4);
			t1.push_back(2.1);
			t1.push_back(1.8);
			print(t1);
			std::cout << "----------\n";
			t1.sort(mycomparison);
			print(t1);
		}
		{
			ft::list<int> t1;
			ft::list<int> t2(1,2);
			t2.push_back(4);
			print(t1);
			print(t2);
			std::cout << "----\n";
			t1.merge(t2);
			print(t1);
			print(t2);
		}
		std::cout << "--------------\n";
		{	
			std::list<int> t1;
			std::list<int> t2(1,2);
			t2.push_back(4);
			print(t1);
			print(t2);
			std::cout << "----\n";
			t1.merge(t2);
			print(t1);
			print(t2);

		}
	{
		ft::list<int> t1(3,3);
		t1.push_back(6);
		t1.push_back(7);
		ft::list<int> t2(2, 1);
		t2.push_back(3);
		t2.push_back(5);
		t2.push_back(5);
		//t2.push_back(8);
		//t2.push_back(10);
		print(t1);
		print(t2);
		std::cout << "-------\n";
		t1.merge(t2);
		print(t1);
		print(t2);
	}
	std::cout << "---------------\n";
	{	
		std::list<int> t1(3,3);
		t1.push_back(6);
		t1.push_back(7);
		std::list<int> t2(2, 1);
		t2.push_back(3);
		t2.push_back(5);
		t2.push_back(5);
		//t2.push_back(8);
		//t2.push_back(10);
		print(t1);
		print(t2);
		std::cout << "-------\n";
		t1.merge(t2);
		print(t1);
		print(t2);

	}
	{
		ft::list<float> t1(1, 2.1);
		t1.push_back(2.3);
		t1.push_back(3.2);
		ft::list<float> t2(1, 1.7);
		t2.push_back(2.2);
		t2.push_back(2.5);
		t2.push_back(2.7);
		//t2.push_back(3.1);
		print(t1);
		print(t2);
		std::cout << "----\n";
		t1.merge(t2, mycomparison);
		print(t1);
		print(t2);
	}
	std::cout << "---------------\n";
	{	
		std::list<float> t1(1, 2.1);
		t1.push_back(2.3);
		t1.push_back(3.2);
		std::list<float> t2(1, 1.7);
		t2.push_back(2.2);
		t2.push_back(2.5);
		t2.push_back(2.7);
		//t2.push_back(3.1);
		print(t1);
		print(t2);
		std::cout << "----\n";
		t1.merge(t2, mycomparison);
		print(t1);
		print(t2);

	}
	{
		ft::list<int> ttt(1, 4);
		ttt.push_back(7);
		ttt.push_back(10);
		ttt.reverse();
		print(ttt);
		ttt.resize(3);
		ttt.erase(ttt.begin());
		ttt.pop_back();
		ttt.reverse();
		ttt.assign(1, 100);
		ft::list<int> t1(99);
		t1.swap(ttt);
		t1.empty();
		t1.size();
		t1.max_size();
		//ft::list<int>::iterator it1 = ttt.begin();
		//ft::list<int>::const_iterator it2 = ttt.begin();
		//if (it1 == it2)
		//	std::cout << "hwer\n";
		std::cout << "RETURN\n";
	}
	
	std::cout << "----------------\n";
	{	
		std::list<int> t1(1, 1);
		t1.push_back(2);
		t1.push_back(3);
		t1.push_back(4);
		std::list<int> t2(1, 10);
		t2.push_back(20);
		t2.push_back(30);
		print(t1);
		print(t2);
		std::list<int> t3;
		//t2.splice(t2.begin(), t3, t3.begin());
		print(t1);
		print(t2);
		std::cout << "RETURN\n";
	}
	std::cout << "----------------\n";
}
