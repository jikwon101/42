#ifndef FT_multiset_CONST_ITERATOR_HPP
# define FT_multiset_CONST_ITERATOR_HPP

#include "../utils/traits.hpp"
#include "../utils/function.hpp"
#include "../iterator/iterator.hpp"
#include "./ft_node_multiset.hpp"

namespace ft
{
	template <typename Key, typename T, typename Compare, typename Alloc>
	class multiset;
	template <typename U>
	class multiset_iteraotr;

	template <typename Pair>
	class multiset_const_iterator : public iterator<ft::bidirectional_iterator_tag, Pair>
	{
		template <typename Key, typename T, typename Compare, typename Alloc>
		friend class ft::multiset;
		template <typename U>
		friend class ft::multiset_iterator;
		template <typename U>
		friend bool operator==(multiset_const_iterator<U> const& lhs, multiset_const_iterator<U> const& rhs);
		template <typename U>
		friend bool operator!=(multiset_const_iterator<U> const& lhs, multiset_const_iterator<U> const& rhs);
		public:
			typedef Pair								value_type;
			typedef typename value_type::first_type		key_type;
			typedef typename value_type::second_type	mapped_type;
			typedef value_type*							pointer;
			typedef const value_type*					const_pointer;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef ptrdiff_t							difference_type;
			typedef ft::node_multiset<value_type>*			iterator_type;
		private:
			iterator_type	_ptr;
			iterator_type	Farleft_after(iterator_type const& parent);
			iterator_type	Farright_after(iterator_type const& parent);
			bool	isRchild(iterator_type const& node);
			bool	isLchild(iterator_type const& node);
		public:
			multiset_const_iterator();
			~multiset_const_iterator();
			multiset_const_iterator(iterator_type const& src);
			multiset_const_iterator(multiset_const_iterator const& rhs);
			multiset_const_iterator(multiset_iterator<Pair> const& rhs);
			multiset_const_iterator&		operator=(multiset_const_iterator const& rhs);
			const_reference			operator*() const;		
			multiset_const_iterator&		operator++();
			multiset_const_iterator		operator++(int);
			multiset_const_iterator&		operator--() ;
			multiset_const_iterator		operator--(int);
			const_pointer			operator->() ;
			bool					operator==(multiset_iterator<value_type> const& x) const;
			bool					operator!=(multiset_iterator<value_type> const& x) const;
	};
	template <typename U>
	bool	operator==(multiset_const_iterator<U> const& lhs, multiset_const_iterator<U> const& rhs);
	template <typename U>
	bool	operator!=(multiset_const_iterator<U> const& lhs, multiset_const_iterator<U> const& rhs);
	#include "./src/ft_multiset_const_iterator2.ipp"

}

#endif
