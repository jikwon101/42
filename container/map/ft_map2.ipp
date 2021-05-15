// default construct
template <typename Key, typename T, typename Compare, typename Alloc>
map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc) 
{
	std::cout << "default\n";
}


template <typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::mapped_type& map<Key, T, Compare, Alloc>::operator[] (const key_type& k)
{
	pointer res;

	if (!(res = this->find_key(k)))
	{
		//insert new value; return;
		this->add_node(k);
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
template <typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::begin()
{
	return (this->left());
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
