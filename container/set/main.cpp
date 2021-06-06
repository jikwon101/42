#include <iostream>
#ifndef TEST
#include "ft_set.hpp"
#endif
#ifdef TEST
#include <set>
#endif

template <typename T>
void	print(ft::set<T> const& src);
template <typename T, typename U>
void	print_itpair(T val, U end);
template <typename T>
void	print(T src);

int main()
{
	{
		int arr[] = {2,4,6,8,10,12,14};
	
		ft::set<int> m1;
		m1.insert(arr, arr+7);
		print("m1 : "); print(m1);
		ft::set<int> m2(m1);
		ft::set<int> m3(m1.begin(), m1.begin());
		ft::set<int> m4(m1.begin(), m1.end());
		ft::set<int> m5;
		m5 = m1;
		print("m2 : "); print(m2);
		print("m3 : "); print(m3);
		print("m4 : "); print(m4);
		print("m5 : "); print(m5);
		std::cout << "m5 reverse print : \n";
		for (ft::set<int>::reverse_iterator it = m5.rbegin() ; it != m5.rend() ; ++it)
		{
			std::cout << (*it) << " ";
		}
		std::cout << "\n";
	}
	print("-------------------------\n");
	{
		ft::set<int> m1;
		print("m1 is empty : "); print(m1.empty()); print("\n");
		print("m1 size : "); print(m1.size()); print("\n");
		m1.insert(10);
		m1.insert(20);
		print(m1);
		print("m1 is empty : "); print(m1.empty()); print("\n");
		print("m1 size : "); print(m1.size()); print("\n");
		print("m1 max : "); print(m1.max_size()); print("\n");
	}
	print("-------------------------\n");
	{
		ft::pair<ft::set<int>::iterator, bool> res;
		ft::set<int> m1;
		print("insert 10\n"); res = m1.insert(10);
		std::cout << "res : " << res.second << "\n";
		print("insert 10\n"); res = m1.insert(10);
		std::cout << "res : " << res.second << "\n";
		int arr[] = {4, 10 , 1, 0, 8};
		m1.insert(arr, arr + 5);
		ft::set<int>::iterator it;
		it = m1.insert(m1.find(10), 2);
		print("res : ");print(*it);print("\n");
		ft::set<int> m2;
		print("m1"); print(m1);
		print("m2: insert\n");m2.insert(m1.begin(), m1.end());
		print("m2"); print(m2);
	}
	print("-------------------------\n");
	{
		int arr[] = {1,9,4,6,7,8,2,4,0,10};
		ft::set<int> m1;
		m1.insert(arr, arr + 10);
		print(m1);
		m1.erase(m1.begin());
		print(m1);
		int res = m1.erase(4);
		print("res : "); print(res); print("\n");
		res = m1.erase(14);
		print("res : "); print(res); print("\n");
		print(m1);
		m1.erase(m1.find(2), m1.find(8));
		print(m1);
	
		ft::set<int> m2;
		print("m1: "); print(m1);
		print("m2: "); print(m2);
		print("m2 swap m1\n"); m2.swap(m1);
		print("m1: "); print(m1);
		print("m2: "); print(m2);
		print("m2 clear\n"); m2.clear();
		print("m2: "); print(m2);
	}
	print("-------------------------\n");
	{
		ft::set<int> m1;
		int arr[] = {1,9,4,6,7,8,2,4,0,10};
		m1.insert(arr, arr + 10);
		ft::set<int>::iterator res;
		print("count 4 : "); print(m1.count(4)); print("\n");
		print("find 4\n");res = m1.find(4);
		print("res : "); print((*res)); print("\n");
	
		print("count 20 : "); print(m1.count(20)); print("\n");
		print("find 20\n"); res = m1.find(20);
		if (res == m1.end())
			print("res is pointing end\n");
	}
	print("-------------------------\n");
	{	
		ft::set<int> m1;
		int arr[] = {2,4,6,8,10,12, 14};
		m1.insert(arr, arr + 7);
		ft::set<int>::iterator it;
		print(m1);
		print("lower(0) :"); it = m1.lower_bound(0);
		if (it != m1.end())
		{	print((*it)); print("\n");}
		else
			print("end\n");
		print("lower(2) :"); it = m1.lower_bound(2);
		if (it != m1.end())
		{	print((*it)); print("\n");}
		else
			print("end\n");
		print("lower(5) :"); it = m1.lower_bound(5);
		if (it != m1.end())
		{	print((*it)); print("\n");}
		else
			print("end\n");
		print("lower(20) :"); it = m1.lower_bound(20);
		if (it != m1.end())
		{	print((*it)); print("\n");}
		else
			print("end\n");
	}
	print("-------------------------\n");
	{	
		ft::set<int> m1;
		int arr[] = {2,4,6,8,10,12, 14};
		m1.insert(arr, arr + 7);
		ft::set<int>::iterator it;
		print(m1);
		print("upper(0) :"); it = m1.upper_bound(0);
		if (it != m1.end())
		{	print(*it); print("\n");}
		else
			print("end\n");
		print("upper(2) :"); it = m1.upper_bound(2);
		if (it != m1.end())
		{	print((*it)); print("\n");}
		else
			print("end\n");
		print("upper(5) :"); it = m1.upper_bound(5);
		if (it != m1.end())
		{	print((*it)); print("\n");}
		else
			print("end\n");
		print("upper(20) :"); it = m1.upper_bound(20);
		if (it != m1.end())
		{	print((*it)); print("\n");}
		else
			print("end\n");
	}
	print("-------------------------\n");
	{
		ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> res;
		ft::set<int> m1;
		int arr[] = {2,4,6,8,10,12, 14};
		m1.insert(arr, arr + 7);
		print("m1 :"); print(m1);
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
	std::cout << "-------------\n";
	{
		ft::set<int> t1;
		t1.insert(10);
		ft::set<int> t2(t1);
		ft::set<int> t3;
		t3.insert(30);
		print("t1 : "); print(t1);
		print("t2 : "); print(t2);
		print("t3 : "); print(t3);
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


template <typename T>
void	print(ft::set<T> const& src)
{
	typename ft::set<T>::const_iterator it;
	
	std::cout << "< ";
	for (it = src.begin() ; it != src.end() ; ++it)
	{
		std::cout << (*it) << " ";
	}
	std::cout << ">\n";
}


template <typename T, typename U>
void	print_itpair(T val, U end)
{
	print("( ");
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

