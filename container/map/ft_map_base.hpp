#ifndef FT_MAP_BASE_HPP
# define FT_MAP_BASE_HPP

#include <memory>
#include "./ft_node_map.hpp"
#include "../utils/pair.hpp"
#include "../utils/function.hpp"

namespace ft
{
	template <typename Key, typename T, typename Compare, typename Alloc>
	class map_base
	{
		protected:
			typedef Key			key_type;
			typedef T			mapped_type;
			typedef Compare		key_compare;
			typedef Alloc		allocator_type;
			typedef ft::pair<const key_type, mapped_type> value_type;
			typedef ft::node_map<value_type>	node;
			typedef typename allocator_type::template rebind<node>::other node_allocator_type;
			typedef typename allocator_type::size_type				size_type;
			typedef typename node_allocator_type::reference			node_reference;
			typedef typename node_allocator_type::const_reference	node_const_reference;
			typedef typename node_allocator_type::pointer			node_pointer;
			typedef typename node_allocator_type::const_pointer		node_const_pointer;
		
			node_pointer	_head;
			node_pointer	_headnext;
			size_type		_size;
			map_base(allocator_type const& alloc = allocator_type());
			~map_base();
			map_base(map_base const& src);
			map_base& operator=(map_base const& src);
			node_pointer	Farleft_after(node_pointer const& parent) const;
			node_pointer	Farright_after(node_pointer const& parent) const;
			node_pointer	find_key(key_type const& k) const;
			node_pointer	find_key(key_type const& k, node_pointer const& start) const;
			node_pointer	find_lower_bound(const key_type& k) const;
			node_pointer	find_upper_bound(const key_type& k) const;
			void			set_to_head(node_pointer const& new_node);
			void			clear_node();
			node_pointer	add_node(value_type const& val);
			node_pointer	add_node(value_type const& val, node_pointer const& position);
			node_pointer	add_node(key_type const& key);
			void			erase_node(node_pointer const& target, bool check);
			size_type		maxsize() const;
			ft::pair<bool, node_pointer>	check_position(key_type const&k, node_pointer const& hint) const;
			node_pointer	end_node() const;
		private:	
			node_pointer	least_leaf();
			node_pointer	GrandParent(node_pointer const& src) const;
			node_pointer	Sibling(node_pointer const& src) const;
			node_pointer	Uncle(node_pointer const& src) const;
			node_pointer	next_node(node_pointer const& x) const;
			node_pointer	prev_node(node_pointer const& x) const;
			node_pointer	construct_node(value_type const& val);
			node_pointer	construct_node(key_type const& key);
			Color	getColor(node_pointer const& node);
			void	swap_color(node_pointer const& x, node_pointer const& y);
			void	rotate_to_right(node_pointer const x);
			void	rotate_to_left(node_pointer const x);
			void	relink(node_pointer const& p, node_pointer const& c, bool isLchild);
			void	destroy_node(node_pointer const& node);
			void	attach_to_right(node_pointer const& x, node_pointer const& new_right);
			void	attach_to_left(node_pointer const& x, node_pointer const& new_left);
			node_pointer	case_change(node_pointer const& x);
			void	caseA(node_pointer const& x);
			void	caseB(node_pointer const& x);
			void	caseC(node_pointer const& x);
			void	switch_node(node_pointer const& x, node_pointer const& y);
			void	recoloring(node_pointer const& x);
			void	restructuring1(node_pointer const& x);
			void	restructuring2(node_pointer const& x);
			void	restructuring3(node_pointer const& x);
			void	restructuring4(node_pointer const& x);
			void	check_double_red(node_pointer const& x);
			void	check_double_black(node_pointer const& x, node_pointer const& sibling);
			void	insert_node(node_pointer const& new_node);
			void	insert_node(node_pointer const& new_node, node_pointer const& start);
			bool	isLchild(node_pointer const& x) const;
	};
	#include "./src/ft_map_base2.ipp"
}
#endif
