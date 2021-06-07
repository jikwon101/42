#ifndef FT_SET_ITERATOR_HPP
# define FT_SET_ITERATOR_HPP

#include "../utils/traits.hpp"
#include "../utils/function.hpp"
#include "../iterator/iterator.hpp"
#include "./ft_node_set.hpp"

namespace ft
{
	template <typename T, typename Compare, typename Alloc>
	class set;

	template <typename U>
	class set_const_iterator;

	template <typename V>
	class set_iterator : public iterator<ft::bidirectional_iterator_tag, V>
	{
		template <typename T, typename Compare, typename Alloc>
		friend class ft::set;
		template <typename U>
		friend class ft::set_const_iterator;
		template <typename U>
		friend bool operator==(set_iterator<U> const& lhs, set_iterator<U> const& rhs);
		template <typename U>
		friend bool operator!=(set_iterator<U> const& lhs, set_iterator<U> const& rhs);
		public:
			typedef V								value_type;
			typedef value_type*						pointer;
			typedef value_type&						reference;
			typedef ptrdiff_t						difference_type;
			typedef ft::node_set<value_type>*		iterator_type;
		private:
			iterator_type	_ptr;
			bool	isRchild(iterator_type const& node);
			bool	isLchild(iterator_type const& node);
			iterator_type Farleft_after(iterator_type const& parent);
			iterator_type Farright_after(iterator_type const& parent);
		public:
			set_iterator();
			~set_iterator();
			set_iterator(iterator_type const& src);
			set_iterator(set_iterator const& rhs);
			set_iterator&		operator=(set_iterator const& rhs);
			reference			operator*() const;		
			set_iterator&		operator++();
			set_iterator		operator++(int);
			set_iterator&		operator--() ;
			set_iterator		operator--(int);
			pointer				operator->() ;
			bool				operator==(set_const_iterator<value_type> const& x) const;
			bool				operator!=(set_const_iterator<value_type> const& x) const;
	};
	template <typename U>
	bool	operator==(set_iterator<U> const& lhs, set_iterator<U> const& rhs);
	template <typename U>
	bool	operator!=(set_iterator<U> const& lhs, set_iterator<U> const& rhs);
	#include "./src/ft_set_iterator2.ipp"

}

#endif
