template <typename T, typename Compare, typename Alloc>
multiset<T, Compare, Alloc>::multiset(const key_compare& comp, const allocator_type& alloc)  : base(alloc)
{
	(void)comp;
}

template <typename T, typename Compare, typename Alloc>
template <typename InputIt>
multiset<T, Compare, Alloc>::multiset(InputIt first, InputIt last, const key_compare& comp, const allocator_type& alloc, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type *) : base(alloc)
{
	(void)comp;
	insert(first, last);
}

template <typename T, typename Compare, typename Alloc>
multiset<T, Compare, Alloc>::multiset(const multiset& x) : base(x.get_allocator())
{
	insert(x.begin(), x.end());
}

template <typename T, typename Compare, typename Alloc>
multiset<T, Compare, Alloc>::~multiset()
{}

template <typename T, typename Compare, typename Alloc>
multiset<T, Compare, Alloc>&	multiset<T, Compare, Alloc>::operator=(const multiset& x)
{
	if (this != &x)
	{
		clear();
		insert(x.begin(), x.end());
	}
	return (*this);
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::allocator_type	multiset<T, Compare, Alloc>::get_allocator() const
{
	return (allocator_type());
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::iterator	multiset<T, Compare, Alloc>::begin()
{
	return (this->Farleft_after(this->_head));
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::const_iterator	multiset<T, Compare, Alloc>::begin() const
{
	return (this->Farleft_after(this->_head));
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::iterator	multiset<T, Compare, Alloc>::end()
{
	return (this->end_node());
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::const_iterator	multiset<T, Compare, Alloc>::end() const
{
	return (this->end_node());
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::reverse_iterator	multiset<T, Compare, Alloc>::rbegin()
{
	return (reverse_iterator(end()));
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::const_reverse_iterator	multiset<T, Compare, Alloc>::rbegin() const
{
	return (reverse_iterator(end()));
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::reverse_iterator	multiset<T, Compare, Alloc>::rend()
{
	return (reverse_iterator(begin()));
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::const_reverse_iterator	multiset<T, Compare, Alloc>::rend() const
{
	return (reverse_iterator(begin()));
}

template <typename T, typename Compare, typename Alloc>
bool	multiset<T, Compare, Alloc>::empty() const
{
	return (size() == 0);
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::size_type	multiset<T, Compare, Alloc>::size() const
{
	return (this->_size);
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::size_type	multiset<T, Compare, Alloc>::max_size() const
{
	return (ft::min<size_type>(std::numeric_limits<difference_type>::max(), this->maxsize()));
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::iterator
	multiset<T, Compare, Alloc>::insert(const value_type& val)
{	
	iterator res;
	
	res = this->add_node(val);
	return (res);	
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::iterator
	multiset<T, Compare, Alloc>::insert(iterator position, const value_type& val)
{	
	iterator res;
	
	if (position != end())
		res = this->add_node(val, position._ptr);
	else
		res = this->add_node(val);
	return (res);
}

template <typename T, typename Compare, typename Alloc>
template <typename InputIt>
void
	multiset<T, Compare, Alloc>::insert(InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type*)
{
	for (InputIt pos = first ; pos != last ; ++pos)
	{
		insert(*pos);
	}
}

template <typename T, typename Compare, typename Alloc>
void	multiset<T, Compare, Alloc>::erase(iterator position)
{
	this->erase_node(position._ptr, true);
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::size_type		multiset<T, Compare, Alloc>::erase(const key_type& k)
{
	size_type	cnt;
	iterator position;

	cnt = 0;
	while ((position = find(k)) != end())
	{
		this->erase_node(position._ptr, true);
		cnt++;
	}
	return (cnt);
}

template <typename T, typename Compare, typename Alloc>
void	multiset<T, Compare, Alloc>::erase(iterator first, iterator last)
{
	iterator target;
	iterator pos;

	for (pos = first; pos != last ; )
	{
		target = pos++;
		this->erase_node(target._ptr, true);
	}
}

template <typename T, typename Compare, typename Alloc>
void	multiset<T, Compare, Alloc>::swap(multiset& x)
{
	node_pointer temp;
	size_type	tempsize;

	tempsize = x.size();
	temp = tempsize ? x._head : NULL;
	if (!this->_size)
		x.set_to_head(NULL);
	else
		x.set_to_head(this->_head);
	x._size = this->_size;
	this->set_to_head(temp);
	this->_size = tempsize;
}

template <typename T, typename Compare, typename Alloc>
void	multiset<T, Compare, Alloc>::clear()
{
	this->clear_node();
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::key_compare
	multiset<T, Compare, Alloc>::key_comp() const
{
	return (key_compare());
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::value_compare
	multiset<T, Compare, Alloc>::value_comp() const
{
	return (value_compare(key_compare()));
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::iterator	multiset<T, Compare, Alloc>::find(key_type const& k)
{
	iterator res;

	res = this->find_key(k);
	return (res);
}
template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::const_iterator	multiset<T, Compare, Alloc>::find(key_type const& k) const
{
	iterator res;

	res = this->find_key(k);
	return (res);
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::size_type	multiset<T, Compare, Alloc>::count(key_type const& k) const
{
	ft::pair<const_iterator, const_iterator> res;
	const_iterator pos;
	size_type cnt;

	cnt = 0;
	res = equal_range(k);
	pos = res.first;
	while (pos != res.second)
	{
		cnt++;
		++pos;
	}
	return (cnt);
}


template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::iterator
		multiset<T, Compare, Alloc>::lower_bound(const key_type& k)
{
	if (!size())
		return (end());
	return (this->find_lower_bound(k));
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::const_iterator
		multiset<T, Compare, Alloc>::lower_bound(const key_type& k) const
{
	if (!size())
		return (end());
	return (this->find_lower_bound(k));
}

template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::iterator
		multiset<T, Compare, Alloc>::upper_bound(const key_type& k)
{
	if (!size())
		return (end());
	return (this->find_upper_bound(k));
}
template <typename T, typename Compare, typename Alloc>
typename multiset<T, Compare, Alloc>::const_iterator
		multiset<T, Compare, Alloc>::upper_bound(const key_type& k) const
{
	if (!size())
		return (end());
	return (this->find_upper_bound(k));
}

template <typename T, typename Compare, typename Alloc>
ft::pair<typename multiset<T, Compare, Alloc>::iterator, typename multiset<T, Compare, Alloc>::iterator>
		multiset<T, Compare, Alloc>::equal_range(const key_type& k)
{
	return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
}

template <typename T, typename Compare, typename Alloc>
ft::pair<typename multiset<T, Compare, Alloc>::const_iterator, typename multiset<T, Compare, Alloc>::const_iterator>
		multiset<T, Compare, Alloc>::equal_range(const key_type& k) const
{
	return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
}

template <typename T, typename Compare, typename Alloc>
bool	operator==(const multiset<T, Compare, Alloc>& lhs, const multiset<T, Compare, Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	{
		typename multiset<T, Compare, Alloc>::const_iterator lit;
		typename multiset<T, Compare, Alloc>::const_iterator rit;
		
		lit = lhs.begin();
		rit = rhs.begin();
		while (lit != lhs.end())
		{
			if (*lit != *rit)
				return (false);
			++lit;
			++rit;
		}
	}
	return (true);
}
template <typename T, typename Compare, typename Alloc>
bool	operator!=(const multiset<T, Compare, Alloc>& lhs, const multiset<T, Compare, Alloc>& rhs)
{
	return (!(lhs == rhs));
}
template <typename T, typename Compare, typename Alloc>
bool	operator<(const multiset<T, Compare, Alloc>& lhs, const multiset<T, Compare, Alloc>& rhs)
{
	typename multiset<T, Compare, Alloc>::const_iterator lit;
	typename multiset<T, Compare, Alloc>::const_iterator rit;
	
	lit = lhs.begin();
	rit = rhs.begin();
	while (lit != lhs.end() && rit != rhs.end())
	{
		if (*lit < *rit)
			return (true);
		if (*lit > *rit)
			return (false);
		++lit;
		++rit;
	}
	if (lit != lhs.end())
		return (false);
	return (true);
}

template <typename T, typename Compare, typename Alloc>
bool	operator<=(const multiset<T, Compare, Alloc>& lhs, const multiset<T, Compare, Alloc>& rhs)
{
	return (!(lhs > rhs));
}

template <typename T, typename Compare, typename Alloc>
bool	operator>(const multiset<T, Compare, Alloc>& lhs, const multiset<T, Compare, Alloc>& rhs)
{
	return (rhs < lhs);
}

template <typename T, typename Compare, typename Alloc>
bool	operator>=(const multiset<T, Compare, Alloc>& lhs, const multiset<T, Compare, Alloc>& rhs)
{
	return (!(lhs < rhs));
}
