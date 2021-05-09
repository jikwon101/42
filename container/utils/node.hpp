#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{
	template <typename T>
	struct node
	{
		typedef node<T>*	pointer;
		pointer				_prev;
		pointer				_next;
		T					_val;
		node();
		node(const T& val);
	};
	#include "node2.ipp"
}

#endif
