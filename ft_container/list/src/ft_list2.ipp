template <typename T, typename Alloc>
list<T, Alloc>::list(const alloc_type& alloc) 
	: base(alloc)
{}

template <typename T, typename Alloc>
list<T, Alloc>::list(size_type n, const value_type& val, const alloc_type& alloc)
	: base(alloc)
{
	this->append_node_back(n, val);
}

template <typename T, typename Alloc>
list<T, Alloc>::list(const list& src)
	: base(src.get_allocator())
{
	this->append_node_back(src.begin(), src.end());
}

template <typename T, typename Alloc>
template <typename InputIt>
list<T, Alloc>::list(InputIt first, InputIt last, const alloc_type& alloc, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type*) 
	: base(alloc)
{
	this->append_node_back(first, last);
}

template <typename T, typename Alloc>
list<T, Alloc>::~list()
{
	clear();
}

template <typename T, typename Alloc>
list<T, Alloc>&		list<T, Alloc>::operator=(const list& src)
{
	if (this != &src)
	{
		clear();
		this->append_node_back(src.begin(), src.end());
	}
	return (*this);
}


template <typename T, typename Alloc>
typename list<T, Alloc>::alloc_type list<T, Alloc>::get_allocator() const
{
	return (alloc_type());
}

template <typename T, typename Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::begin()
{
	return (this->_head());
}

template <typename T, typename Alloc>
typename list<T, Alloc>::const_iterator list<T, Alloc>::begin() const
{
	return (this->_head());
}

template <typename T, typename Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::end()
{
	return (this->_end());
}

template <typename T, typename Alloc>
typename list<T, Alloc>::const_iterator list<T, Alloc>::end() const
{
	return (this->_end());
}

template <typename T, typename Alloc>
typename list<T, Alloc>::reverse_iterator list<T, Alloc>::rbegin()
{
	return (reverse_iterator(end()));
}

template <typename T, typename Alloc>
typename list<T, Alloc>::const_reverse_iterator list<T, Alloc>::rbegin() const
{
	return (reverse_iterator(end()));
}

template <typename T, typename Alloc>
typename list<T, Alloc>::reverse_iterator list<T, Alloc>::rend()
{
	return (reverse_iterator(begin()));
}

template <typename T, typename Alloc>
typename list<T, Alloc>::const_reverse_iterator list<T, Alloc>::rend() const
{
	return (reverse_iterator(begin()));
}

template <typename T, typename Alloc>
typename list<T, Alloc>::reference	list<T, Alloc>::front()
{
	return (this->_head()->_val);
}

template <typename T, typename Alloc>
typename list<T, Alloc>::const_reference	list<T, Alloc>::front() const
{
	return (this->_head()->_val);
}
template <typename T, typename Alloc>
typename list<T, Alloc>::reference	list<T, Alloc>::back()
{
	return (this->_tail()->_val);
}
template <typename T, typename Alloc>
typename list<T, Alloc>::const_reference	list<T, Alloc>::back() const
{
	return (this->_tail()->_val);
}

template <typename T, typename Alloc>
bool	list<T, Alloc>::empty() const
{
	return (size() == 0);
}
template <typename T, typename Alloc>
typename list<T, Alloc>::size_type list<T, Alloc>::size() const
{
	return (this->get_size());
}

template <typename T, typename Alloc>
typename list<T, Alloc>::size_type list<T, Alloc>::max_size() const
{
	return (ft::min<size_type>(std::numeric_limits<difference_type>::max(),this->_max_size()));
}

template <typename T, typename Alloc>
void	list<T, Alloc>::assign(size_type n, const value_type& val)
{
	clear();
	this->append_node_back(n, val);
}

template <typename T, typename Alloc>
template <typename InputIt>
void	list<T, Alloc>::assign(InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type* )
{
	clear();
	this->append_node_back(first, last);
}

template <typename T, typename Alloc>
void	list<T, Alloc>::push_front(const value_type& val)
{
	this->append_node_front(1, val);
}
template <typename T, typename Alloc>
void	list<T, Alloc>::push_back(const value_type& val)
{
	this->append_node_back(1, val);
}

template <typename T, typename Alloc>
void	list<T, Alloc>::pop_front()
{
	node_pointer head_node;

	head_node = this->_head();
	this->delete_one_node(head_node);
}

template <typename T, typename Alloc>
void	list<T, Alloc>::pop_back()
{
	node_pointer tail_node;

	tail_node = this->_tail();
	this->delete_one_node(tail_node);
}

template <typename T, typename Alloc>
typename list<T, Alloc>::iterator	list<T, Alloc>::insert(iterator position, const value_type& val)
{
	node_pointer new_node;

	new_node = this->make_one_node(val);
	this->insert_node_front(position._ptr, new_node, 1);
	return (new_node);
}

