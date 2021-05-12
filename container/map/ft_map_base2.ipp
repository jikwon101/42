template <typename Key, typename T, typename Compare, typename Alloc>
map_base<Key, T, Compare, Alloc>::map_base()
		: _head(NULL), _size(0)
{}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer
	map_base<Key, T, Compare, Alloc>::construct_node(value_type const& val)
{
	node_allocator_type	alloc;
	node_pointer		res;

	res = alloc.allocate(1);
	alloc.construct(res, val);
	return (res);
}


template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer&
	map_base<Key, T, Compare, Alloc>::GrandParent(node_pointer const& src)
{
	return (src->Parent->Parent);
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer&
	map_base<Key, T, Compare, Alloc>::Sibling(node_pointer const& src)
{
	node_pointer& parent = src->Parent;
	if (parent->Rchild == src)
		return (parent->Lchild);
	return (parent->Rchild);
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer&
	map_base<Key, T, Compare, Alloc>::Uncle(node_pointer const& src)
{
	return (Sibling(src->Parent));
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::pointer
	map_base<Key, T, Compare, Alloc>::find_key(key_type const& k) const
{
	node_pointer	pos;
	key_compare		comp;

	pos = _head;
	while (pos && pos->data.first != k)
	{
		if (comp(k, pos->data.first))
			pos = pos->Lchild;
		else
			pos = pos->Rchild;
	}
	if (!pos)
		return (NULL);
	return (&pos->data);
}


template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::insert_node(node_pointer& new_node)
{
	node_pointer	parent;
	node_pointer	pos;
	key_compare		comp;

	pos = _head;
	if (!(parent == pos))
	{
		// new_node->prev 
			// 아예 함수 하나로 뺼까? settoHeader?
		_head = new_node;
		new_node->color = BLACK;
	}
	while (pos)
	{
		parent = pos;
		if (comp(pos->data.first, new_node->data.first))
			pos = pos->Rchild;
		else
			pos = pos->Lchild;
	}
	new_node->Parent = parent;
	if (comp(parent->data.first, new_node->data.first))
		parent->Rchild = new_node;
	else
		parent->Lchild = new_node;
	return ;
}

/*
template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::
	map_base<Key, T, Compare, Alloc>::
{}
*/
