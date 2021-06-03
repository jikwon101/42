
#ifndef TEST
#include "ft_list.hpp"
#endif

#ifdef TEST
#include <list>
#endif

#include <iostream>
#include <list>
class Test;
struct is_odd
{
	bool operator() (const int& value)
	{
		return ((value % 2) == 1);
	}
};

bool mycomparison(double first, double second);
bool same_integral_part(double first, double second);

void	print(std::string const& src)
{ std::cout << src ; }

void	print(long long const& src)
{ std::cout << src ; }

template <typename T>
void print_info(T const& src);

template <typename T>
void print_type(T);

template <typename T>
void print_list(const ft::list<T>& src);

template <>
void print_list<ft::list<int> >(const ft::list<ft::list<int> >& src );

template <typename T>
void print_it(T const & src);

template <typename T>
void printsize(T src)
{
	std::cout << sizeof(src) << std::endl;
}

int main()
{
	{
		int arr[] = {1,2,3,4,5,6};
		ft::list<int> t1(arr, arr +6);
		ft::list<int>::iterator it1 = t1.end();
		ft::list<int>::reverse_iterator it2(it1);
		for (it2 = t1.rbegin() ; it2 != t1.rend() ; ++it2)
		{
			std::cout << *it2 << " " ;
		}
		std::cout << "\n";
	}
	{
		ft::list<int> t1;					//default
		print_list(t1);
		const ft::list<int> t2(4, 10);		//size
		print_list(t2);
		ft::list<int> t3(t2);				//copy
		print_list(t3);
		t1 = t3;							//operator=
		//t2 = t3;  // error : t2 const x
		print_list(t1);
		int arr[] = {1,2,3,4,5};
		ft::list<int> t4(arr, arr +5);		///range
		print_list(t4);
		std::cout << typeid(t1.get_allocator()).name() << std::endl;
	}
	std::cout << "----------------------------\n";
	{
		int arr[] = {1,2,3,4,5};
		ft::list<int> t1(arr, arr +5);
		const ft::list<int> t2(t1);
		ft::list<int>::iterator it1 = t1.begin();
		print_it(it1);
		ft::list<int>::const_iterator it2 = t1.end();
		ft::list<int>::value_type value1 = t1.front();
		ft::list<int>::value_type value2 = t1.back();
		std::cout << "front : " << value1 << ", back : " << value2 << std::endl;

		ft::list<int>::const_iterator it3 = it1;
		it3 = it1;
		print_it(it3);
		//it1 = it3;		// error : int = const int
		//it1 = t2.begin(); // error : t2 const list
		it2 = t2.begin();
	}
	std::cout << "----------------------------\n";
	{
		ft::list<int> t1;
		ft::list<char> t2(1, 10);
		print("t1 has "); print(t1.size()); print(" elements\n");
		print("t2 has "); print(t2.size()); print(" elements\n");
		print("t1 isEmpty "); print(t1.empty()); print("\n");
		print("t2 isEmpty "); print(t2.empty()); print("\n");
		print("t1<int> max: "); print(t1.max_size()); print("\n");
		print("t2<char> max: "); print(t2.max_size()); print("\n");
	}
	std::cout << "----------------------------\n";
	{

		int arr[] = {1,2,3,4,5};
		ft::list<int> t1;
		ft::list<int> t2(arr, arr + 5);
		print("t1:");print_list(t1);
		print("t1: assign\n"); t1.assign(4, 3);
		print("t1:"); print_list(t1);
		print("t1: assign\n"); t1.assign(t2.begin(), t2.end());
		print("t1:"); print_list(t1);
		print("t1: push_front\n"); t1.push_front(9);
		print("t1:"); print_list(t1);
		print("t1: push_back\n"); t1.push_back(11);
		print("t1:"); print_list(t1);
		print("t1: pop_front\n"); t1.pop_front();
		print("t1:"); print_list(t1);
		print("t1: pop_back\n"); t1.pop_back();
		print("t1:"); print_list(t1);
		print("t1: resize to 3\n"); t1.resize(3);
		print("t1:"); print_list(t1);
		print("t1: resize to 6\n"); t1.resize(6);
		print("t1:"); print_list(t1);
		print("t2:"); print_list(t2);
		print("t1 swap with t2\n"); t1.swap(t2);
		print("t1:"); print_list(t1);
		print("t2:"); print_list(t2);
			}
	std::cout << "----------------------------\n";
	{
		ft::list<int> t1;
		ft::list<int> t2(1,99);
		print("t1:insert begin, 10\n"); t1.insert(t1.begin(), 10);
		print("t1:"); print_list(t1);
		print("t1:insert begin, 3, 4\n"); t1.insert(t1.begin(), 3, 4);
		print("t1:"); print_list(t1);
		print("t2:insert begin, t1.[b, e-1)\n"); t2.insert(t2.begin(), t1.begin(), --t1.end());
		print("t2:"); print_list(t2);
		print("t1 clear\n"); t1.clear();
		print("t1:"); print_list(t1);
		print("t2 erase begin\n"); t2.erase(t2.begin());
		print("t2:"); print_list(t2);
		print("t2 erase end-1\n"); t2.erase(--t2.end());
		print("t2:"); print_list(t2);
		print("t2 erase range\n"); t2.erase(t2.begin(), t2.end());
		print("t2:"); print_list(t2);

	}
	std::cout << "----------------------------\n";
	{
		int arr[] = {1,5,0,9,6,7,6, 13,4,6};
		ft::list<int> t1(arr, arr + 10);
		print("t1:"); print_list(t1);
		print("t1 reverse\n"); t1.reverse();
		print("t1:"); print_list(t1);
		print("t1 sort\n"); t1.sort();
		print("t1:"); print_list(t1);
		print("t1 unique\n"); t1.unique();
		print("t1:"); print_list(t1);
		print("t1 remove\n"); t1.remove(13);
		print("t1:"); print_list(t1);
		print("t1 remove if\n"); t1.remove_if(is_odd());
		print("t1:"); print_list(t1);

	}
	std::cout << "----------------------------\n";
	{
		float arr[] = {2.6, 2.3, 4.1, 2.4, 2.1, 1.8};
		ft::list<float> t1(arr, arr+6);
		print("t1:"); print_list(t1);
		print("t1: sort (comp)\n"); t1.sort(mycomparison);
		print("t1:"); print_list(t1);
		ft::list<float> t2(arr, arr+6);
		print("t2:"); print_list(t2);
		print("t2: unique (pred)\n"); t2.unique(same_integral_part);
		print("t2:"); print_list(t2);
	}
	std::cout << "----------------------------\n";
	{
		int arr1[] = {1,2,3,4,5};
		int arr2[] = {66,77,88,99};
		ft::list<int> t1(arr1, arr1+5);
		ft::list<int> t2(arr2, arr2+4);
		print("t1:"); print_list(t1);
		print("t2:"); print_list(t2);
		print("t1:splice(b,t2)\n"); t1.splice(t1.begin(), t2);
		print("t1:"); print_list(t1);
		print("t2:"); print_list(t2);
		print("t2:splice(b,t1,t1.b)\n"); t2.splice(t2.begin(), t1, t1.begin());
		print("t1:"); print_list(t1);
		print("t2:"); print_list(t2);
		print("t2:splice(b,t1,t1.b, t1.e)\n"); t2.splice(t2.begin(), t1, t1.begin(), t1.end());
		print("t1:"); print_list(t1);
		print("t2:"); print_list(t2);
	}
	std::cout << "----------------------------\n";
	{
		int arr1[] = {1, 3, 5, 9, 11};
		int arr2[] = {2, 4, 7,8, 9};
		ft::list<int> t1(arr1, arr1+5);
		ft::list<int> t2(arr2, arr2+5);
		print("t1:"); print_list(t1);
		print("t2:"); print_list(t2);
		print("t1: merge(t2)\n"); t1.merge(t2);
		print("t1:"); print_list(t1);
		print("t2:"); print_list(t2);

		float arr3[] = {2.1, 2.3, 3.2};
		float arr4[] = {1.7, 2.2, 2.5, 2.7};
		ft::list<float> t3(arr3, arr3 +3);
		ft::list<float> t4(arr4, arr4 + 4);
		print("t3:"); print_list(t3);
		print("t4:"); print_list(t4);
		print("t3: merge(t4, mycomparison)\n"); t3.merge(t4, mycomparison);
		print("t3:\n"); print_list(t3);
		print("t4:"); print_list(t4);
	}
	std::cout << "----------------------------\n";
	{
		ft::list<int> t1;
		ft::list<int> t2;
		t1.push_back(3);
		t2.push_back(1);
		t2.push_back(3);
		print("t1 : "); print_list(t1);
		print("t2 : ");print_list(t2);
		print("t1 == t2  ? ");
		if (t1 == t2) print("true\n"); else print("false\n");
		print("t1 < t2  ? ");
		if (t1 < t2) print("true\n"); else print("false\n");
		print("t1 >= t2  ? ");
		if (t1 >= t2) print("true\n"); else print("false\n");
	}
}