template <typename T, typename Alloc>
void	list<T, Alloc>::insert(iterator position, size_type n,const value_type& val)
{
	node_pointer new_node;
	
	new_node = this->make_nodes(n, val);
	this->insert_node_front(position._ptr, new_node, n);
}

template <typename T, typename Alloc>
template <typename InputIt>
void	list<T, Alloc>::insert(iterator position, InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type* )
{
	node_pointer new_node;
	size_type n;

	if (first == last)
		return ;
	n = ft::distance(first, last);
	new_node = this->make_nodes(first, last);
	this->insert_node_front(position._ptr, new_node, n);
}

template <typename T, typename Alloc>
typename list<T, Alloc>::iterator	list<T, Alloc>::erase(iterator position)
{
	node_pointer& pos = position._ptr;
	return (this->delete_one_node(pos));
}

template <typename T, typename Alloc>
typename list<T, Alloc>::iterator	list<T, Alloc>::erase(iterator first, iterator last)
{
	if (first == last)
		return (last);
	node_pointer& _first = first._ptr;
	node_pointer& _last = last._ptr;
	return (this->delete_nodes(_first, _last));
}

template <typename T, typename Alloc>
void	list<T, Alloc>::swap(list& x)
{
	if (this == &x)
		return ;
	this->swap_base(x);
}

template <typename T, typename Alloc>
void	list<T, Alloc>::resize(size_type n, value_type val)
{
	if (size() == n)
		return ;
	if (size() > n)
	{
		while (size() > n)
			pop_back();
	}
	else
	{
		while (size() < n)
			push_back(val);
	}
}

template <typename T, typename Alloc>
void	list<T, Alloc>::clear()
{
	node_pointer end_node;
	node_pointer head_node;

	if (!size())
		return ;
	head_node = this->_head();
	end_node = this->_end();
	this->delete_nodes(head_node, end_node);
}

template <typename T, typename Alloc>
void	list<T, Alloc>::splice(iterator position, list& x)
{
	node_pointer new_node;
	size_type n;

	n = x.size();
	new_node = x.extract_node(x._head(), x._end());
	this->insert_node_front(position._ptr, new_node, n);
}

template <typename T, typename Alloc>
void	list<T, Alloc>::splice(iterator position, list& x, iterator i)
{
	node_pointer new_node;
	size_type n;
	
	n = x.size() - 1;
	new_node = x.extract_node(i._ptr, i._ptr->_next);
	this->insert_node_front(position._ptr, new_node, n);
}

template <typename T, typename Alloc>
void	list<T, Alloc>::splice(iterator position, list& x, iterator first, iterator last)
{
	node_pointer new_node;
	size_type n;

	n = x.size();
	new_node = x.extract_node(first._ptr, last._ptr);
	n -= x.size();
	this->insert_node_front(position._ptr, new_node, n);
}


template <typename T, typename Alloc>
void	list<T, Alloc>::remove(const value_type& val)
{
	node_pointer pos;

	pos = this->_head();
	while (!this->isEnd(pos))
	{
		if (pos->_val == val)
			pos = this->delete_one_node(pos);
		else
			pos = pos->_next;
	}
}

template <typename T, typename Alloc>
template <typename Predicate>
void	list<T, Alloc>::remove_if(Predicate pred)
{
	node_pointer pos;

	pos = this->_head();
	while (!this->isEnd(pos))
	{
		if (pred(pos->_val))
			pos = this->delete_one_node(pos);
		else
			pos = pos->_next;
	}
}

template <typename T, typename Alloc>
void	list<T, Alloc>::unique()
{	
	node_pointer pos;
	node_pointer search_pos;

	pos = this->_head();
	while (!this->isEnd(pos))
	{
		search_pos = pos->_next;
		while (!this->isEnd(search_pos) &&
				(pos->_val == search_pos->_val))
		{
			search_pos = this->delete_one_node(search_pos);
		}
		pos = pos->_next;
	}
}

template <typename T, typename Alloc>
template <typename BinaryPredicate>
void	list<T, Alloc>::unique(BinaryPredicate binary_pred)
{
	node_pointer pos;
	node_pointer search_pos;

	pos = this->_head();
	while (!this->isEnd(pos))
	{
		search_pos = pos->_next;
		while (!this->isEnd(search_pos) &&
				binary_pred(pos->_val, search_pos->_val))
		{
			search_pos = this->delete_one_node(search_pos);
		}
		pos = pos->_next;
	}
}

