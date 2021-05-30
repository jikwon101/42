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
			node_pointer	_headnext;
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
			node_pointer	find_key(key_type const& k) const;
			node_pointer	find_key(key_type const& k, node_pointer const& start) const;
			ft::Pair<bool, node_pointer>	dist_type(key_type const&k, node_pointer const& hint) const;
			void	insert_node(node_pointer& new_node);
			void	insert_node(node_pointer& new_node, node_pointer const& start);
			void	set_to_head(node_pointer& new_node);
			node_pointer	add_node(value_type const& val);
			node_pointer	add_node(value_type const& val, node_pointer const& position);
			node_pointer	add_node(key_type const& key);
			void	check_double_red(node_pointer const& x);
			void	check_double_black(node_pointer const& x, node_pointer const& sibling);
			val_maker	get_val_maker();
			bool	isLchild(node_pointer const& x);
			void	recoloring(node_pointer const& x);
			void	restructuring1(node_pointer const& x);
			void	restructuring2(node_pointer const& x);
			void	restructuring3(node_pointer const& x);
			void	restructuring4(node_pointer const& x);
			node_pointer	Farleft_after(node_pointer const& parent);
			void	erase_node(node_pointer const& target);
			void	printcolor();	//temp
			void	count_color(); //temp
		private:
			Color	getColor(node_pointer const& node);
			void	swap_color(node_pointer const& x, node_pointer const& y);
			void	rotate_to_right(node_pointer const x);
			void	rotate_to_left(node_pointer const x);
			void	relink(node_pointer const& p, node_pointer const& c, bool isChild);
			void	destroy_node(node_pointer const& node);
			void	node_info(node_pointer const& pos);	//temp
			void	attach_to_right(node_pointer const& x, node_pointer const& new_right);
			void	attach_to_left(node_pointer const& x, node_pointer const& new_left);
			void	case_change(node_pointer const& x);
			void	caseA(node_pointer const& x);
			void	caseB(node_pointer const& x);
			void	caseC(node_pointer const& x);
			void	switch_node(node_pointer const& x, node_pointer const& y);

			
	};
	#include "ft_map_base2.ipp"
}
#endif
