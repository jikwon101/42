#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iter_category.hpp"

namespace ft
{
	
	template <typename Category, typename T, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T& >
	struct iterator
	{
		typedef T			value_type;
		typedef Category	iterator_category;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};

	// 컴파일 도중에 주어진 타입의 정보를 얻을 수 있게 하는 객체
	template <typename Iterator>
	struct iterator_traits	
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <typename T>
	struct iterator_traits<T *>
	{
		typedef ptrdiff_t 					difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};
	template <typename T>
	struct iterator_traits<const T *>
	{	
		typedef ptrdiff_t 					difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <typename T, typename U>
	struct is_iterator 	{};

	template <typename T>
	struct is_iterator<T, typename T::iterator_category>
	{
		typedef T type;
	};
	
	template <typename T>
	struct is_iterator<T *, typename iterator_traits<T *>::iterator_category>
	{
		typedef T type;
	};

	template <typename _Iter>
	typename iterator_traits<_Iter>::iterator_category iterCategory(const _Iter&)
	{
		typename iterator_traits<_Iter>::iterator_categoty _category;
		return (_category);
	}

	template <typename InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
	{
		ptrdiff_t diff;
	
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
