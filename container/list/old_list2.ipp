template <typename T, typename Alloc>
list<T, Alloc>::list(const alloc_type& alloc)
		: _head(NULL), _tail(NULL)
{
	std::cout << "[list] default\n";
}


// size
template <typename T, typename Alloc>
list<T, Alloc>::list(size_type n, const value_type& val, const alloc_type& alloc)
		: _head(NULL), _tail(NULL)
{
	node_pointer temp;

	this->make_nodes_at_back(n, val);
	// old
	/*
	temp = this->make_nodes(n, val);
	add_node_at_head(temp);
	temp = temp->tail();
	add_node_at_tail(temp);
	*/
	// new
}

// copy
template <typename T, typename Alloc>
list<T, Alloc>::list(const list& src) : _head(NULL), _tail(NULL)
{
	node_pointer temp;
	/*
	temp = this->copy_node(src._head, src._tail);
	add_node_at_head(temp);
	temp = temp->tail();
	add_node_at_tail(temp);
	*/
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
/*
template <typename T, typename Alloc>
typename list<T, Alloc>::iterator	list<T, Alloc>::begin()
{
}

template <typename T, typename Alloc>
typename list<T, Alloc>::iterator	list<T, Alloc>::begin()
{
}
*/
/* private function*/
/*template <typename T, typename Alloc>
void	list<T, Alloc>::add_node_at_tail(node_pointer& new_node)
{
	if (_tail)
		this->link_node(_tail, new_node);
	_tail = new_node;
}

template <typename T, typename Alloc>
void	list<T, Alloc>::add_node_at_head(node_pointer& new_node)
{
	if (_head)
		this->link_node(new_node, _head);
	_head = new_node;
}
*/

/*
template <typename T, typename Alloc>

template <typename T, typename Alloc>

template <typename T, typename Alloc>

template <typename T, typename Alloc>

template <typename T, typename Alloc>

template <typename T, typename Alloc>

template <typename T, typename Alloc>
*/


/* 
** list_base 
*/

template <typename T, typename Alloc>
list_base<T, Alloc>::list_base()
{
	//std::cout << "[base] default\n";
}
template <typename T, typename Alloc>
list_base<T, Alloc>::list_base(const list_base& src)
{
	//std::cout << "[base] copy\n";
}
template <typename T, typename Alloc>
list_base<T, Alloc>::~list_base()
{
	//std::cout << "[base] destructor\n";
}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer list_base<T, Alloc>::make_one_node(const value_type& val)
{
	node_pointer new_node;

	new_node = node_alloc.allocate(1);
	node_alloc.construct(new_node, val);
	return (new_node);
}

template <typename T, typename Alloc>
typename list_base<T, Alloc>::node_pointer list_base<T, Alloc>::make_nodes_at_back(size_type n, const value_type& val)
{
	node_pointer cur_node = NULL;
	node_pointer prev_node = NULL;

	cur_node = make_one_node(val);
	link_node(_end->_prev, cur_node);
	prev_node = cur_node;
	for (size_type i = 0 ; i < n - 1 ; ++i)
	{
		cur_node = make_one_node(val);
		link_node(prev_node, cur_node);
		prev_node = cur_node;
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
typename list_base<T, Alloc>::node_pointer	list_base<T, Alloc>::delete_one_node(node_pointer& nd)
{
	node_pointer prev_node;
	node_pointer next_node;

	prev_node = nd->_prev;
	next_node = nd->_next;

	destruct_node(nd);
	link_node(prev_node, next_node);
	/*
	if  (prev_node && next_node)
		link_node(prev_node, next_node);
	else if (!prev_node)
		next_node->_prev = NULL;
	else if (!next_node)
		prev_node->_next = NULL;
	return (next_node);
	*/
}

template <typename T, typename Alloc>
void	list_base<T, Alloc>::destruct_node(node_pointer& nd)
{
	node_alloc.destroy(nd);
}

//entire
template <typename T, typename Alloc>
typename list_base<T,Alloc>::node_pointer list_base<T, Alloc>::copy_node(const node_pointer& nd)
{
	node_pointer new_node;
	
	new_node = make_one_node(nd->_val);
	return (new_node);
}

//range
template <typename T, typename Alloc>
typename list_base<T,Alloc>::node_pointer list_base<T, Alloc>::copy_node(const node_pointer& head, const node_pointer& tail)
{
	node_pointer new_node = NULL;
	node_pointer cur_node = NULL;
	node_pointer prev_node = NULL;

	for (node_pointer pos = head ; pos != _end ; ++pos)
	{
		cur_node = make_one_node(pos->_val);
		if (!prev_node)
			new_node = cur_node;
		else
			link_node(prev_node, cur_node);
		prev_node = cur_node;
	}
	return (new_node);
}

/*
template <typename T, typename Alloc>
list_base<T, Alloc>
template <typename T, typename Alloc>
list_base<T, Alloc>
*/


