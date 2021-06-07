#ifndef FT_MAP_CONST_ITERATOR_HPP
# define FT_MAP_CONST_ITERATOR_HPP

#include "../utils/traits.hpp"
#include "../utils/function.hpp"
#include "../iterator/iterator.hpp"
#include "./ft_node_map.hpp"

namespace ft
{
	template <typename Key, typename T, typename Compare, typename Alloc>
	class map;
	template <typename U>
	class map_iteraotr;

	template <typename Pair>
	class map_const_iterator : public iterator<ft::bidirectional_iterator_tag, Pair>
	{
		template <typename Key, typename T, typename Compare, typename Alloc>
		friend class ft::map;
		template <typename U>
		friend class ft::map_iterator;
		template <typename U>
		friend bool operator==(map_const_iterator<U> const& lhs, map_const_iterator<U> const& rhs);
		template <typename U>
		friend bool operator!=(map_const_iterator<U> const& lhs, map_const_iterator<U> const& rhs);
		public:
			typedef Pair								value_type;
			typedef typename value_type::first_type		key_type;
			typedef typename value_type::second_type	mapped_type;
			typedef value_type*							pointer;
			typedef const value_type*					const_pointer;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef ptrdiff_t							difference_type;
			typedef ft::node_map<value_type>*			iterator_type;
		private:
			iterator_type	_ptr;
			iterator_type	Farleft_after(iterator_type const& parent);
			iterator_type	Farright_after(iterator_type const& parent);
			bool	isRchild(iterator_type const& node);
			bool	isLchild(iterator_type const& node);
		public:
			map_const_iterator();
			~map_const_iterator();
			map_const_iterator(iterator_type const& src);
			map_const_iterator(map_const_iterator const& rhs);
			map_const_iterator(map_iterator<Pair> const& rhs);
			map_const_iterator&		operator=(map_const_iterator const& rhs);
			const_reference			operator*() const;		
			map_const_iterator&		operator++();
			map_const_iterator		operator++(int);
			map_const_iterator&		operator--() ;
			map_const_iterator		operator--(int);
			const_pointer			operator->() ;
			bool					operator==(map_iterator<value_type> const& x) const;
			bool					operator!=(map_iterator<value_type> const& x) const;
	};
	template <typename U>
	bool	operator==(map_const_iterator<U> const& lhs, map_const_iterator<U> const& rhs);
	template <typename U>
	bool	operator!=(map_const_iterator<U> const& lhs, map_const_iterator<U> const& rhs);
	#include "./src/ft_map_const_iterator2.ipp"

}

#endif
