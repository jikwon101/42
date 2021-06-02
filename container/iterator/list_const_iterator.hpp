#ifndef LIST_CONST_ITERATOR_HPP
# define LIST_CONST_ITERATOR_HPP

#include "../utils/traits.hpp"
#include "../utils/function.hpp"
#include "./iterator.hpp"
#include "../list/node_list.hpp"

namespace ft
{
	template <typename T, typename Alloc>
	class list;

	template <typename T>
	class list_iterator;
	
	template <typename T>
	class list_const_iterator : public iterator<ft::bidirectional_iterator_tag, T>
	{
		template <typename U, typename Alloc>
		friend class ft::list;
		template <typename U>
		friend class ft::list_iterator;
		template <typename U>
		friend class ft::list_const_iterator;

		public:
			typedef T					value_type;
			typedef const value_type*	const_pointer;
			typedef const value_type&	const_reference;
			typedef ptrdiff_t			difference_type;
			typedef ft::node_list<value_type>*	iterator_type;
			//typedef typename node<typename ft::remove_const<value_type>::type>::pointer iterator_type;
			//typedef ft::bidirectional_iterator_tag	iterator_category;
		private:
			iterator_type _ptr;

		public:
			list_const_iterator();
			~list_const_iterator();
			list_const_iterator(iterator_type const& src);
			list_const_iterator(list_iterator<value_type> const& rhs);
			list_const_iterator(list_const_iterator const& rhs);
			list_const_iterator& operator=(list_iterator<value_type> const& rhs);
			list_const_iterator& operator=(list_const_iterator const& rhs);

			const_reference			operator*() const;		
			list_const_iterator&	operator++();
			list_const_iterator		operator++(int);
			list_const_iterator&	operator--() ;
			list_const_iterator		operator--(int);
			const_pointer			operator->() ;
			template <typename U>
			friend bool operator==(list_const_iterator<U> const& lhs, list_const_iterator<U> const& rhs);
			template <typename U>
			friend bool operator!=(list_const_iterator<U> const& lhs, list_const_iterator<U> const& rhs);
	};
	template <typename U>
	bool	operator==(list_const_iterator<U> const& lhs, list_const_iterator<U> const& rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}
	template <typename U>
	bool	operator!=(list_const_iterator<U> const& lhs, list_const_iterator<U> const& rhs)
	{
		return (lhs._ptr != rhs._ptr);
	}
	#include "list_const_iterator2.ipp"

}

#endif
