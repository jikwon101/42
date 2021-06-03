/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:46:00 by jikwon            #+#    #+#             */
/*   Updated: 2021/06/03 11:47:51 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST
#include "ft_vector.hpp"
#endif

#ifdef TEST
#include <vector>
#endif

#include <iostream>

template <typename T>
void print_info(T const& src);

template <typename T>
void print_type(T);

void print(std::string const& src);

template <typename T>
void print_vector(const std::vector<T>& src);

template <>
void print_vector<std::vector<int> >(const std::vector<std::vector<int> >& src );

template <typename T>
void print_it(T const & src);

int main()
{
	print("---------------------");
	print("Constructor\n");
	{
		std::vector<int> v1;			// default
		std::vector<int> v2(3);		// fill
		std::vector<int> v3(3, 5);	// fill
		int arr[] = {0,1,2,3,4};
		std::vector<int> v4(arr, arr + 5); 			//range pointer;
		std::vector<int> v5(v2.begin(), v2.end()); // range iterator;
		print_vector(v1);
		print_vector(v2);
		print_vector(v3);
		print_vector(v4);
		print_vector(v5);
		std::vector<int> v6 = v4;	//copy
		print_vector(v6);
		v1 = v3;					//operator=
		print_vector(v1);
		const std::vector<int> v7 = v2;	//const vector copy from non-const
		print_vector(v7);
		v2 = v7;
		char arr2[] = {'a', 'b', 'c'};
		std::vector<int> v8(arr2, arr2 + 3);		//range pointer
		print_vector(v8);
	}
	print("---------------------");
	print("Iterator\n");
	{
		int arr[] = {-1,0,1,2,3};
		std::vector<int> v1(arr, arr + 5);
		const std::vector<int> v2(v1);
		print_vector(v1);

		std::vector<int>::iterator it1;
		std::vector<int>::const_iterator it2;
		//std::vector<int>::iterator it3(it2);	 	// error : it copy from const-it
		std::vector<int>::const_iterator it3(it1);
		//it1 = it2;	// error : it = const-it
		it2 = it1;	// const-it = it

		it1 = v1.begin();
		//it1 = v2.begin();  // error : it <= const vector
		print_it(it1);

		std::vector<int>::reverse_iterator rit1;
		rit1 = v1.rbegin();
		if (rit1.base() == v1.end())
			std::cout << "rbegin() == end()" << std::endl;
		print_it(rit1);
		++rit1;
		print_it(rit1);
		rit1 = v1.rend();
		if (rit1.base() == v1.begin())
			std::cout << "rend() == begin()" << std::endl;
		//print_it(rit1);		// undefiend behavior
	}
	print("---------------------");
	print("Element Access : at, [], front, back\n");
	{
		int arr[] = {-1,0,1,2,3};
		std::vector<int> v1(arr, arr + 5);
		print_vector(v1);
		std::cout << v1[0] << " ";
		v1[0] = 3;
		std::cout << "->  " << v1[0] << std::endl;
		std::cout << v1.at(4) << " ";
		v1.at(4) = 10;
		std::cout << "-> " << v1.at(4) << std::endl;
		std::cout << "front : " << v1.front() << ", back : " << v1.back() << std::endl;
		v1.front() = -1;
		v1.back() = 3;
		std::cout << "front : " << v1.front() << ", back : " << v1.back() << std::endl;

		const std::vector<int> v2(arr, arr + 3);
		print_vector(v2);
		for (std::vector<int>::size_type i = 0; i < v2.size() ; i++)
		{
			std::cout << v2[i] << " & " << v2.at(i) << std::endl;
			//v2[i] = 3;		// error : const vector
			//v2.at(i) = 5;		// error : const vector
		}
		std::cout << "front : " << v2.front() << ", back : " << v2.back() << std::endl;
	}
	print("---------------------");
	print("Cap 1 : size, capacity, max_size, empty\n");
	{
		int arr[] = {97, 98, 99, 100};
		std::vector<int> v1(arr, arr + 4);
		std::vector<char> v2(arr, arr + 4);
		print_vector(v1);
		std::cout << "size : " << v1.size()  << std::endl;
		std::cout << "capacity : " << v1.capacity()  << std::endl;
		std::cout << "max_size : " << v1.max_size()  << std::endl;
		std::cout << "max_size : " << v2.max_size()  << std::endl;
		std::cout << "Is v1 empty ? : " << v1.empty() << std::endl;
		std::vector<int> v3;
		std::cout << "Is v3 empty ? : " << v3.empty() << std::endl;
		print("---------------------");
		print("Cap 2 : reserve, resize\n");
		v3.reserve(2);
		std::cout << "v3 : reserve (2)\n";
		print_info(v3);
		v3.reserve(1);
		std::cout << "v3 : reserve (1)\n";	//Do nothing
		print_info(v3);
		print_info(v1);
		print_vector(v1);
		v1.resize(3);
		std::cout << "v1 : resize (3)\n";
		print_info(v1);
		print_vector(v1);
		v1.resize(5);
		std::cout << "v1 : resize (5)\n";
		print_info(v1);
		print_vector(v1);

	}
	print("---------------------");
	print("Mod1 : erase, clear, swap, push_back, pop_back\n");
	{
		int arr1[] = {1,2,3,4,5,6};
		std::vector<int> v1(arr1, arr1 + 6);
		print_vector(v1);
		print_it(v1.erase(v1.begin(), v1.begin() + 1));		// erase
		v1.erase(v1.begin());
		print_vector(v1);
		v1.clear();					//clear
		print_info(v1);
	
		std::vector<int> v3(3,3);
		std::vector<int> v4(4,4);
		print_vector(v3);
		print_vector(v4);
		v3.swap(v4);				//swap
		print("v3 : swap (v4)");
		print_vector(v3);

		std::vector<std::vector<int> > v2(1, v3);
		v2.push_back(std::vector<int>(arr1, arr1 + 2));		// push_back
		v2.push_back(std::vector<int>(arr1 + 3, arr1 + 6));
		print_vector(v2);
		v2.pop_back();				//pop_back
		v2.pop_back();		
		print_vector(v2);
	}	
	print("---------------------");
	print("Mod 2 : insert, assign\n");
	{
		int arr[] = {1,2,3,4,5};
		std::vector<std::vector<int> > v1;
		std::vector<std::vector<int> > v2;
		std::vector<int> base1(1,1);
		std::vector<int> base2(2, 2);
		std::vector<int> base3(arr, arr + 4);
		
		v1.insert(v1.begin(), base1);
		v1.insert(v1.end(), 2, base2);
		print_info(v1);
		print_vector(v1);
		print_info(v2);
		v2.insert(v2.begin(), v1.begin(), v1.begin() + 1);
		print("v2 : insert");
		print_info(v2);
		print_vector(v2);
		v2.insert(v2.begin() + 1, v1.begin() + 1, v1.end());
		print("v2 : insert");
		print_vector(v2);

		std::vector<std::vector<int> > v3;
		print_info(v3);
		v3.reserve(4);
		print("v3 : reserve (4)");
		v3.assign(v2.begin(),v2.begin() + 2);
		print("v3 : assign");
		print_vector(v3);
		v3.resize(0);
		print("v3 : resize (0)");
		v3.assign(v1.begin(), v1.begin() + 3);
		print("v3 : assign");
		print_vector(v3);
	}
	print("---------------------");
	{
		int arr[] = {1,2,3,4,5};
		int rarr[] = {5,4,3,2,1};
		std::vector<int> v1(arr, arr + 4);
		std::vector<int> v2(arr, arr + 4);
		std::vector<int> v3(rarr, rarr + 2);
		print("v1: ");print_vector(v1);
		print("v2: ");print_vector(v2);
		print("v3: ");print_vector(v3);
		print("v1 == v2 ?  ");
		if (v1 == v2) print("true"); else print("false");
		print("v1 <= v2 ?  ");
		if (v1 <= v2) print("true"); else print("false");
		print("v1 <= v3 ?  ");
		if (v1 <= v3) print("true"); else print("false");
		print("v1 > v3 ?  ");
		if (v1 > v3) print("true"); else print("false");
	}
	print("---------------------");
	print("RETURN");
}

template <typename T>
void print_info(T const& src)
{
	std::cout << "size [" << src.size() << "], cap [" << src.capacity() << "]\n";
}

template <typename T>
void print_type(T)
{
	std::cout << typeid(T).name() << std::endl;
}

void print(std::string const& src)
{
	std::cout << src << std::endl;
}

template <typename T>
void print_vector(const std::vector<T>& src)
{
	typename std::vector<T>::const_iterator it;
	
	std::cout << "[ ";
	for (it = src.begin() ; it != src.end() ; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "]" << std::endl;
}

template <>
void print_vector<std::vector<int> >(const std::vector<std::vector<int> >& src )
{
	for (size_t i = 0 ; i < src.size() ; i++)
	{
		std::cout << " + " ;
		print_vector(src[i]);
	}
}


template <typename T>
void print_it(T const & src)
{
	std::cout << "It contains : " << *src << std::endl;
}

