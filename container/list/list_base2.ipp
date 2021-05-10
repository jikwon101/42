/* 
** list_base 
*/

template <typename T, typename Alloc>
list_base<T, Alloc>::list_base(const alloc_type& alloc)  : _size(0)
{
	(void)alloc;	//temp
	node_pointer _this = reinterpret_cast<node_pointer>(this);
	_end_node.first() = _end_node.second() = _this;
}

template <typename T, typename Alloc>
list_base<T, Alloc>::list_base(const list_base& src) : _size(0)
{
	node_pointer _this = reinterpret_cast<node_pointer>(this);
	_end_node.first() = _end_node.second() = _this;
	append_node_back(src._head(), src._end());
}

template <typename T, typename Alloc>
list_base<T, Alloc>&	list_base<T, Alloc>::operator=(const list_base& src)
{
	if ( this != &src)
	{
		if (_size)
			delete_nodes(_head(), _end());
		append_node_back(src._head(), src._end());
	}
	return (*this);
}

template <typename T, typename Alloc>
list_base<T, Alloc>::~list_base()
{}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::size_type	list_base<T, Alloc>::length(node_pointer& first, node_pointer& last)
{
	size_type cnt = 0;
	
	for (node_pointer pos = first; pos != last; pos = pos->_next)
		cnt++;
	return (cnt);
}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer& list_base<T, Alloc>::to_tail(node_pointer& nd)
{
	
	while (!(nd->_next == NULL || isEnd(nd->_next)))	
		nd = nd->_next;
	return (nd);
}

template <typename T, typename Alloc>
void	list_base<T, Alloc>::insert_node_back(node_pointer& prev_node, node_pointer& new_node)
{
	node_pointer next_node;
	node_pointer pos;

	next_node = prev_node->_next;
	pos = new_node;
	link_node(prev_node, pos);
	pos = to_tail(pos);
	link_node(pos, next_node);
}

template <typename T, typename Alloc>
void	list_base<T, Alloc>::insert_node_front(node_pointer& next_node, node_pointer& new_node)
{
	node_pointer pos = new_node;
	node_pointer& prev_node = next_node->_prev;
	
	link_node(prev_node, pos);
	pos = to_tail(new_node);
	link_node(pos, next_node);

}

template <typename T, typename Alloc>
void list_base<T, Alloc>::append_node_front(size_type n, const value_type& val)
{
	node_pointer new_node;
	node_pointer head_node;

	new_node = make_one_node(val);
	head_node = _head();
	insert_node_front(head_node, new_node);
	_size += n;
}

template <typename T, typename Alloc>
void list_base<T, Alloc>::append_node_back(size_type n, const value_type& val)
{
	node_pointer new_node;
	node_pointer tail_node;

	new_node = make_nodes(n, val);
	tail_node = _tail();
	insert_node_back(tail_node, new_node);
	_size += n;
}

template <typename T, typename Alloc>
template <typename InputIt>
void list_base<T, Alloc>::append_node_back(InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type*)
{
	node_pointer new_node;
	node_pointer tail_node;

	if (first == last)
		return ;
	new_node = make_nodes(first, last);
	tail_node = _tail();
	insert_node_back(tail_node, new_node);
	_size += ft::distance(first, last);
}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer list_base<T, Alloc>::make_one_node(const value_type& val)
{
	node_pointer new_node;

	new_node = node_alloc_type().allocate(1);
	node_alloc_type().construct(new_node, val);
	return (new_node);
}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer list_base<T, Alloc>::make_nodes(size_type n, const value_type& val)
{
	node_pointer new_node;
	node_pointer cur_node;
	node_pointer prev_node;
	
	cur_node = node_alloc_type().allocate(1);
	node_alloc_type().construct(cur_node, val);
	new_node = cur_node;
	for (size_type i = 0 ; i < n - 1 ; i++)
	{
		prev_node = cur_node;
		cur_node = node_alloc_type().allocate(1);
		node_alloc_type().construct(cur_node, val);
		link_node(prev_node, cur_node);
	}
	return (new_node);
}


template <typename T, typename Alloc>
template <typename InputIt>
typename list_base<T, Alloc>::node_pointer list_base<T, Alloc>::make_nodes(InputIt first, InputIt last)
{	
	node_pointer new_node = NULL;
	node_pointer cur_node = NULL;
	node_pointer prev_node = NULL;
	InputIt pos;
	
	pos = first;
	cur_node = make_one_node(*pos);
	new_node = cur_node;
	for (++pos; pos != last ; ++pos)
	{
		prev_node = cur_node;
		cur_node = make_one_node(*pos);
		link_node(prev_node, cur_node);
	}
	return (new_node);
}

template <typename T, typename Alloc>
void	list_base<T, Alloc>::link_node(node_pointer& prev_node, node_pointer& next_node)
{
	prev_node->_next = next_node;
	next_node->_prev = prev_node;
}

template <typename T, typename Alloc>
bool	list_base<T, Alloc>::isEnd(node_pointer& nd) const
{
	return (reinterpret_cast<list_base<T, Alloc>*>(nd) == this);
}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer list_base<T, Alloc>::_head() const
{
	return (_end_node.second());
}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer list_base<T, Alloc>::_tail() const
{
	return (_end_node.first());
}
template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer list_base<T, Alloc>::_end() const
{
	return (_end_node.first()->_next);
}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::size_type list_base<T, Alloc>::_max_size() const
{
	return (node_alloc_type().max_size());
}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer&	list_base<T, Alloc>::delete_one_node(node_pointer& target)
{
	node_alloc_type _deallocator;
	node_pointer& _prev = target->_prev;
	node_pointer& _next = target->_next;

	_deallocator.destroy(target);
	_deallocator.deallocate(target, 1);
	_size--;
	_prev->_next = _next;
	_next->_prev = _prev;
	return (_next);
}

// [first, last)
template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer&	list_base<T, Alloc>::delete_nodes(node_pointer& first, node_pointer& last)
{
	node_alloc_type _deallocator;
	node_pointer _prev = first->_prev;
	node_pointer _next;
	
	_prev = first->_prev;
	for (node_pointer pos = first; pos != last ; pos = _next)
	{
		_next = pos->_next;
		_deallocator.destroy(pos);
		_deallocator.deallocate(pos, 1);
		_size--;
	}
	_prev->_next = last;
	last->_prev = _prev;
	return (last);
}

template <typename T, typename Alloc>
void	list_base<T, Alloc>::swap_base(list_base& x)
{
	node_pointer new_node_x;
	node_pointer new_node_this;
	node_pointer head_node;
	
	if (this == &x)
		return ;
	if (!_size && !x._size)
		return ;
	new_node_x = x.splice_node(x._head(), x._end());
	new_node_this = x.splice_node(_head(), _end());
	head_node = _head();
	insert_node_front(head_node, new_node_x);
	head_node = x._head();
	x.insert_node_front(head_node, new_node_this);
}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer	list_base<T, Alloc>::splice_node(node_pointer first, node_pointer last)
{
	node_pointer prev_node_first = first->_prev;
	node_pointer prev_node_last = last->_prev;
	size_type n;

	n = length(first, last);
	prev_node_first->_next = last;
	last->_prev = prev_node_first;

	first->_prev = NULL;
	prev_node_last->_next = NULL;
	_size -= n;
	return (first);
}
