#ifndef MAP_CONST_ITERATOR_HPP
# define MAP_CONST_ITERATOR_HPP

#include "../utils/traits.hpp"
#include "../utils/function.hpp"
#include "./iterator.hpp"
#include "../map/node_map.hpp"

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
		public:
			typedef Pair							value_type;
			typedef typename value_type::first_type			key_type;
			typedef typename value_type::second_type			mapped_type;
			typedef value_type*						pointer;
			typedef const value_type*				const_pointer;
			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef ptrdiff_t						difference_type;
			typedef ft::node_map<value_type>*			iterator_type;
		private:
			iterator_type _ptr;
			bool	isRchild(iterator_type const& node);
			bool	isLchild(iterator_type const& node);
			iterator_type Farleft_after(iterator_type const& parent);
			iterator_type Farright_after(iterator_type const& parent);
		public:
			map_const_iterator();
			~map_const_iterator();
			map_const_iterator(iterator_type const& src);
			map_const_iterator(map_const_iterator const& rhs);
			map_const_iterator& operator=(map_const_iterator const& rhs);

			const_reference			operator*() const;		
			map_const_iterator&		operator++();
			map_const_iterator		operator++(int);
			map_const_iterator&		operator--() ;
			map_const_iterator		operator--(int);
			const_pointer			operator->() ;
			template <typename U>
			friend bool operator==(map_const_iterator<U> const& lhs, map_const_iterator<U> const& rhs);
			template <typename U>
			friend bool operator!=(map_const_iterator<U> const& lhs, map_const_iterator<U> const& rhs);
	};
	template <typename U>
	bool	operator==(map_const_iterator<U> const& lhs, map_const_iterator<U> const& rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}
	template <typename U>
	bool	operator!=(map_const_iterator<U> const& lhs, map_const_iterator<U> const& rhs)
	{
		return (lhs._ptr != rhs._ptr);
	}
	#include "map_const_iterator2.ipp"

}

#endif
