#ifndef LIST_BASE_HPP
# define LIST_BASE_HPP

#include <memory>
#include <limits>
#include "../iterator/list_iterator.hpp"
#include "../iterator/list_const_iterator.hpp"
#include "../utils/node.hpp"
#include "../utils/pair.hpp"
#include "../iterator/reverse_iterator.hpp"

namespace ft
{
	template <typename T, typename Alloc>
	class list_base
	{
		private:
			typedef Alloc	alloc_type;
			typedef typename alloc_type::template rebind<ft::node<T> >::other	node_alloc_type;
		protected:
			typedef typename node_alloc_type::value_type	node;
			typedef	typename node_alloc_type::pointer		node_pointer;
			typedef typename node_alloc_type::const_pointer	node_const_pointer;
			typedef typename alloc_type::difference_type	difference_type;
			typedef typename alloc_type::size_type			size_type;
			typedef typename alloc_type::value_type			value_type;
			typedef typename alloc_type::pointer			pointer;
			typedef typename alloc_type::const_pointer		const_pointer;
			typedef typename alloc_type::reference			reference;
			typedef typename alloc_type::const_reference	const_reference;
		private:
			ft::Pair<node_pointer, node_pointer> _end_node;	//(tail, head)
			size_type	_size;
		protected:
			list_base(const alloc_type& alloc = alloc_type());
			list_base(const list_base& src);
			list_base& operator=(const list_base& src);
			~list_base();
			bool			isEnd(node_pointer& nd) const;
			size_type		_max_size() const;
			size_type		length(node_pointer& head, node_pointer& tail);
			size_type		to_tail(node_pointer& nd);
			node_pointer	_head() const;
			node_pointer	_tail() const;
			node_pointer	_end() const;
			size_type		get_size() const;
			void			swap_base(list_base& x);
			void			append_node_back(size_type n,const value_type& val);
			template <typename InputIt>
			void			append_node_back(InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type* = NULL);
			void			append_node_front(size_type n, const value_type& val);
			void			insert_node_front(node_pointer& next_node, node_pointer& new_node, size_type n);
			void			insert_node_back(node_pointer& prev_node, node_pointer& new_node, size_type n);
			node_pointer	make_one_node(const value_type& val);
			node_pointer	make_nodes(size_type n, const value_type& val);
			template <typename InputIt>
			node_pointer	make_nodes(InputIt first, InputIt last);
			void			link_node(node_pointer& prev_node, node_pointer& next_node);
			node_pointer&	delete_nodes(node_pointer& first, node_pointer& last);
			node_pointer	delete_one_node(node_pointer& target);
			node_pointer	splice_node(node_pointer first, node_pointer last);
	};
	#include "list_base2.ipp"
}

#endif
