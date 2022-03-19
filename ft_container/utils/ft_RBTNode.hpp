#ifndef FT_RBTNODE_HPP
# define FT_RBTNODE_HPP

namespace ft
{
	enum Color
	{
		BLACK,
		RED,
	};

	template <typename T>
	struct RBTNode
	{
		typedef RBTNode*	pointer;
		typedef T			value_type;
		pointer				Lchild;
		pointer				Rchild;
		pointer				Parent;
		value_type			data;
		Color				color;
		RBTNode();
		RBTNode(value_type const& src);
		RBTNode(RBTNode const& src);
		RBTNode& operator=(RBTNode const& src);
		~RBTNode();
	};
	#include "./ft_RBTNode2.ipp"

}

#endif
