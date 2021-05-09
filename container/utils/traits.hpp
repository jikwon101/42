#ifndef TRAITS_HPP
# define TRAITS_HPP

#include "../iterator/iterator.hpp"

namespace ft
{
	template <typename T, T v>
	struct	integral_constant 
	{
		typedef	T	value_type;
		static const T value = v;
	};

	typedef ft::integral_constant<bool, true>	true_type;
	typedef ft::integral_constant<bool, false>	false_type;

	/*
	** is_same 
	*/
	template <typename T, typename U>
	struct	is_same : ft::false_type
	{
		//static const bool value = false;
	};

	template <typename T>
	struct	is_same<T, T> : ft::true_type
	{
		//static const bool value = true;
	};

	/*
	** is_same_category
	*/
	template <typename T, typename U>
	struct	is_same_category
	{
		static const bool value = ft::is_same<typename iterator_traits<T>::iterator_category, U>::value;
	};

	/*
	** is_iterator
	*/
	template <bool B, typename U>
	struct	is_iterator	{};

	template <typename U>
	struct	is_iterator<true, U>
	{
		typedef typename ft::iterator_traits<U>::value_type type;
	};

	/*
	** enable_if
	*/
	template <bool B, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	/*
	** is_const
	*/
	template <typename T>
	struct is_const : ft::false_type
	{
		//static const bool value = false;
	};

	template <typename T>
	struct is_const<const T> : ft::true_type
	{
		//static const bool value = true;
	};

	/*
	** is_arithmetic
	*/
	template <typename T>
	struct is_arithmetic : ft::false_type
	{
		//static const bool value = false;
	};

	template <>
	struct is_arithmetic<bool> : ft::true_type
	{
	//	static const bool value = true;
	};
	
	template <>
	struct is_arithmetic<char> : ft::true_type
	{
	//	static const bool value = true;
	};
	
	template <>
	struct is_arithmetic<signed char> : ft::true_type
	{
	//	static const bool value = true;
	};
	
	template <>
	struct is_arithmetic<unsigned char> : ft::true_type
	{
	//	static const bool value = true;
	};

	template <>
	struct is_arithmetic<wchar_t> : ft::true_type
	{
	//	static const bool value = true;
	};

	template <>
	struct is_arithmetic<short> : ft::true_type
	{
		//static const bool value = true;
	};

	template <>
	struct is_arithmetic<unsigned short> : ft::true_type
	{
		//static const bool value = true;
	};

	template <>
	struct is_arithmetic<int> : ft::true_type
	{
	//	static const bool value = true;
	};

	template <>
	struct is_arithmetic<unsigned int> : ft::true_type
	{
		//static const bool value = true;
	};

	template <>
	struct is_arithmetic<long> : ft::true_type
	{
		//static const bool value = true;
	};

	template <>
	struct is_arithmetic<unsigned long> : ft::true_type
	{
		//static const bool value = true;
	};
			
	template <>
	struct is_arithmetic<float> : ft::true_type
	{
		//static const bool value = true;
	};

	template <>
	struct is_arithmetic<double> : ft::true_type
	{
		//static const bool value = true;
	};

	template <>
	struct is_arithmetic<long double> : ft::true_type
	{
		//static const bool value = true;
	};

}
#endif
