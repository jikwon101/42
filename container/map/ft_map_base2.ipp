template <typename Key, typename T, typename Compare, typename Alloc>
map_base<Key, T, Compare, Alloc>::map_base()
		: _head(NULL), _size(0)
{
	node_pointer _this = reinterpret_cast<node_pointer>(&_head);
	_head = _this;
}

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
typename map_base<Key, T, Compare, Alloc>::val_maker	map_base<Key, T, Compare, Alloc>::get_val_maker()
{
	return (make_pair<const key_type, mapped_type>);
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer
	map_base<Key, T, Compare, Alloc>::construct_node(key_type const& key)
{
	node_allocator_type	alloc;
	node_pointer		res;
	val_maker			maker;

	maker = get_val_maker();
	res = alloc.allocate(1);
	alloc.construct(res, maker(key, mapped_type()));
	return (res);
}


template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer
	map_base<Key, T, Compare, Alloc>::GrandParent(node_pointer const& src)
{
	return (src->Parent->Parent);
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer
	map_base<Key, T, Compare, Alloc>::Sibling(node_pointer const& src)
{
	node_pointer& parent = src->Parent;
	if (parent->Rchild == src)
		return (parent->Lchild);
	return (parent->Rchild);
}
template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer
	map_base<Key, T, Compare, Alloc>::Parent(node_pointer const& src)
{
	return (src->Parent);
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer
	map_base<Key, T, Compare, Alloc>::Uncle(node_pointer const& src)
{
	return (Sibling(src->Parent));
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer
	map_base<Key, T, Compare, Alloc>::find_key(key_type const& k) const
{
	node_pointer	pos;
	key_compare		comp;

	if (!_size)
		return (NULL);
	pos = _head;
	while (pos)
	{
		if (k == pos->data.first)
			return (pos);
		if (comp(k, pos->data.first))
			pos = pos->Lchild;
		else
			pos = pos->Rchild;
	}
	return (NULL);
	/*
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
	return (pos);
	*/
}
template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer
	map_base<Key, T, Compare, Alloc>::find_key(key_type const& k, node_pointer const& hint) const
{
	node_pointer	pos;
	key_compare		comp;

	pos = hint;
	while (pos)
	{
		if (k == pos->data.first)
			return (pos);
		if (comp(k, pos->data.first))
			pos = pos->Lchild;
		else
			pos = pos->Rchild;
	}
	return (NULL);
}


template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::set_to_head(node_pointer& new_node)
{
	new_node->Parent = _head;
	_head = new_node;
	new_node->color = BLACK;
	//new_node->Parent = NULL;
	// new_color->prev = this?	//write
}

template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::insert_node(node_pointer& new_node)
{
	node_pointer	parent;
	node_pointer	pos;
	key_compare		comp;
	bool			isRchild;

	pos = _head;
	if (!_size)
	{
		set_to_head(new_node);
		_size++;
		return ;
	}
	while (pos)
	{
		parent = pos;
		if ((isRchild = comp(pos->data.first, new_node->data.first)))
			pos = pos->Rchild;
		else
			pos = pos->Lchild;
	}
	new_node->Parent = parent;
	if (isRchild)
		parent->Rchild = new_node;
	else
		parent->Lchild = new_node;
	_size++;
}

template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::recoloring(node_pointer const& x)
{
	//std::cout << "Recoloring\n";
	Uncle(x)->color = BLACK;
	x->Parent->color = BLACK;
	if (GrandParent(x) != _head)
		GrandParent(x)->color = RED;
}

template <typename Key, typename T, typename Compare, typename Alloc>
bool	map_base<Key, T, Compare, Alloc>::isLchild(node_pointer const& x)
{
	node_pointer lchild;
	
	if (!x->Parent)
		return (false);
	lchild = x->Parent->Lchild;
	return (lchild == x);
}

template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::rotate_to_left(node_pointer const& x)
{
	node_pointer parent = x->Parent;
	node_pointer rchild = x->Rchild;
	
	if (isLchild(x))
		parent->Lchild = rchild;
	else if (parent)
		parent->Rchild = rchild;
	rchild->Parent = parent;
	x->Parent = rchild;
	x->Rchild = rchild->Lchild;
	if (rchild->Lchild)
		rchild->Lchild->Parent = x;
	rchild->Lchild = x;
	if (!parent)
		_head = rchild;

	//parent->Rchild = rchild;
}

template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::rotate_to_right(node_pointer const& x)
{
	node_pointer parent = x->Parent;
	node_pointer lchild = x->Lchild;
		
	if (isLchild(x))
		parent->Lchild = lchild;
	else if (parent)
		parent->Rchild = lchild;
	lchild->Parent = parent;
	x->Parent = lchild;
	x->Lchild = lchild->Rchild;
	if (lchild->Rchild)
		lchild->Rchild->Parent = x;
	lchild->Rchild = x;
	if (!parent)
		_head = lchild;
}

template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::swap_color(node_pointer const& x, node_pointer const& y)
{
	Color temp;

	temp = x->color;
	x->color = y->color;
	y->color = temp;
	if (_head == x)
		x->color = BLACK;
	if (_head == y)
		y->color = BLACK;
}

template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::restructuring1(node_pointer const& x)
{
	//std::cout << "LL\n";
	rotate_to_right(GrandParent(x));
	swap_color(Parent(x), Sibling(x));

}
template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::restructuring2(node_pointer const& x)
{
	//std::cout << "LR\n";
	rotate_to_left(Parent(x));
	restructuring1(x->Lchild);
}

template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::restructuring3(node_pointer const& x)
{
	//std::cout << "RL\n";
	rotate_to_right(Parent(x));
	restructuring4(x->Rchild);
}
template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::restructuring4(node_pointer const& x)
{
	//std::cout << "RR\n";
	rotate_to_left(GrandParent(x));
	swap_color(Parent(x), Sibling(x));
}
template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::check_node(node_pointer const& x)
{
	bool	status_parent;
	bool	status_x;

	if ((_head == x) || (x->Parent->color == BLACK))
		return ;
	if (Uncle(x) && Uncle(x)->color == RED)
	{
		recoloring(x);
		check_node(GrandParent(x));	//if grandparent null ?
	}
	else
	{
		status_parent = isLchild(x->Parent);
		status_x = isLchild(x);
		if (status_parent && status_x)	//LL
			restructuring1(x);
		else if (status_parent && !status_x)	//LR
			restructuring2(x);
		else if (!status_parent && status_x) //RL
			restructuring3(x);
		else if (!status_parent && !status_x) // RR
			restructuring4(x);
		else
			std::cout << "no!!!!\n";	//temp
	}
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer
	map_base<Key, T, Compare, Alloc>::add_node(value_type const& val)
{
	node_pointer new_node;

	new_node = construct_node(val);
	insert_node(new_node);
	check_node(new_node);
	return (new_node);
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer
	map_base<Key, T, Compare, Alloc>::add_node(key_type const& key)
{
	node_pointer new_node;

	new_node = construct_node(key);
	insert_node(new_node);
	check_node(new_node);
	return (new_node);
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer
	map_base<Key, T, Compare, Alloc>::left()
{
	node_pointer pos;

	pos = _head;
	while (pos->Lchild)
		pos = pos->Lchild;
	return (pos);
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer
	map_base<Key, T, Compare, Alloc>::left(node_pointer const& hint)
{
	node_pointer pos = hint;

	while (pos->Lchild)
		pos = pos->Lchild;
	return (pos);
}

template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::node_info(node_pointer const& pos)
{	
	std::cout << "key : " << pos->data.first << ", value : " << pos->data.second <<", color: ";
	if (pos->color == BLACK)
		std::cout << "Blak";
	else
		std::cout << "Redd";

	std::cout << "L : ";
	if (pos->Lchild)
		std::cout << pos->Lchild->data.first << " " ;
	else
		std::cout << "nil";
	std::cout << " R : " ;
	if (pos->Rchild)
		std::cout << pos->Rchild->data.first << "\n";
	else
		std::cout << "nil\n";

}
template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::printcolor()
{
	node_pointer pos;
	
	std::cout << "head : "<< _head->data.first << std::endl;
	pos = left();
	while (pos)
	{
		node_info(pos);
		if (pos->Rchild)
			pos = left(pos->Rchild);
		else
		{
			node_pointer temp = pos;
			while (temp && !isLchild(temp))
				temp = temp->Parent;
			if (temp)
				pos = temp->Parent;
			else
				pos = temp;
		}
	}
}
/*
template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::
	map_base<Key, T, Compare, Alloc>::
{}
*/
