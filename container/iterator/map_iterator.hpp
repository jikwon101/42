#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../utils/traits.hpp"
#include "../utils/function.hpp"
#include "./iterator.hpp"
#include "../map/node_map.hpp"

namespace ft
{
	template <typename Key, typename T, typename Compare, typename Alloc>
	class map;

	
	template <typename Pair>
	class map_iterator : public iterator<ft::bidirectional_iterator_tag, Pair>
	{
		template <typename Key, typename T, typename Compare, typename Alloc>
		friend class ft::map;
		template <typename U>
		friend class ft::map_iterator;
	//T : pair<key, mappedval>
		public:
			typedef Pair							value_type;
			typedef typename value_type::first_type			key_type;
			typedef typename value_type::second_type			mapped_type;
			typedef value_type*						pointer;
			typedef value_type&						reference;
			typedef ptrdiff_t						difference_type;
			typedef ft::node_map<value_type>*			iterator_type;
		private:
			iterator_type _ptr;
			bool	isRchild(iterator_type const& node);
			bool	isLchild(iterator_type const& node);
			iterator_type left(iterator_type const& hint);
		public:
			map_iterator();
			~map_iterator();
			map_iterator(iterator_type const& src);
			map_iterator(map_iterator const& rhs);
			map_iterator& operator=(map_iterator const& rhs);

			reference			operator*() const;		
			map_iterator&		operator++();
			map_iterator		operator++(int);
			map_iterator&		operator--() ;
			map_iterator		operator--(int);
			pointer				operator->() ;
			template <typename U>
			friend bool operator==(map_iterator<U> const& lhs, map_iterator<U> const& rhs);
			template <typename U>
			friend bool operator!=(map_iterator<U> const& lhs, map_iterator<U> const& rhs);
	};
	template <typename U>
	bool	operator==(map_iterator<U> const& lhs, map_iterator<U> const& rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}
	template <typename U>
	bool	operator!=(map_iterator<U> const& lhs, map_iterator<U> const& rhs)
	{
		return (lhs._ptr != rhs._ptr);
	}
	#include "map_iterator2.ipp"

}

#endif
