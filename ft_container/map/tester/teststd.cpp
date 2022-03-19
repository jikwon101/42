#include <iostream>
#ifndef TEST
#include "ft_map.hpp"
#endif
#ifdef TEST
#include <map>
#endif

#define NL print("\n")

template <typename X, typename T, typename U>
void	print(X const& name, std::map<T, U> const& src);
template <typename T>
void	print(T  src);
template <typename T, typename U>
void	print_itpair(T val, U end);
template <typename T>
void	print_it(T const& it, T const& end);

int main()
{
	print("-------------------------\n");
	print("CONSTRUCTOR/ITERATOR\n");
	print("-------------------------\n");
	{
		int arr[] = {2,4,6,8,10,12,14};
		std::map<int, int> m1;
		for (int i = 0; i < 7 ; i++)
			m1[arr[i]];
		print("m1", m1);
		std::map<int, int> m2(m1);
		std::map<int, int> m3(m1.begin(), m1.begin());
		std::map<int, int> m4(m1.begin(), m1.end());
		std::map<int, int> m5;
		m5 = m1;
		print("m2", m2);
		print("m3", m3);
		print("m4", m4);
		print("m5", m5);
		print("m5 reverse print : \n");
		for (std::map<int, int>::reverse_iterator it = m5.rbegin() ; it != m5.rend() ; ++it)
		{
			std::cout << (*it).first << " ";
		}
		NL;
		std::map<int, int>::iterator it = m1.begin();
		std::map<int, int>::const_iterator cit(it);
		cit = it;
		if (cit == it) print("cit == it\n"); else print("cit != it\n");

	}
	NL;
	print("-------------------------\n");
	print("CAPACITY\n");
	print("-------------------------\n");
	{
		std::map<int, int> m1;
		print("m1 is empty : "); print(m1.empty()); NL;
		print("m1 size : "); print(m1.size()); NL;
		m1[10];
		print("key10, value : "); print(m1[10]); NL;
		m1[10] = 20;
		print("key10, value : "); print(m1[10]); NL;
		m1[100] = 100; m1[200] = 200;
		print("m1", m1);
		print("m1 is empty : "); print(m1.empty()); NL;
		print("m1 size : "); print(m1.size()); NL;
		print("m1 max : "); print(m1.max_size()); NL;
	}
	NL;
	print("-------------------------\n");
	print("MODIFIERS\n");
	print("-------------------------\n");
	{
		int arr[] = {1,9,4,6,7,8,2,4,0,10};
		std::map<int, int> m1;
		for ( int n = 0 ; n < 10 ; n++)
			m1[arr[n]];
		print("m1", m1);
		m1.erase(m1.begin());
		print("m1", m1);
		print("erase 4\n"); int res = m1.erase(4);
		print("res : "); print(res); print("\n");
		print("erase 14\n"); res = m1.erase(14);
		print("res : "); print(res); print("\n");
		print("m1", m1);
		print("erase 2-8\n"); m1.erase(m1.find(2), m1.find(8));
		print("m1", m1);
	
		std::map<int, int> m2;
		print("m1", m1);
		print("m2", m2);
		print("m2 swap m1\n"); m2.swap(m1);
		print("m1", m1);
		print("m2", m2);
		print("m2 clear\n"); m2.clear();
		print("m2", m2);
		m2[10] = 100;
		print("m2", m2);
	}

	NL;
	print("-------------------------\n");
	print("MODIFIERS - INSERT\n");
	print("-------------------------\n");
	{
		std::pair<int, int> t1(3, 10);
		std::pair<std::map<int, int>::iterator, bool> res;
		std::map<int, int> m1;
		print("insert (3,10)\n"); res = m1.insert(t1);
		print("res : "); print(res.second); print(" ");
		print_it(res.first, m1.end()); NL;
		print("insert (3,10)\n"); res = m1.insert(t1);
		print("res : "); print(res.second); print(" ");
		print_it(res.first, m1.end()); NL;

		m1[4]; m1[10]; m1[1]; m1[0]; m1[8];
		std::map<int, int>::iterator it;
		std::pair<int, int> t2(2, 22);
		it = m1.insert(m1.find(10), t2);
		print_it(it, m1.end()); NL;
		std::map<int, int> m2;
		print("m1", m1);
		print("m2: insert\n");m2.insert(m1.begin(), m1.end());
		print("m2", m2);
	}
	NL;
	print("-------------------------\n");
	print("OPEATIONS\n");
	print("-------------------------\n");
	{
		std::map<int, int> m1;
		int arr[] = {1,9,4,6,7,8,2,4,0,10};
		for ( int n = 0 ; n < 10 ; n++)
			m1[arr[n]];
		std::map<int, int>::iterator res;
		print("count 4 : "); print(m1.count(4)); print("\n");
		print("find 4\n");res = m1.find(4);
		print("res : "); print_it(res, m1.end()); NL;
		print("count 20 : "); print(m1.count(20)); print("\n");
		print("find 20\n"); res = m1.find(20);
		print("res : "); print_it(res, m1.end()); NL;
	}
	NL;
	print("-------------------------\n");
	print("BOUND\n");
	print("-------------------------\n");
	{	
		std::map<int, int> m1;
		int arr[] = {2,4,6,8,10,12, 14};
		for ( int n = 0 ; n < 7 ; n++)
			m1[arr[n]];
		std::map<int, int>::iterator it;
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
	print("-------------------------\n");
	{
		std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> res;
		std::map<int, int> m1;
		int arr[] = {2,4,6,8,10,12, 14};
		for ( int n = 0 ; n < 7 ; n++)
			m1[arr[n]];
		print("m1", m1);
		print("range(0)");
		res = m1.equal_range(0);
		print_itpair(res, m1.end());
		print("range(2)");
		res = m1.equal_range(2);
		print_itpair(res, m1.end());
		print("range(5)");
		res = m1.equal_range(5);
		print_itpair(res, m1.end());
		print("range(10)");
		res = m1.equal_range(20);
		print_itpair(res, m1.end());
	}
	NL;
	print("-------------------------\n");
	print("RELATIONAL OPERATORS\n");
	print("-------------------------\n");
	{
		std::map<int, int> t1;
		t1[10] = 20;
		std::map<int, int> t2(t1);
		std::map<int, int> t3;
		t3[10] = 30;
		print("t1", t1);
		print("t2", t2);
		print("t3", t3);
		print("t1 == t2  ? ");
		if (t1 == t2) print("True\n") ; else print( "False\n");
		print("t1 == t3  ? ");
		if (t1 == t3) print("True\n") ; else print( "False\n");
		print("t1 <  t3  ? ");
		if (t1 < t3) print("True\n") ; else print( "False\n");
		print("t1 >  t3  ? ");
		if (t1 > t3) print("True\n") ; else print( "False\n");
	}
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
template <typename X, typename T, typename U>
void	print(X const& name, std::map<T, U> const& src)
{
	typename std::map<T, U>::const_iterator it;
	
	std::cout << name << ": ";
	std::cout << "< ";
	for (it = src.begin() ; it != src.end() ; ++it)
	{
		std::cout << (*it).first << " ";
	}
	std::cout << ">\n";
}

template <typename T>
void print(T src)
{
	std::cout << src;
}

template <typename T, typename U>
void	print_itpair(T val, U end)
{
	std::cout << "[ (";
	print_it(val.first, end);
	std::cout << ") , (";
	print_it(val.second, end);
	std::cout << ") )\n";
}

template <typename T>
void	print_it(T const& it, T const& end)
{
	if (it == end)
		std::cout << "end";
	else
		std::cout << (*it).first << " , " << (*it).second;
}

