#ifndef FT_MAP_BASE_HPP
# define FT_MAP_BASE_HPP

namespace ft
{
	template <typename Key, typename T, typename Compare, typename Alloc>
	class map_base
	{
		protected:
			typedef Key		key_type;
			typedef T		mapped_type;
			typedef Compare	key_compare;
			typedef ft::Pair<const key_type, mapped_type> value_type;
			typedef Alloc		allocator_type;
			typedef typename allocator_type::reference	reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef ft::node_map<value_type>	node;
			typedef typename allocator_type::template rebind<node>::other node_allocator_type;
			typedef size_t		size_type;
			typedef ptrdiff_t	difference_type;
			typedef typename node_allocator_type::reference node_reference;
			typedef typename node_allocator_type::const_reference node_const_reference;
			typedef typename node_allocator_type::pointer node_pointer;
			typedef typename node_allocator_type::const_pointer node_const_pointer;
			typedef ft::Pair<const key_type, mapped_type> (*val_maker)(const key_type, mapped_type);
			node_pointer	_head;
			size_type		_size;
			map_base();
			//~map_base();
			//map_base(map_base const& src);
			//operator=
			node_pointer	construct_node(value_type const& val);
			node_pointer	construct_node(key_type const& key);
			node_pointer	GrandParent(node_pointer const& src);
			node_pointer	Sibling(node_pointer const& src);
			node_pointer	Uncle(node_pointer const& src);
			node_pointer	Parent(node_pointer const& src);
			pointer		find_key(key_type const& k) const;
			void	insert_node(node_pointer& new_node);
			void	set_to_head(node_pointer& new_node);
			void	add_node(value_type const& val);
			void	add_node(key_type const& key);
			void	check_node(node_pointer const& x);
			val_maker	get_val_maker();
			bool	isLchild(node_pointer const& x);
			void	recoloring(node_pointer const& x);
			void	restructuring1(node_pointer const& x);
			void	restructuring2(node_pointer const& x);
			void	restructuring3(node_pointer const& x);
			void	restructuring4(node_pointer const& x);
			node_pointer	left();
			node_pointer	left(node_pointer const& hint);
			void	printcolor();	//temp
		private:
			void	swap_color(node_pointer const& x, node_pointer const& y);
			void	rotate_to_right(node_pointer const& x);
			void	rotate_to_left(node_pointer const& x);
			void	node_info(node_pointer const& pos);	//temp


			
	};
	#include "ft_map_base2.ipp"
}
#endif
