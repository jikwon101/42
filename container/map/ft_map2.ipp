// default construct
template <typename Key, typename T, typename Compare, typename Alloc>
map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc) 
{
	std::cout << "default\n";
}


template <typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::mapped_type& map<Key, T, Compare, Alloc>::operator[] (const key_type& k)
{
	iterator res;

	res = this->find_key(k);
	if (res._ptr == NULL)
	{
		//std::cout << "Not in this containers\n"; //temp
		res = this->add_node(k);
		return (res._ptr->data.second);
	}
	//std::cout << "Already have\n"; //temp
	return (res._ptr->data.second);
}

template <typename Key, typename T, typename Compare, typename Alloc>
bool	map<Key, T, Compare, Alloc>::empty() const
{
	return (size() == 0);
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::size() const
{
	return (this->_size);
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::max_size() const
{
	// write
	return (this->_size);
}
template <typename Key, typename T, typename Compare, typename Alloc>
Pair<typename map<Key, T, Compare, Alloc>::iterator, bool>	
	map<Key, T, Compare, Alloc>::insert(const value_type& val)
{	
	iterator res;
	
	std::cout << "single\n";
	res = this->find_key(val.first);
	if (res._ptr == NULL)
	{
		//std::cout << "Not in this containers\n"; //temp
		res = this->add_node(val);
		return (Pair<iterator, bool>(res, true));
	}
	//std::cout << "Already have\n"; //temp
	return  (Pair<iterator, bool>(res, false));
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::iterator
	map<Key, T, Compare, Alloc>::insert(iterator position, const value_type& val)
{	
	ft::Pair<bool, node_pointer> type;
	iterator res;
	
	type = this->dist_type(val.first, position._ptr);
	if (type.first == false)
		res = this->find_key(val.first);
	else
		res = this->find_key(val.first, type.second);
	if (res._ptr == NULL)
	{
		//std::cout << "Not in this containers\n"; //temp
		if (type.first == false)
			res = this->add_node(val);
		else
			res = this->add_node(val, type.second);
			//res = this->add_node(val, position._ptr);
		return (res);
	}
	//std::cout << "Already have\n"; //temp
	return (res);
}

template <typename Key, typename T, typename Compare, typename Alloc>
template <typename InputIt>
void
	map<Key, T, Compare, Alloc>::insert(InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type*)
{
	for (InputIt pos = first ; pos != last ; ++pos)
	{
		insert(*pos);
	}
}
template <typename Key, typename T, typename Compare, typename Alloc>
void	map<Key, T, Compare, Alloc>::swap(map& x)
{
	// write;
}

template <typename Key, typename T, typename Compare, typename Alloc>
void	map<Key, T, Compare, Alloc>::clear()
{
	// write;
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::begin()
{
//	return (this->left());
	return (this->Farleft_after(this->_head));
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::end()
{
	return (this->_head->Parent);
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::find(key_type const& k)
{
	iterator res;

	res = this->find_key(k);
	return (res);
}

/*
template <typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator	map<Key, T, Compare, Alloc>::find(key_type const& k) const
{
	const_iterator res;

	res = this->find_key(k);
	return (res);
}
*/
template <typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::count(key_type const& k) const
{
	iterator res;

	res = this->find_key(k);
	if (!res._ptr)
		return (0);
	return (1);
}

//temp
template <typename Key, typename T, typename Compare, typename Alloc>
void	map<Key, T, Compare, Alloc>::printinfo()
{
	this->printcolor();
}

template <typename Key, typename T, typename Compare, typename Alloc>
void	map<Key, T, Compare, Alloc>::erase(iterator position)
{
	this->erase_node(position._ptr);
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::size_type		map<Key, T, Compare, Alloc>::erase(const key_type& k)
{
	iterator position;

	position = find(k);
	if (!position._ptr)
		return (0);
	this->erase_node(position._ptr);
	return (1);
}

template <typename Key, typename T, typename Compare, typename Alloc>
void	map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
{
	iterator target;
	iterator pos;

	for (pos = first; pos != last ; )
	{
		target = pos++;
		this->erase_node(target._ptr);
	}
}

/*
template <typename Key, typename T, typename Compare, typename Alloc>
map<Key, T, Compare, Alloc>::
{
}
*/
