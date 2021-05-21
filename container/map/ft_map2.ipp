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
	iterator res;

	res = this->find_key(val.first, position->_ptr);
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
typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::begin()
{
	return (this->left());
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::end()
{
	return (this->_head->Parent);
}

//temp
template <typename Key, typename T, typename Compare, typename Alloc>
void	map<Key, T, Compare, Alloc>::printinfo()
{
	this->printcolor();
}

/*
template <typename Key, typename T, typename Compare, typename Alloc>
map<Key, T, Compare, Alloc>::
{
}
*/
