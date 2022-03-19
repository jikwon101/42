#ifndef FT_NODE_MULTIMAP_HPP
# define FT_NODE_MULTIMAP_HPP

namespace ft
{
	enum Color
	{
		BLACK,
		RED,
	};

	template <typename T>
	struct node_multimap
	{
		typedef node_multimap*	pointer;
		typedef T			value_type;
		pointer				Lchild;
		pointer				Rchild;
		pointer				Parent;
		value_type			data;
		Color				color;
		node_multimap();
		node_multimap(value_type const& src);
		node_multimap(node_multimap const& src);
		node_multimap& operator=(node_multimap const& src);
		~node_multimap();
	};
	#include "./src/ft_node_multimap2.ipp"

}

#endif
