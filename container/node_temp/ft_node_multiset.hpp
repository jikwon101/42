#ifndef FT_NODE_MULTISET_HPP
# define FT_NODE_MULTISET_HPP

namespace ft
{
	enum Color
	{
		BLACK,
		RED,
	};

	template <typename T>
	struct node_multiset
	{
		typedef node_multiset*	pointer;
		typedef T			value_type;
		pointer				Lchild;
		pointer				Rchild;
		pointer				Parent;
		value_type			data;
		Color				color;
		node_multiset();
		node_multiset(value_type const& src);
		node_multiset(node_multiset const& src);
		node_multiset& operator=(node_multiset const& src);
		~node_multiset();
	};
	#include "./src/ft_node_multiset2.ipp"

}

#endif
