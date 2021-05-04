/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:46:00 by jikwon            #+#    #+#             */
/*   Updated: 2021/05/05 00:10:25 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>

# define CL "\033[1m\033[36m"
# define RS "\033[0m"

template <typename T>
void print_type(T)
{
	std::cout << typeid(T).name() << std::endl;
}

void print(std::string const& src)
{
	//std::cout << CL << src << RS << std::endl;
	std::cout << src << std::endl;
}

template <typename T>
void print_vector(T& src)
{
	typename T::const_iterator it;

	std::cout << "< ";
	for (it = src.begin() ; it != src.end() ; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << ">" << std::endl;
}

template <typename T>
void print_it(T const & src)
{
	std::cout << "It contains : " << *src << std::endl;
}

int main()
{
	print("---------------------");
	print("Constructor\n");
	{
		std::vector<int> v1;			// default
		std::vector<int> v2(3);		// fill
		std::vector<int> v3(3, 5);	// fill
		int arr[] = {0,1,2,3,4};
		std::vector<int> v4(arr, arr + 5); //range pointer;
		std::vector<int> v5(v2.begin(), v2.end()); // range iterator;
		print_vector(v1);
		print_vector(v2);
		print_vector(v3);
		print_vector(v4);
		print_vector(v5);
		std::cout << "cap : " << v4.capacity() << ", size : " << v4.size() << std::endl;
		std::vector<int> v6 = v4;	//copy
		print_vector(v6);
		//v1 = v3;
		//print_vector(v1);
		const std::vector<int> v7 = v2;	//const vector copy from non-const
		print_vector(v7);
		v2 = v7;
		char arr2[] = {'a', 'b', 'c'};
		std::vector<int> v8(arr2, arr2 + 3);
		print_vector(v8);
	}
	/*
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
	print("Element Access\n");
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
		for (int i = 0; i < v2.size() ; i++)
		{
			std::cout << v2[i] << " & " << v2.at(i) << std::endl;
			//v2[i] = 3;		// error : const vector
			//v2.at(i) = 5;		// error : const vector
		}
		std::cout << "front : " << v2.front() << ", back : " << v2.back() << std::endl;
	}
	
	print("---------------------");
	print("Capacity\n");
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
		std::vector<int> v4(arr, arr +4);
		std::cout << "<><><><><><>><>\n";
		std::vector<std::vector<int> > v5(1);
		std::cout << "<><><><><><>><>\n";
	}
	*/
	print("---------------------");
	print("Mo");
	{
		int arr1[] = {1,2,3,4};
		std::vector<int> v1(arr1, arr1 + 4);
		print_vector(v1);
		v1.erase(v1.begin(), v1.begin() + 1);
		print_vector(v1);
		std::vector<std::vector<int> > v2(2, v1);
	}
	print("---------------------");
	print("---------------------");
	print("---------------------");
	print("RETURN");
}

