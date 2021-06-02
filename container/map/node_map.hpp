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

	template <typename T>
	node_map<T>::node_map() : Parent(NULL), Lchild(NULL), Rchild(NULL), color(RED)
	{}

	template <typename T>
	node_map<T>::node_map(value_type const& src) : Parent(NULL), Lchild(NULL), Rchild(NULL), color(RED), data(src)
	{}

	template <typename T>
	node_map<T>::node_map(node_map const& src) : color(src.color), data(src.data)
	{
		Lchild = src.Lchild;
		Rchild = src.Rchild;
		Parent = src.Parent;
	}

	template <typename T>
	node_map<T>&	node_map<T>::operator=(node_map const& src)
	{
		if (this != &src)
		{
			color = src.color;
			Lchild = src.Lchild;
			Rchild = src.Rchild;
			Parent = src.Parent;
			data = src.data;
		}
		return (*this);
	}

	template <typename T>
	node_map<T>::~node_map()
	{}
}

#endif
