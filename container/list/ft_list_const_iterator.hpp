#ifndef LIST_CONST_ITERATOR_HPP
# define LIST_CONST_ITERATOR_HPP

#include "../utils/traits.hpp"
#include "../utils/function.hpp"
#include "../iterator/iterator.hpp"
#include "./ft_node_list.hpp"

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
			bool	operator==(ft::list_iterator<value_type> const& x) const;
			bool	operator!=(ft::list_iterator<value_type> const& x) const;
	};
	template <typename U>
	bool	operator==(ft::list_const_iterator<U> const& lhs, ft::list_const_iterator<U> const& rhs);
	template <typename U>
	bool	operator!=(ft::list_const_iterator<U> const& lhs, ft::list_const_iterator<U> const& rhs);
	#include "./src/ft_list_const_iterator2.ipp"

}

#endif
