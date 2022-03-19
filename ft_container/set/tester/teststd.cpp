#include <iostream>
#ifndef TEST
#include "ft_set.hpp"
#endif
#ifdef TEST
#include <set>
#endif

# define NL print("\n")

template <typename X, typename T>
void	print(X const& name, std::set<T> const& src);
template <typename T, typename U>
void	print_itpair(T val, U end);
template <typename T>
void	print(T src);
template <typename T>
void	print_it(T const& it, T const& end);

int main()
{
	print("-------------------------\n");
	print("CONSTRUCTOR/ITERATOR\n");
	print("-------------------------\n");
	{
		int arr[] = {2,6,4,4,8,10,3,14};
	
		std::set<int> m1;
		m1.insert(arr, arr+8);
		print("m1", m1);
		std::set<int> m2(m1);
		std::set<int> m3(m1.begin(), m1.begin());
		std::set<int> m4(m1.begin(), m1.end());
		std::set<int> m5;
		m5 = m1;
		print("m2", m2);
		print("m3", m3);
		print("m4", m4);
		print("m5", m5);
		print("m5 reverse: ");
		for (std::set<int>::reverse_iterator it = m5.rbegin() ; it != m5.rend() ; ++it)
		{
			print((*it)); print(" ");
		}
		NL;
		std::set<int>::iterator it = m1.begin();
		std::set<int>::iterator cit(it);
		cit = it;
		if (cit == it) print("cit == it\n"); else print("cit != it\n");
	}
	
	NL;
	print("-------------------------\n");
	print("RELATIONAL OPERATORS\n");
	print("-------------------------\n");
	{
		std::set<int> m1;
		std::set<int> m2;
		print("m1", m1);
		print("m2", m2);
		print("m1 == m2  ? ");
		if (m1 == m2) print("True\n"); else print("False\n");
		m1.insert(2); m1.insert(2);
		m1.insert(2);
		print("m1", m1);
		print("m2", m2);
		print("m1 < m2  ? ");
		if (m1 < m2) print("True\n"); else print("False\n");
		print("m1 > m2  ? ");
		if (m1 > m2) print("True\n"); else print("False\n");
	}
	NL;
	print("-------------------------\n");
	print("CAPACITY\n");
	print("-------------------------\n");
	{
		std::set<int> m1;
		print("m1 is empty : "); print(m1.empty()); print("\n");
		print("m1 size : "); print(m1.size()); print("\n");
		m1.insert(10);
		m1.insert(10);
		print("m1", m1);
		print("m1 is empty : "); print(m1.empty()); print("\n");
		print("m1 size : "); print(m1.size()); print("\n");
		print("m1 max : "); print(m1.max_size()); print("\n");
	}
	NL;
	print("-------------------------\n");
	print("MODIFIERS-INSERT\n");
	print("-------------------------\n");
	{
		std::pair<std::set<int>::iterator, bool> res;
		std::set<int> m1;
		print("insert 10\n"); res = m1.insert(10);
		print("res :"); print(res.second); print(" ");
		print_it(res.first, m1.end()); NL;
		print("insert 10\n"); res = m1.insert(10);
		print("res :"); print(res.second); print(" ");
		print_it(res.first, m1.end()); NL;
		int arr[] = {4, 10 ,2 ,2,  1};
		m1.insert(arr, arr + 5);
		std::set<int>::iterator it;
		it = m1.insert(m1.find(2), 2);
		it = m1.insert(m1.find(10), 2);
		std::set<int> m2;
		print("m1", m1);
		print("m2: insert\n");m2.insert(m1.begin(), m1.end());
		print("m2", m2);
	}
	NL;
	print("-------------------------\n");
	print("MODIFIERS-ELSE\n");
	print("-------------------------\n");
	{
		int arr[] = {0,2,2,2,4,6,6,7,8,8};
		std::set<int> m1;
		m1.insert(arr, arr + 10);
		print("m1", m1);
		print("erase begin\n"); 
		m1.erase(m1.begin());
		print("m1", m1);
		int res = m1.erase(2);
		print("erase 2 : "); print(res); print("\n");
		res = m1.erase(14);
		print("erase 14 : "); print(res); print("\n");
		print("m1", m1);
		std::set<int> m3(arr, arr + 10);
		print("m3", m3);
		m3.erase(m3.find(2), m3.find(8));
		print("m3", m3);
		std::set<int> m2;
		print("m1", m1);
		print("m2", m2);
		print("m2 swap m1\n"); m2.swap(m1);
		print("m1", m1);
		print("m2", m2);
		print("m2 clear\n"); m2.clear();
		print("m2", m2);
		m2.insert(10);
		print("m2", m2);
	}
	NL;
	print("-------------------------\n");
	print("OPERATIONS\n");
	print("-------------------------\n");
	{
		int arr[] = {0,2,2,2,4,6,6,7,8,8};
		std::set<int> m1;
		m1.insert(arr, arr + 10);
		std::set<int>::iterator res;
		print("count 2 : "); print(m1.count(2)); print("\n");
		print("find 2\n");res = m1.find(2);
		print_it(res, m1.end()); NL;
		print("count 20 : "); print(m1.count(20)); print("\n");
		print("find 20\n"); res = m1.find(20);
		print_it(res, m1.end()); NL;
	}
	NL;
	print("-------------------------\n");
	print("BOUND\n");
	print("-------------------------\n");
	{	
		int arr[] = {0,2,2,2,4,6,6,7,8,8};
		std::set<int> m1;
		m1.insert(arr, arr + 10);
		print("m1", m1);
		std::set<int>::iterator it;
		print("m1", m1);
		print("lower(0) :"); it = m1.lower_bound(0);
		print_it(it, m1.end()); NL;
		print("lower(2) :"); it = m1.lower_bound(2);
		print_it(it, m1.end()); NL;
		print("lower(5) :"); it = m1.lower_bound(5);
		print_it(it, m1.end()); NL;
		print("lower(20) :"); it = m1.lower_bound(20);
		print_it(it, m1.end()); NL;
		print("upper(0) :"); it = m1.upper_bound(0);
		print_it(it, m1.end()); NL;
		print("upper(2) :"); it = m1.upper_bound(2);
		print_it(it, m1.end()); NL;
		print("upper(5) :"); it = m1.upper_bound(5);
		print_it(it, m1.end()); NL;
		print("upper(20) :"); it = m1.upper_bound(20);
		print_it(it, m1.end()); NL;
	}
	NL;
	print("-------------------------\n");
	{
		std::pair<std::set<int>::iterator, std::set<int>::iterator> res;
		std::set<int> m1;
		int arr[] = {0,2,2,2,4,8,8,9,11,15};
		m1.insert(arr, arr + 10);
		print("m1", m1);
		print("range(0)");
		res = m1.equal_range(0);
		print_itpair(res, m1.end());
		print("range(2)");
		res = m1.equal_range(2);
		print_itpair(res, m1.end());
		print("range(10)");
		res = m1.equal_range(10);
		print_itpair(res, m1.end());
		print("range(15)");
		res = m1.equal_range(15);
		print_itpair(res, m1.end());
	}
	NL;
	print("-------------------------\n");
	print("RETURN\n");
}
class test
{
public:
	int nbr;
	test(int a){nbr = a; std::cout << "here\n";}
	test() : nbr(0)
	{
		std::cout << "hi\n";
	}
	test(test const& x) : nbr(x.nbr)
	{
		std::cout << "copy\n";
	}
	~test(){std::cout << "bye\n";}
	bool operator==(test const& x) const
	{
		return (this->nbr == x.nbr);
	}
	bool operator<(test const& x) const
	{
		return (this->nbr < x.nbr);
	}
	bool operator>(test const&x ) const
	{
		return (this->nbr > x.nbr);
	}
	bool operator!=(test const& x) const
	{
		return (this->nbr != x.nbr);
	}
};

std::ostream& operator<<(std::ostream& os, test & x)
{
	os << x.nbr;
	return (os);
}


template <typename X, typename T>
void	print(X const& name, std::set<T> const& src)
{
	typename std::set<T>::const_iterator it;
	int cnt = 0;
	
	std::cout << name << ": ";
	std::cout << "< ";
	for (it = src.begin() ; it != src.end() ; ++it)
	{
		std::cout << (*it) << " ";
		cnt++;
	}
	if (!cnt)
		std::cout << "EMPTY";
	std::cout << ">\n";
}


template <typename T, typename U>
void	print_itpair(T val, U end)
{
	print("[ ");
	if (val.first == end)
		print("end");
	else
		print(*(val.first));
	print(" , ");
	if (val.second == end)
		print("end");
	else
		print(*(val.second));
	std::cout << " )\n";
}

template <typename T>
void print(T src)
{
	std::cout << src;
}

template <typename T>
void	print_it(T const& it, T const& end)
{
	if (it == end)
		std::cout << "end";
	else
		std::cout << *it;
}
