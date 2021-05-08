template <typename T, typename Alloc>
list<T, Alloc>::list(const alloc_type& alloc)
{
	//std::cout << "[list] default\n";
}


// size
template <typename T, typename Alloc>
list<T, Alloc>::list(size_type n, const value_type& val, const alloc_type& alloc)
	: list_base<T, Alloc>(n)
{
	this->append_node_back(n, val);
}

// copy
template <typename T, typename Alloc>
list<T, Alloc>::list(const list& src)
{
	// write after adding const_iterator
	//this->append_node_back(src.begin(), src.end());
}

// destructor
template <typename T, typename Alloc>
list<T, Alloc>::~list()
{
	std::cout <<"[list] destructor\n";
	// write
}

// allocator
template <typename T, typename Alloc>
typename list<T, Alloc>::alloc_type list<T, Alloc>::get_allocator() const
{
	return (alloc_type());
}

// iterator
template <typename T, typename Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::begin()
{
	std::cout << "begin\n";
	return (this->head());
}
template <typename T, typename Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::end()
{
	return (this->tail()->_next);
}

template <typename T, typename Alloc>
typename list<T, Alloc>::reference	list<T, Alloc>::front()
{
	return (this->head()->_val);
}

template <typename T, typename Alloc>
typename list<T, Alloc>::const_reference	list<T, Alloc>::front() const
{
	return (this->head()->_val);
}
template <typename T, typename Alloc>
typename list<T, Alloc>::reference	list<T, Alloc>::back()
{
	return (this->tail()->_val);
}
template <typename T, typename Alloc>
typename list<T, Alloc>::const_reference	list<T, Alloc>::back() const
{
	return (this->tail()->_val);
}

/* capacity */
template <typename T, typename Alloc>
bool	list<T, Alloc>::empty() const
{
	return (this->_size == 0);
}
template <typename T, typename Alloc>
typename list<T, Alloc>::size_type list<T, Alloc>::size() const
{
	return (this->_size);
}
template <typename T, typename Alloc>
typename list<T, Alloc>::size_type list<T, Alloc>::max_size() const
{
	return (ft::min<size_type>(std::numeric_limits<difference_type>::max(),this->_max_size()));
}

/* 
** list_base 
*/

template <typename T, typename Alloc>
list_base<T, Alloc>::list_base()  : _size(0)
{
	//std::cout << "[base] default\n";

	/* new */
	node_pointer _this = reinterpret_cast<node_pointer>(this);
	_end.first() = _end.second() = _this;
}

template <typename T, typename Alloc>
list_base<T, Alloc>::list_base(size_type n) : _size(n)
{
	node_pointer _this = reinterpret_cast<node_pointer>(this);
	_end.first() = _end.second() = _this;
}

template <typename T, typename Alloc>
list_base<T, Alloc>::list_base(const list_base& src)
{
	//std::cout << "[base] copy\n";
	//oldend._prev = oldend._next = &oldend;
}

template <typename T, typename Alloc>
list_base<T, Alloc>::~list_base()
{
	//std::cout << "[base] destructor\n";

}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::size_type	list_base<T, Alloc>::size(node_pointer& head, node_pointer& tail)
{
	size_type cnt = 1;
	node_pointer pos;
	
	for (node_pointer pos = head; pos != tail ; pos = pos->_next)
		cnt++;
	return (cnt);
}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer& list_base<T, Alloc>::to_tail(node_pointer& nd)
{
	while (!(nd->_next == NULL || isTail(nd) == true))	
		nd = nd->_next;
	return (nd);
}
template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer& list_base<T, Alloc>::to_head(node_pointer& nd)
{
	while (!(nd->_prev == NULL || isHead(nd) == true))	
		nd = nd->_prev;
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
void list_base<T, Alloc>::append_node_back(size_type n, const value_type& val)
{
	node_pointer new_node;

	new_node = make_nodes(n, val);
	insert_node_back(tail(), new_node);
}

// [first, last)
template <typename T, typename Alloc>
void list_base<T, Alloc>::append_node_back(node_pointer const& first, node_pointer const& last)
{
	node_pointer new_node;

	new_node = make_nodes(first, last);
	insert_node_back(tail(), new_node);
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


// [first, last)
template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer list_base<T, Alloc>::make_nodes(node_pointer const& first, node_pointer const& last)
{
	node_pointer new_node = NULL;
	node_pointer cur_node = NULL;
	node_pointer prev_node = NULL;
	
	cur_node = make_one_node(first->_val);
	new_node = cur_node;
	for (node_pointer pos = first->_next ; pos != last ; pos = pos->_next)
	{
		prev_node = cur_node;
		cur_node = make_one_node(pos->_val);
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
bool	list_base<T, Alloc>::isHead(node_pointer& nd) const
{
	return (reinterpret_cast<list_base<T, Alloc>*>(nd->_prev) == this);
}
template <typename T, typename Alloc>
bool	list_base<T, Alloc>::isTail(node_pointer& nd) const
{
	return (reinterpret_cast<list_base<T, Alloc>*>(nd->_next) == this);
}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer& list_base<T, Alloc>::head()
{
	return (_end.second());
}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer& list_base<T, Alloc>::tail()
{
	return (_end.first());
}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::size_type list_base<T, Alloc>::_max_size() const
{
	return (node_alloc_type().max_size());
}
