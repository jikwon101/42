#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iter_category.hpp"

namespace ft
{
	template <bool B, class T>
	struct enable_if ;

	template <class T>
	struct enable_if<true, T> ;
	
	template <typename Category, typename T, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T& >
	struct iterator;

	template <typename Iterator>
	struct iterator_traits;

	template <typename T>
	struct iterator_traits<T *>;
	
	template <typename T>
	struct iterator_traits<const T *>;

	template <typename T, typename = void>
	struct is_iterator;

	template <typename T>
	struct is_iterator<T, typename ft::iterator_traits<T>::value_type>;

	template <typename _Iter>
	typename iterator_traits<_Iter>::iterator_category iterCategory(const _Iter&);

	template <typename InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last);

}
#endif