template <typename T>
void print_info(T const& src)
{
	std::cout << "list has  [" << src.size() << "]\n";
}

template <typename T>
void print_type(T)
{
	std::cout << typeid(T).name() << std::endl;
}

template <typename T>
void print_list(const ft::list<T>& src)
{
	typename ft::list<T>::const_iterator it;
	
	std::cout << "[ ";
	for (it = src.begin() ; it != src.end() ; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "]" << std::endl;
}

template <>
void print_list<ft::list<int> >(const ft::list<ft::list<int> >& src )
{
	(void)src;
	print("need to write\n");
}

template <typename T>
void print_it(T const & src)
{
	std::cout << "It indicates : " << *src << std::endl;
}


bool mycomparison(double first, double second)
{
	return (int(first) < int(second));
}
bool same_integral_part(double first, double second)
{
	return (int(first) == int(second));
}

class Test
{
public:
	int nbr1;
	Test()
	{
		nbr1 = 100;
		std::cout << "construct...\n";
	}
	Test(int n)
	{	
		nbr1 = n;
		std::cout << "construct with number....\n";
	}
	Test(const Test& src)
	{
		nbr1 =src.nbr1;
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
	return (lhs.nbr1 == rhs.nbr1);
}
bool operator!=(Test const& lhs, Test const& rhs)
{
	return (lhs.nbr1 != rhs.nbr1);
}
std::ostream& operator<<(std::ostream& os, const Test& src)
{
	os << src.nbr1;
	return (os);
}

