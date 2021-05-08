#ifndef LIST_HPP
# define LIST_HPP

#include "../iterator/list_iterator.hpp"
#include "../utils/node.hpp"
#include "../utils/pair.hpp"

namespace ft
{
	template <typename T, typename Alloc>
	class list_base
	{
		protected:
			typedef Alloc			alloc_type;
			typedef T& reference;
			typedef const T& const_reference;
			typedef typename std::allocator_traits<alloc_type>	alloc_traits;
			typedef ft::node<T>			node;
			typedef node*			node_pointer;
			typedef	const node*		const_node_pointer;
			typedef node& 			node_reference;
			typedef const node&		const_node_reference;
			typedef typename alloc_traits::size_type size_type;
			typedef typename alloc_traits::difference_type difference_type;
			typedef T	value_type;
		private:
			typedef typename alloc_traits::pointer pointer;
			typedef typename alloc_traits::const_pointer const_pointer;
			typedef typename alloc_type::template rebind<node>::other node_alloc_type;
			
		protected:
			Pair<node_pointer, node_pointer> _end;	//(_prev, _next), (_tail, _head)
			size_type _size;
			
			list_base();
			list_base(size_type n);
			list_base(const list_base& src);
			~list_base();
			size_type	_max_size() const;
			size_type	size(node_pointer& head, node_pointer& tail);
			node_pointer& to_head(node_pointer& nd);
			node_pointer& to_tail(node_pointer& nd);
			bool	isHead(node_pointer& nd) const;
			bool	isTail(node_pointer& nd) const;
			node_pointer& head();
			node_pointer& tail();
			void	append_node_back(size_type n, const value_type& val);
			void	append_node_back(node_pointer const& first, node_pointer const& last);
			void	insert_node_back(node_pointer& prev_node, node_pointer& new_node);
			node_pointer	make_one_node(const value_type& val);
			node_pointer	make_nodes(size_type n, const value_type& val);
			node_pointer	make_nodes(node_pointer const&first, node_pointer const& last);
			void	link_node(node_pointer& prev_node, node_pointer& next_node);
	};
	template <typename T, typename Alloc = std::allocator<T> >
	class list : private list_base<T, Alloc>
	{
		public:
			typedef T						value_type;
			typedef Alloc				alloc_type;
			typedef ft::list_iterator<T>	iterator;
			typedef typename list_base<T, Alloc>::node			node;
			/*
			typedef typename  list_base<T, Alloc>::node_pointer	node_pointer;
			typedef typename list_base<T, Alloc>::const_node_pointer	const_node_pointer;
			typedef typename  list_base<T, Alloc>::node_reference reference;
			typedef typename list_base<T, Alloc>::const_node_reference	const_reference;
			*/
			typedef T& reference;
			typedef const T& const_reference;
			typedef T* pointer;
			typedef const T* const_pointer;
			typedef typename list_base<T, Alloc>::size_type		size_type;

			typedef typename list_base<T, Alloc>::difference_type	difference_type;
		private:
			typedef typename list_base<T, Alloc>::node_pointer node_pointer;
		public:
			explicit list(const alloc_type& alloc = alloc_type());
			explicit list(size_type n, const value_type& val = value_type(), const alloc_type& alloc = alloc_type());
			list(const list& src);
			~list();
			alloc_type get_allocator() const;
			/* iterator */
			iterator begin();
			iterator end();
			/* access element */
			reference front();
			const_reference front() const;
			reference	back();
			const_reference back() const;
			/* capacity */
			bool	empty() const;
			size_type size() const;
			size_type max_size() const;

		private:
	};
	#include "list2.ipp"
}

#endif
