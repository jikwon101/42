#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include <exception>
#include "./iterator.hpp"
#include "./iter_category.hpp"

namespace ft
{
	template <typename _Iters>
	class vector_iterator
	{
		public:
			typedef _Iters			iterator_type;
			typedef typename iterator_traits<iterator_type>::iterator_category  iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type value_type;
			typedef typename iterator_traits<iterator_type>::difference_type difference_type;
			typedef typename iterator_traits<iterator_type>::pointer pointer;
			typedef typename iterator_traits<iterator_type>::reference reference;
		private:
			iterator_type _ptr;
		public:
			vector_iterator();
			~vector_iterator();
			vector_iterator(iterator_type const src);
			vector_iterator(vector_iterator const& rhs);			
			template <typename U>  //only work on const;
			vector_iterator(vector_iterator<U> const& rhs, typename ft::enable_if<!ft::is_const<U>::value, U>::type = NULL );
			reference operator*() const;		
			vector_iterator& operator=(vector_iterator const& rhs);
			iterator_type base() const;	
			vector_iterator& operator++();
			vector_iterator operator++(int);
			vector_iterator& operator--() ;
			vector_iterator operator--(int);
			pointer operator->() ;

			template <typename U>
			bool operator==(vector_iterator<U> const& rhs) const;
			
			template <typename U>
			bool operator!=(vector_iterator<U> const &rhs) const;

			vector_iterator& operator+=(difference_type n);
			vector_iterator& operator-=(difference_type n);
			reference operator[](int n) const ;

			template <typename U>
			bool operator>(vector_iterator<U> const& other) const;

			template <typename U>
			bool operator<(vector_iterator<U> const& other) const;

			template <typename U>
			bool operator<=(vector_iterator<U> const& other) const;
		
			template <typename U>
			bool operator>=(vector_iterator<U> const& other) const;
			vector_iterator operator+(difference_type n);
			vector_iterator operator-(difference_type n);

	};
#include "vector_iterator2.hpp"

}

#endif
