#ifndef FT_VECTOR_ITERATOR_HPP
# define FT_VECTOR_ITERATOR_HPP

#include "../utils/traits.hpp"
#include "../iterator/iterator.hpp"
#include <iterator>

namespace ft
{
	template <typename _Iters>
	class vector_iterator
	{
		public:
			typedef _Iters			iterator_type;
			typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type			value_type;
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::pointer			pointer;
			typedef typename iterator_traits<iterator_type>::reference			reference;
		private:
			iterator_type _ptr;
		public:
			vector_iterator();
			~vector_iterator();
			vector_iterator(iterator_type const src);
			template <typename U>
			vector_iterator(vector_iterator<U> const& rhs);
			vector_iterator& operator=(vector_iterator const& rhs);

			iterator_type		base() const;	
			reference			operator*() const;		
			vector_iterator		operator+(difference_type n) const;
			vector_iterator&	operator++();
			vector_iterator		operator++(int);
			vector_iterator&	operator+=(difference_type n);
			vector_iterator		operator-(difference_type n) const;
			vector_iterator&	operator--() ;
			vector_iterator		operator--(int);
			vector_iterator&	operator-=(difference_type n);
			pointer				operator->() ;
			reference			operator[](int n) const ;
	};
	template <typename T, typename U>
	bool	operator==(vector_iterator<T> const& lhs, vector_iterator<U> const& rhs);
	template <typename T, typename U>
	bool	operator!=(vector_iterator<T> const& lhs, vector_iterator<U> const& rhs);
	template <typename T, typename U>
	bool	operator>(vector_iterator<T> const& lhs, vector_iterator<U> const& rhs);
	template <typename T, typename U>
	bool	operator>=(vector_iterator<T> const& lhs, vector_iterator<U> const& rhs);
	template <typename T, typename U>
	bool	operator<(vector_iterator<T> const& lhs, vector_iterator<U> const& rhs);
	template <typename T, typename U>
	bool	operator<=(vector_iterator<T> const& lhs, vector_iterator<U> const& rhs);
	template <typename T, typename U>
	typename ft::iterator_traits<T>::difference_type	operator-(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs);

	#include "./src/ft_vector_iterator2.ipp"

}

#endif
