#ifndef FT_NODE_LIST_HPP
# define FT_NODE_LIST_HPP

namespace ft
{
	template <typename T>
	struct node_list
	{
		typedef T				value_type;
		typedef node_list<T>*	pointer;
		pointer					_prev;
		pointer					_next;
		value_type				_val;
		node_list();
		node_list(value_type const& val);
		~node_list();
		node_list(node_list const& src);
		node_list& operator=(node_list const& src);
	};
	#include "./src/ft_node_list2.ipp"
}

#endif