template <typename T, typename Alloc>
void	list<T, Alloc>::merge(list& x)
{
	node_pointer	pos;
	node_pointer	new_node;
	node_pointer	pos_x;
	size_type		n;

	if (this == &x)
		return ;
	pos = this->_head();
	pos_x = x._head();
	while (!x.isEnd(pos_x))
	{
		if (this->isEnd(pos))
		{
			n = x.size();
			new_node = x.extract_node(pos_x, x._end());
			n -= x.size();
			this->insert_node_front(pos, new_node, n);
			return ;
		}
		while (!x.isEnd(pos_x) && (pos_x->_val < pos->_val))
		{
			pos_x = pos_x->_next;
			n = x.size();
			new_node = x.extract_node(pos_x->_prev, pos_x);
			n -= x.size();
			this->insert_node_front(pos, new_node, n);
		}
		pos = pos->_next;
	}

}

template <typename T, typename Alloc>
template <typename Compare>
void	list<T, Alloc>::merge(list& x, Compare comp)
{
	node_pointer	pos;
	node_pointer	new_node;
	node_pointer	pos_x;
	size_type		n;

	if (this == &x)
		return ;
	pos = this->_head();
	pos_x = x._head();
	while (!x.isEnd(pos_x))
	{
		if (this->isEnd(pos))
		{
			n = x.size();
			new_node = x.extract_node(pos_x, x._end());
			n -= x.size();
			this->insert_node_front(pos, new_node, n);
			return ;
		}
		while (!x.isEnd(pos_x) && comp(pos_x->_val,pos->_val))
		{
			n = x.size();
			pos_x = pos_x->_next;
			new_node = x.extract_node(pos_x->_prev, pos_x);
			n -= x.size();
			this->insert_node_front(pos, new_node, n);
		}
		pos = pos->_next;
	}

}

template <typename T, typename Alloc>
void	list<T, Alloc>::sort()
{
	node_pointer	pos;
	node_pointer	new_node;
	node_pointer	search_pos;

	pos = this->_head()->_next;
	while (!this->isEnd(pos))
	{
		search_pos = pos->_prev;
		while (!this->isEnd(search_pos) &&
				(pos->_val < search_pos->_val))
		{
			while (!(this->isEnd(search_pos))
					&& (pos->_val < search_pos->_val))
				search_pos = search_pos->_prev;
			pos = pos->_prev;
			new_node = this->extract_node(pos->_next, pos->_next->_next);
			this->insert_node_back(search_pos, new_node, 1);
		}
		pos = pos->_next;
	}
}

template <typename T, typename Alloc>
template <typename Compare>
void	list<T, Alloc>::sort(Compare comp)
{	
	node_pointer	pos;
	node_pointer	new_node;
	node_pointer	search_pos;
	
	pos = this->_head()->_next;
	while (!this->isEnd(pos))
	{
		search_pos = pos->_prev;
		while (!this->isEnd(search_pos) &&
				(comp(pos->_val, search_pos->_val)))
		{
			while (!(this->isEnd(search_pos))
					&& (comp(pos->_val, search_pos->_val)))
				search_pos = search_pos->_prev;
			pos = pos->_prev;
			new_node = this->extract_node(pos->_next, pos->_next->_next);
			this->insert_node_back(search_pos, new_node, 1);
		}
		pos = pos->_next;
	}
}

template <typename T, typename Alloc>
void	list<T, Alloc>::reverse()
{
	node_pointer	temp_node;
	node_pointer	pos;

	if (!size())
		return ;
	for (pos = this->_head() ; !this->isEnd(pos) ; pos = temp_node)
	{
		temp_node = pos->_next;
		pos->_next = pos->_prev;
		pos->_prev = temp_node;
	}
	temp_node = pos->_next;
	pos->_next = pos->_prev;
	pos->_prev = temp_node;
}

template <typename T, typename Alloc>
void	swap(list<T, Alloc> &x, list<T, Alloc>& y)
{
	x.swap(y);
}

template <class T, class Alloc>
bool	operator== (const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs)
{
	typename ft::list<T, Alloc>::const_iterator lit;
	typename ft::list<T, Alloc>::const_iterator rit;

	if (lhs.size() != rhs.size())
		return (false);
	lit = lhs.begin();
	rit = rhs.begin();
	for (; lit != lhs.end() && rit != rhs.end();)
	{
		if (*lit != *rit)
			return (false);
		++lit;
		++rit;
	}
	return (true);
}

template <class T, class Alloc>
bool	operator!= (const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool	operator< (const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs)
{
	typename ft::list<T, Alloc>::const_iterator lit;
	typename ft::list<T, Alloc>::const_iterator rit;
		
	lit = lhs.begin();
	rit = rhs.begin();
	for (; lit != lhs.end() && rit != rhs.end();)
	{
		if (*lit < *rit)
			return (true);
		else if (*lit > *rit)
			return (false);
		++lit;
		++rit;
	}
	return (lhs.size() < rhs.size());
}

template <class T, class Alloc>
bool	operator<= (const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs)
{
	return (!(lhs > rhs));
}

template <class T, class Alloc>
bool	operator> (const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Alloc>
bool	operator>= (const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs)
{
	return (!(lhs < rhs));
}
