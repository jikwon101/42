#ifndef FT_NODE_SET_HPP
# define FT_NODE_SET_HPP

namespace ft
{
	enum Color
	{
		BLACK,
		RED,
	};

	template <typename T>
	struct node_set
	{
		typedef node_set*	pointer;
		typedef T			value_type;
		pointer				Lchild;
		pointer				Rchild;
		pointer				Parent;
		value_type			data;
		Color				color;
		node_set();
		node_set(value_type const& src);
		node_set(node_set const& src);
		node_set& operator=(node_set const& src);
		~node_set();
	};
	#include "./src/ft_node_set2.ipp"

}

#endif
