#ifndef FUNCTION_HPP
# define FUNCTION_HPP

#include "../iterator/iterator.hpp"
#include "./traits.hpp"
#include "./pair.hpp"

namespace ft
{
	template <typename Arg1, typename Arg2, class Result>
	struct binary_function
	{
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template <typename T>
	struct less : binary_function<T, T, bool>
	{

		bool operator() (const T& x, const T& y)
		{
			return (x < y);
		}
	};
	template <typename T, typename U>
	ft::pair<T, U>	make_pair(T x, U y)
	{
		return (ft::pair<T, U>(x, y));
	}

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
	typename iterator_traits<_Iter>::iterator_category	iterCategory(const _Iter&)
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
