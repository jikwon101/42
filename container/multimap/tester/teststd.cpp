#include <iostream>
#ifndef TEST
#include "ft_multimap.hpp"
#include "../map/ft_map.hpp"
#endif
#ifdef TEST
#include <map>
#endif

# define NL print("\n")

template <typename X, typename T, typename U>
void	print(X name , std::multimap<T, U> const& src);
template <typename T>
void	print(T src);
template <typename T, typename U>
void	print_itpair(T val, U end);

void print_it(std::multimap<int, int>::iterator const& it, std::multimap<int, int>::iterator const& end) ;

int main()
{
	print("-----------------------\n");
	print("CONSTRUCTOR/ITERATOR\n");
	print("-----------------------\n");
	{
		std::pair<int, int> test[5];
		for (int i = 0 ; i < 5 ; i++)
			test[i].first = (i % 3);
		for (int i = 0; i < 5 ; i++)
			test[i].second = i;
		std::multimap<int, int> m1(test, test+5);
		print("m1", m1);
		std::multimap<int, int> m2(m1);
		std::multimap<int, int> m3(m1.begin(), m1.begin());
		std::multimap<int, int> m4(m1.begin(), m1.end());
		std::multimap<int, int> m5;
		m5 = m1;
		print("m2", m2);
		print("m3", m3);
		print("m4", m4);
		print("m5", m5);
		std::cout << "m5 reverse: ";
		for (std::multimap<int, int>::reverse_iterator it = m5.rbegin() ; it != m5.rend() ; ++it)
		{
			print("( ");
			print((*it).first);
			print(" , ");
			print((*it).second);
			print(" )");
			NL;
		}
		std::multimap<int, int>::iterator it = m1.begin();
		std::multimap<int, int>::const_iterator cit(it);
		cit = it;
		if (cit == it) print("cit == it\n"); else print("cit != it\n");
		std::map<int, int> t1;
		t1[3] = 30;
		t1[2] = 20;
		t1[4] = 40;
		std::multimap<int, int> t2;
		t2.insert(t1.begin(), t1.end());
		print("t2", t2);
	}
	NL;
	print("-----------------------\n");
	print("REALATIONAL OPERATORS\n");
	print("-----------------------\n");
	{
		std::pair<int, int> k1(1, 0);
		std::pair<int, int> k2(1, 1);
		std::multimap<int, int> m1;
		m1.insert(k2);
		std::multimap<int, int> m2;
		m2.insert(m2.find(1), k1);
		m2.insert(m2.find(1), k1);
		print("m1", m1);
		print("m2", m2);
		print("m1 <  m2  ? ");
		if (m1 < m2) print("True\n"); else print("False\n");
		print("m1 == m2 ? ");
		if (m1 == m2) print("True\n"); else print("False\n");
		print("m1 >  m2  ? ");
		if (m1 > m2) print("True\n"); else print("False\n");
		print("m1 != m2  ? ");
		if (m1 != m2) print("True\n"); else print("False\n");
	}
	NL;
	print("-----------------------\n");
	print("CAPACITY\n");
	print("-----------------------\n");
	{
		std::multimap<int, char> m1;
		print("m1", m1);
		print("m1 is empty : "); print(m1.empty()); NL;
		print("m1 size : "); print(m1.size()); NL;
		m1.insert(std::make_pair<int, char>(3, 'a'));
		print("m1", m1);
		print("m1 is empty : "); print(m1.empty()); NL;
		print("m1 size : "); print(m1.size()); NL;
		print("m1 max : "); print(m1.max_size()); NL;
	}
	NL;
	print("-----------------------\n");
	print("MODIFIERS\n");
	print("-----------------------\n");
	{
		std::pair<int, int> test[5];
		for (int i = 0 ; i < 5 ; i++)
			test[i].first = (i % 3);
		for (int i = 0; i < 5 ; i++)
			test[i].second = i;
		std::multimap<int, int> m1(test, test + 5);
		print("m1", m1);
		print("m1 erase begin\n");	m1.erase(m1.begin());
		print("m1", m1);
		print("m1 erase 1\n"); int res = m1.erase(1);
		print("res : "); print(res); print("\n");
		print("m1 erase 14\n"); res = m1.erase(14);
		print("res : "); print(res); print("\n");
		std::multimap<int, int> m3(test, test + 5);
		std::multimap<int, int>::iterator it1 = m3.find(1);
		std::multimap<int, int>::iterator it2 = it1++;
		print("m3", m3);
		print("m3 erase\n"); m3.erase(it2, it1);
		print("m3", m3);
		std::multimap<int, int> m2;
		print("m2", m2);
		print("m2 swap m3\n"); m2.swap(m3);
		print("m2 swap m3\n"); m2.swap(m3);
		print("m2", m2);
		print("m3", m3);
		print("m2 clear\n"); m2.clear();
		print("m2", m2);
		print("m3 clear\n"); m3.clear();
		print("m3", m3);
	}
	NL;
	print("-----------------------\n");
	print("OPEARTION\n");
	print("-----------------------\n");
	{	
		std::pair<int, int> test[10];
		for (int i = 0 ; i < 10 ; i++)
			test[i].first = i % 4;
		for (int i = 0; i < 10 ; i++)
			test[i].second = i ;
		std::multimap<int, int> m1(test, test+10);
		std::multimap<int, int>::iterator res;
		print("m1", m1);
		print("count 3 : "); print(m1.count(3)); NL;
		print("find 3\n");res = m1.find(3);
		print("res : "); print_it(res, m1.end()); NL;
		print("count 20 : "); print(m1.count(20));NL;
		print("find 20\n"); res = m1.find(20);
		print("res : "); print_it(res, m1.end()); NL;
	}
	NL;
	print("-----------------------\n");
	print("OPERATIONS-BOUND\n");
	print("-----------------------\n");
	{
		std::pair<int, int> test[10];
		for (int i = 0 ; i < 10 ; i++)
			test[i].first = (i % 4 + 1);
		for (int i = 0; i < 10 ; i++)
			test[i].second = i;
		std::multimap<int, int> m1(test, test+10);
		std::multimap<int, int> m2(m1);
		std::multimap<int, int>::iterator i;
		print("m1", m1);
		print("m2", m2);
		for (int n = 0; n < 6 ; n++)
		{
			print(n); print(" ");
			print("[");
			i = m1.lower_bound(n);
			print_it(i, m1.end());
			print(" , ");
			i = m1.upper_bound(n);
			print_it(i, m1.end());
			print(")\n");
			print("count: "); print(m1.count(n)); NL;
		}
	}
	NL;
	print("-----------------------\n");
	print("OPERATIONS-BOUND2\n");
	print("-----------------------\n");
	{
		std::pair<int, int> k1(1, 0);
		std::pair<int, int> k2(1, 0);
		std::pair<int, int> k3(1, 1);
		std::pair<int, int> k4(1, 3);
		std::pair<int, int> k5(3, 4);
		std::pair<int, int> k6(0, 4);

		std::multimap<int, int> m1;
		m1.insert(k1);
		std::multimap<int, int>::iterator i = m1.find(2);
		m1.insert(i, k2);
		m1.insert(k3);
		m1.insert(k4);
		m1.insert(k5);
		m1.insert(m1.find(3), k6);
		print("m1", m1);
		for (int n = 0 ; n < 5 ; n++)
		{
			print(n); print(" ");
			print("[");
			i = m1.lower_bound(n);
			print_it(i, m1.end());
			print(" , ");
			i = m1.upper_bound(n);
			print_it(i, m1.end());
			print(")\n");
		}

		std::multimap<int, int> m2;
		std::multimap<int, int>::iterator it;
		print("m2", m2);
		it = m2.lower_bound(1);
		print_it(it, m2.end()); NL;
		it = m2.upper_bound(1);
		print_it(it, m2.end()); NL;
	}
	print("-----------------------\n");
	print("INSERT-BOUND\n");
	print("-----------------------\n");
	{
		std::pair<int, int> k1(1, 0);
		std::pair<int, int> k2(1, 10);
		std::pair<int, int> k3(1, 20);
		std::pair<int, int> k4(2, 0);
		std::pair<int, int> k5(1, 8);
		std::multimap<int, int> m1;
		m1.insert(k1);
		std::multimap<int, int>::iterator i = m1.find(1);
		m1.insert(i, k2);
		m1.insert(k3);
		m1.insert(k4);
		print("m1", m1);
		i = m1.find(1);
		++i;
		print_it(i, m1.end()); NL;
		m1.insert(i, k5);
		print("m1", m1);
		i = m1.find(1);
		print_it(i, m1.end()); NL;
		i = m1.lower_bound(3);
		print_it(i, m1.end()); NL;
		i = m1.upper_bound(3);
		print_it(i, m1.end()); NL;
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
void	print(X name, std::multimap<T, U> const& src)
{
	int cnt = 0;
	typename std::multimap<T, U>::const_iterator it;
	
	std::cout << name << ": ";
	for (it = src.begin() ; it != src.end() ; ++it)
	{
		std::cout << "( " << (*it).first << " , " << (*it).second << " )\n";
		cnt++;
	}
	if (!cnt)
		std::cout << "EMPTY\n";
	return ;
}

template <typename T>
void print(T src)
{
	std::cout << src;
}
void print_it(std::multimap<int, int>::iterator const& it, std::multimap<int, int>::iterator const& _end) 
{
	if (it != _end)
	{	
		print((*it).first); 
		print(","); 
		print((*it).second);
	}	
	else
		print("end");
}

template <typename T, typename U>
void	print_itpair(T val, U end)
{
	print("( ");
	if (val.first == end)
		print("end");
	else
		print((*(val.first)).first);
	print(" , ");
	if (val.second == end)
		print("end");
	else
		print((*(val.second)).first);
	std::cout << " )\n";
}
