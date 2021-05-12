#ifndef FT_MAP_BASE_HPP
# define FT_MAP_BASE_HPP

namespace ft
{
	template <typename Key, typename T, typename Compare, typename Alloc>
	class map_base
	{
		protected:
			typedef Key key_type;
			typedef T mapped_type;
			typedef Compare key_compare;
			typedef ft::Pair<const key_type, mapped_type> value_type;
			typedef Alloc	allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef ft::node_map<value_type>	node;
			typedef typename allocator_type::template rebind<node>::other node_allocator_type;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef typename node_allocator_type::reference node_reference;
			typedef typename node_allocator_type::const_reference node_const_reference;
			typedef typename node_allocator_type::pointer node_pointer;
			typedef typename node_allocator_type::const_pointer node_const_pointer;
			node_pointer	_head;
			size_type _size;
			map_base();
			node_pointer	construct_node(value_type const& val);
			node_pointer&	GrandParent(node_pointer const& src);
			node_pointer&	Sibling(node_pointer const& src);
			node_pointer&	Uncle(node_pointer const& src);
			pointer		find_key(key_type const& k) const;
			void	insert_node(node_pointer& new_node);
			
	};
	#include "ft_map_base2.ipp"
}
#endif
