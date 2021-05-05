#ifndef FUNCTION_HPP
# define FUNCTION_HPP

#include "./iterator.hpp"
#include "./traits.hpp"

namespace ft
{
	/* reference rvalue = c++11 */
	/*
	template <typename T>
	struct remove_reference
	{
		typedef T type;
	};
	template <typename T>
	struct remove_reference<T&>
	{
		typedef T type;
	};
	template <typename T>
	struct remove reference<T&&>
	{
		typedef T type;
	};

	template <typename T>
	typename ft::remove_reference<T>::type&& move(T&& t)
	{
		return (static_cast<typename ft::remove_reference<T>::type&&>(t));
	}
	template <typename InputIt, typename OutputIt>
	OutputIt move(InputIt first, InputIt last, OutputIt other)
	{
		while (first != last)
		{
			*other = ft::move(*first);
			++first;
			++other
		}
		return (other);
	}
	*/
	template <typename T>
	T	max(T a, T b)
	{
		if (a > b)
			return (a);
		return (b);
	}

	template <typename T>
	T	min(T a, T b)
	{
		if (a < b)
			return (a);
		return (b);
	}
	template <typename _Iter>
	typename iterator_traits<_Iter>::iterator_category			iterCategory(const _Iter&)
	{
		typename iterator_traits<_Iter>::iterator_categoty _category;
		return (_category);
	}

	template <typename InputIterator>
	typename iterator_traits<InputIterator>::difference_type	distance(InputIterator first, InputIterator last)
	{
	
		if (ft::is_same_category<InputIterator, ft::random_access_iterator_tag>::value)
		{
			return (last - first);
		}
		typename iterator_traits<InputIterator>::difference_type diff;
		diff = 0;
		while (first != last)
		{
			++diff;
			++first;
		}
		return (diff);
	}


}
#endif
