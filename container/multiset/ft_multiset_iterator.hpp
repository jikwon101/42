#ifndef FT_MULTISET_ITERATOR_HPP
# define FT_MULTISET_ITERATOR_HPP

#include "../utils/traits.hpp"
#include "../utils/function.hpp"
#include "../iterator/iterator.hpp"
#include "./ft_node_multiset.hpp"

namespace ft
{
	template <typename T, typename Compare, typename Alloc>
	class multiset;

	template <typename U>
	class multiset_const_iterator;

	template <typename V>
	class multiset_iterator : public iterator<ft::bidirectional_iterator_tag, V>
	{
		template <typename T, typename Compare, typename Alloc>
		friend class ft::multiset;
		template <typename U>
		friend class ft::multiset_const_iterator;
		template <typename U>
		friend bool operator==(multiset_iterator<U> const& lhs, multiset_iterator<U> const& rhs);
		template <typename U>
		friend bool operator!=(multiset_iterator<U> const& lhs, multiset_iterator<U> const& rhs);
		public:
			typedef V									value_type;
			typedef value_type*							pointer;
			typedef value_type&							reference;
			typedef ptrdiff_t							difference_type;
			typedef ft::node_multiset<value_type>*		iterator_type;
		private:
			iterator_type	_ptr;
			bool	isRchild(iterator_type const& node);
			bool	isLchild(iterator_type const& node);
			iterator_type Farleft_after(iterator_type const& parent);
			iterator_type Farright_after(iterator_type const& parent);
		public:
			multiset_iterator();
			~multiset_iterator();
			multiset_iterator(iterator_type const& src);
			multiset_iterator(multiset_iterator const& rhs);
			multiset_iterator&		operator=(multiset_iterator const& rhs);
			reference			operator*() const;		
			multiset_iterator&		operator++();
			multiset_iterator		operator++(int);
			multiset_iterator&		operator--() ;
			multiset_iterator		operator--(int);
			pointer				operator->() ;
			bool				operator==(multiset_const_iterator<value_type> const& x) const;
			bool				operator!=(multiset_const_iterator<value_type> const& x) const;
	};
	template <typename U>
	bool	operator==(multiset_iterator<U> const& lhs, multiset_iterator<U> const& rhs);
	template <typename U>
	bool	operator!=(multiset_iterator<U> const& lhs, multiset_iterator<U> const& rhs);
	#include "./src/ft_multiset_iterator2.ipp"

}

#endif
