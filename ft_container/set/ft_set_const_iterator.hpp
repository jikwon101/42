#ifndef FT_SET_CONST_ITERATOR_HPP
# define FT_SET_CONST_ITERATOR_HPP

#include "../utils/traits.hpp"
#include "../utils/function.hpp"
#include "../iterator/iterator.hpp"
#include "../utils/ft_RBTNode.hpp"

namespace ft
{
	template <typename T, typename Compare, typename Alloc>
	class set;
	template <typename U>
	class set_iteraotr;

	template <typename V>
	class set_const_iterator : public iterator<ft::bidirectional_iterator_tag, V>
	{
		template <typename T, typename Compare, typename Alloc>
		friend class ft::set;
		template <typename U>
		friend class ft::set_iterator;
		template <typename U>
		friend bool operator==(set_const_iterator<U> const& lhs, set_const_iterator<U> const& rhs);
		template <typename U>
		friend bool operator!=(set_const_iterator<U> const& lhs, set_const_iterator<U> const& rhs);
		public:
			typedef V value_type;
			typedef value_type*							pointer;
			typedef const value_type*					const_pointer;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef ptrdiff_t							difference_type;
			typedef ft::RBTNode<value_type>*			iterator_type;
		private:
			iterator_type	_ptr;
			iterator_type	Farleft_after(iterator_type const& parent);
			iterator_type	Farright_after(iterator_type const& parent);
			bool	isRchild(iterator_type const& node);
			bool	isLchild(iterator_type const& node);
		public:
			set_const_iterator();
			~set_const_iterator();
			set_const_iterator(iterator_type const& src);
			set_const_iterator(set_const_iterator const& rhs);
			set_const_iterator&		operator=(set_const_iterator const& rhs);
			const_reference			operator*() const;		
			set_const_iterator&		operator++();
			set_const_iterator		operator++(int);
			set_const_iterator&		operator--() ;
			set_const_iterator		operator--(int);
			const_pointer			operator->() ;
			bool					operator==(set_iterator<value_type> const& x) const;
			bool					operator!=(set_iterator<value_type> const& x) const;
	};
	template <typename U>
	bool	operator==(set_const_iterator<U> const& lhs, set_const_iterator<U> const& rhs);
	template <typename U>
	bool	operator!=(set_const_iterator<U> const& lhs, set_const_iterator<U> const& rhs);
	#include "./src/ft_set_const_iterator2.ipp"

}

#endif
