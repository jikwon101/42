#ifndef LIST_BASE_HPP
# define LIST_BASE_HPP

#include "../iterator/list_iterator.hpp"
#include "../iterator/list_const_iterator.hpp"
#include "../utils/node.hpp"
#include "../utils/pair.hpp"

namespace ft
{
	template <typename T, typename Alloc>
	class list_base
	{
		protected:
			typedef Alloc			alloc_type;
			typedef T				value_type;
			typedef T&				reference;
			typedef const T&		const_reference;
			typedef ft::node<T>		node;
			typedef node*			node_pointer;
			typedef	const node*		const_node_pointer;
			typedef node& 			node_reference;
			typedef const node&		const_node_reference;
			typedef typename std::allocator_traits<alloc_type>	alloc_traits;
			typedef typename alloc_traits::size_type			size_type;
			typedef typename alloc_traits::difference_type		difference_type;
		private:
			typedef typename alloc_traits::pointer				pointer;
			typedef typename alloc_traits::const_pointer		const_pointer;
			typedef typename alloc_type::template rebind<node>::other	node_alloc_type;
		protected:
			Pair<node_pointer, node_pointer> _end_node;	//(_prev, _next), (_tail, _head)
			size_type _size;
			list_base(const alloc_type& alloc = alloc_type());
			list_base(const list_base& src);
			list_base& operator=(const list_base& src);
			~list_base();
			size_type	_max_size() const;
			size_type	length(node_pointer& head, node_pointer& tail);
			node_pointer&	to_tail(node_pointer& nd);
			bool	isEnd(node_pointer& nd) const;
			node_pointer	_head() const;
			node_pointer	_tail() const;
			node_pointer	_end() const;
			void	swap_base(list_base& x);
			void	append_node_back(size_type n,const value_type& val);
			template <typename InputIt>
			void	append_node_back(InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type* = NULL);
			void	append_node_front(size_type n, const value_type& val);
			void	insert_node_front(node_pointer& next_node, node_pointer& new_node);
			void	insert_node_back(node_pointer& prev_node, node_pointer& new_node);
			node_pointer	make_one_node(const value_type& val);
			node_pointer	make_nodes(size_type n, const value_type& val);
			template <typename InputIt>
			node_pointer	make_nodes(InputIt first, InputIt last);
			void			link_node(node_pointer& prev_node, node_pointer& next_node);
			node_pointer&	delete_nodes(node_pointer& first, node_pointer& last);
			node_pointer&	delete_one_node(node_pointer& target);
			node_pointer	splice_node(node_pointer first, node_pointer last);
	};
	#include "list_base2.ipp"
}

#endif
