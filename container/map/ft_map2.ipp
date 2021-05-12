// default construct
template <typename Key, typename T, typename Compare, typename Alloc>
map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc) 
{
	std::cout << "default\n";
	value_type val(1, 3);
	node_pointer new_node;
	new_node = this->construct_node(val);
	this->insert_node(new_node);
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::mapped_type& map<Key, T, Compare, Alloc>::operator[] (const key_type& k)
{
	pointer res;

	if (!(res = this->find_key(k)))
	{
		//insert new value; return;
		std::cout << "Not in this container\n";
	}
	return (res->second);
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
void	map<Key, T, Compare, Alloc>::insert(const value_type& val)
{
}

/*
template <typename Key, typename T, typename Compare, typename Alloc>
map<Key, T, Compare, Alloc>::
{
}
*/
