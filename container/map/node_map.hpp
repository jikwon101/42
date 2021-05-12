#ifndef NODE_MAP_HPP
# define NODE_MAP_HPP

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
		typedef T	value_type;
		pointer		Parent;
		pointer		Lchild;
		pointer		Rchild;
		value_type	data;
		Color		color;
		node_map() : Parent(NULL), Lchild(NULL), Rchild(NULL), color(RED)
		{}
		node_map(value_type const& src) : Parent(NULL), Lchild(NULL), Rchild(NULL), color(RED), data(src)
		{}
		~node_map()
		{}
		
	};
}

#endif
