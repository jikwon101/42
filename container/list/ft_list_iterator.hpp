#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

#include "../utils/traits.hpp"
#include "../utils/function.hpp"
#include "../iterator/iterator.hpp"
#include "./ft_node_list.hpp"

namespace ft
{
	template <typename T, typename Alloc>
	class list;

	template <typename T>
	class list_const_iterator;
	
	template <typename T>
	class list_iterator : public iterator<ft::bidirectional_iterator_tag, T>
	{
		template <typename U, typename Alloc>
		friend class ft::list;
		template <typename U>
		friend class ft::list_iterator;
		template <typename U>
		friend class ft::list_const_iterator;

		public:
			typedef T								value_type;
			typedef value_type*						pointer;
			typedef value_type&						reference;
			typedef ptrdiff_t						difference_type;
			typedef ft::node_list<value_type>*			iterator_type;
			//typedef ft::bidirectional_iterator_tag 	iterator_category;
		private:
			iterator_type _ptr;
		public:
			list_iterator();
			~list_iterator();
			list_iterator(iterator_type const& src);
			list_iterator(list_iterator const& rhs);
			list_iterator& operator=(list_iterator const& rhs);

			reference			operator*() const;		
			list_iterator&		operator++();
			list_iterator		operator++(int);
			list_iterator&		operator--() ;
			list_iterator		operator--(int);
			pointer				operator->() ;
			template <typename U>
			friend bool operator==(list_iterator<U> const& lhs, list_iterator<U> const& rhs);
			template <typename U>
			friend bool operator!=(list_iterator<U> const& lhs, list_iterator<U> const& rhs);
	};
	template <typename U>
	bool	operator==(list_iterator<U> const& lhs, list_iterator<U> const& rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}
	template <typename U>
	bool	operator!=(list_iterator<U> const& lhs, list_iterator<U> const& rhs)
	{
		return (lhs._ptr != rhs._ptr);
	}
	#include "./src/ft_list_iterator2.ipp"

}

#endif
