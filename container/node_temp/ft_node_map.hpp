#ifndef FT_NODE_MAP_HPP
# define FT_NODE_MAP_HPP

namespace ft
{
	enum Color
	{
		BLACK,
		RED,
	};

	template <typename T>
	struct node_map
	{
		typedef node_map*	pointer;
		typedef T			value_type;
		pointer				Lchild;
		pointer				Rchild;
		pointer				Parent;
		value_type			data;
		Color				color;
		node_map();
		node_map(value_type const& src);
		node_map(node_map const& src);
		node_map& operator=(node_map const& src);
		~node_map();
	};
	#include "./src/ft_node_map2.ipp"

}

#endif
