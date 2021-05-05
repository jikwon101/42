#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "./iterator.hpp"
#include "./traits.hpp"
#include "./function.hpp"

namespace ft
{
	template <typename _Iter>
	class reverse_iterator
	{
		public:
			typedef _Iter				iterator_type;
			typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type			value_type;
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::pointer			pointer;
			typedef typename iterator_traits<iterator_type>::reference			reference;
		private:
			iterator_type _base;
		public:
			~reverse_iterator();
			reverse_iterator();
			explicit reverse_iterator(iterator_type it);
			template <typename It>
			reverse_iterator(const reverse_iterator<It>& rev_it);
			reverse_iterator& operator=(reverse_iterator const& rhs);
			
			iterator_type		base() const;
			reference			operator*() const;
			reverse_iterator	operator+(difference_type n) const;
			reverse_iterator&	operator++();
			reverse_iterator	operator++(int);
			reverse_iterator&	operator+=(difference_type n);
			reverse_iterator	operator-(difference_type n) const;
			reverse_iterator&	operator--();
			reverse_iterator	operator--(int);
			reverse_iterator&	operator-=(difference_type n);
			pointer				operator->() const;
			reference			operator[] (difference_type n) const;
	};

	template <typename Iter>
	bool	operator==(const reverse_iterator<Iter>lhs, const reverse_iterator<Iter>& rhs);
	template <typename Iter>
	bool	operator!=(const reverse_iterator<Iter>lhs, const reverse_iterator<Iter>& rhs);
	template <typename Iter>
	bool	operator<(const reverse_iterator<Iter>lhs, const reverse_iterator<Iter>& rhs);
	template <typename Iter>
	bool	operator<=(const reverse_iterator<Iter>lhs, const reverse_iterator<Iter>& rhs);
	template <typename Iter>
	bool	operator>(const reverse_iterator<Iter>lhs, const reverse_iterator<Iter>& rhs);
	template <typename Iter>
	bool	operator>=(const reverse_iterator<Iter>lhs, const reverse_iterator<Iter>& rhs);
	template <typename Iter>
	reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& rev_it);
	template <typename T, typename U>
	typename reverse_iterator<T>::difference_type	operator-(const reverse_iterator<T>&lhs, const reverse_iterator<U>& rhs);
#include "./reverse_iterator2.hpp"

}
#endif
