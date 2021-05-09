#ifndef FUNCTION_HPP
# define FUNCTION_HPP

#include "../iterator/iterator.hpp"
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
	struct remove_const
	{
		typedef T type;
	};
	template <typename T>
	struct remove_const<const T>
	{
		typedef T type;
	};

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

	template <typename It>
	typename ft::iterator_traits<It>::difference_type do_distance(It first, It last, ft::random_access_iterator_tag)
	{
		return (last - first);
	}
	template <typename It>
	typename ft::iterator_traits<It>::difference_type do_distance(It first, It last, ft::input_iterator_tag)
	{
		typename ft::iterator_traits<It>::difference_type result;

		result = 0;
		while (first != last)
		{
			++first;
			++result;
		}
		return (result);
	}

	template <typename It>
	typename ft::iterator_traits<It>::difference_type	distance(It first, It last)
	{
		return (do_distance(first, last, typename ft::iterator_traits<It>::iterator_category()));
	}


}
#endif
