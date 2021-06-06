#ifndef FT_MULTIMAP_CONST_ITERATOR_HPP
# define FT_MULTIMAP_CONST_ITERATOR_HPP

#include "../utils/traits.hpp"
#include "../utils/function.hpp"
#include "../iterator/iterator.hpp"
#include "./ft_node_multimap.hpp"

namespace ft
{
	template <typename Key, typename T, typename Compare, typename Alloc>
	class multimap;
	template <typename U>
	class multimap_iteraotr;

	template <typename Pair>
	class multimap_const_iterator : public iterator<ft::bidirectional_iterator_tag, Pair>
	{
		template <typename Key, typename T, typename Compare, typename Alloc>
		friend class ft::multimap;
		template <typename U>
		friend class ft::multimap_iterator;
		template <typename U>
		friend bool operator==(multimap_const_iterator<U> const& lhs, multimap_const_iterator<U> const& rhs);
		template <typename U>
		friend bool operator!=(multimap_const_iterator<U> const& lhs, multimap_const_iterator<U> const& rhs);
		public:
			typedef Pair								value_type;
			typedef typename value_type::first_type		key_type;
			typedef typename value_type::second_type	mapped_type;
			typedef value_type*							pointer;
			typedef const value_type*					const_pointer;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef ptrdiff_t							difference_type;
			typedef ft::node_multimap<value_type>*			iterator_type;
		private:
			iterator_type	_ptr;
			iterator_type	Farleft_after(iterator_type const& parent);
			iterator_type	Farright_after(iterator_type const& parent);
			bool	isRchild(iterator_type const& node);
			bool	isLchild(iterator_type const& node);
		public:
			multimap_const_iterator();
			~multimap_const_iterator();
			multimap_const_iterator(iterator_type const& src);
			multimap_const_iterator(multimap_const_iterator const& rhs);
			multimap_const_iterator(multimap_iterator<Pair> const& rhs);
			multimap_const_iterator&		operator=(multimap_const_iterator const& rhs);
			const_reference			operator*() const;		
			multimap_const_iterator&		operator++();
			multimap_const_iterator		operator++(int);
			multimap_const_iterator&		operator--() ;
			multimap_const_iterator		operator--(int);
			const_pointer			operator->() ;
			bool					operator==(multimap_iterator<value_type> const& x) const;
			bool					operator!=(multimap_iterator<value_type> const& x) const;
	};
	template <typename U>
	bool	operator==(multimap_const_iterator<U> const& lhs, multimap_const_iterator<U> const& rhs);
	template <typename U>
	bool	operator!=(multimap_const_iterator<U> const& lhs, multimap_const_iterator<U> const& rhs);
	#include "./src/ft_multimap_const_iterator2.ipp"

}

#endif
