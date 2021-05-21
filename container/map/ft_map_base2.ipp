template <typename Key, typename T, typename Compare, typename Alloc>
map_base<Key, T, Compare, Alloc>::map_base()
		: _head(NULL), _size(0), _headnext(NULL)
{
	node_pointer _this = reinterpret_cast<node_pointer>(&_head);
	_head = _this;
	_headnext = _head;
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
}

template <typename Key, typename T, typename Compare, typename Alloc>
typename map_base<Key, T, Compare, Alloc>::node_pointer
	map_base<Key, T, Compare, Alloc>::find_key(key_type const& k, node_pointer const& start) const
{
	node_pointer	pos;
	key_compare		comp;

	if (!_size)
		return (NULL);
	pos = start;
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
ft::Pair<bool, typename map_base<Key, T, Compare, Alloc>::node_pointer>
	map_base<Key, T, Compare, Alloc>::dist_type(key_type const& k, node_pointer const& hint) const
{
	node_pointer	pos;
	key_compare		comp;

	pos = hint;
	if (comp(pos->data.first, _head->data.first))
	{
		// find larger : pos > k
		while (comp(pos->data.first, k) && pos != _head)
			pos = pos->Parent;
		if (pos == _head)
			return (ft::Pair<bool, node_pointer>(false, pos));
		else
			return (ft::Pair<bool, node_pointer>(true, pos));
	}
	else
	{
		// find smaller : pos < k
		while (comp(k, pos->data.first) && pos != _head)
			pos = pos->Parent;
		if (pos == _head)
			return (ft::Pair<bool, node_pointer>(false, pos));
		else
			return (ft::Pair<bool, node_pointer>(true, pos));
	}
}


template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::set_to_head(node_pointer& new_node)
{
	new_node->Parent = _head->Parent;
	_head = new_node;
	//new_node->color = BLACK;
	_headnext = new_node->Rchild ? new_node->Rchild : new_node;
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
		new_node->Parent = _head;
		_head = _headnext = new_node;
		_head->color = BLACK;
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
void	map_base<Key, T, Compare, Alloc>::insert_node(node_pointer& new_node, node_pointer const& start)
{
	node_pointer	parent;
	node_pointer	pos;
	key_compare		comp;
	bool			isRchild;

	pos = start;
	if (!_size)
	{
		new_node->Parent = _head;
		_head = _headnext = new_node;
		_head->color = BLACK;
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
	return (x == x->Parent->Lchild);
}


template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::attach_to_right(node_pointer const& x, node_pointer const& new_right)
{
	x->Rchild = new_right;
	if (new_right)
		new_right->Parent = x;
}
template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::attach_to_left(node_pointer const& x, node_pointer const& new_left)
{
	x->Lchild = new_left;
	if (new_left)
		new_left->Parent = x;
}

template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::rotate_to_left(node_pointer const& x)
{
	node_pointer parent = x->Parent;
	node_pointer rchild = x->Rchild;

	if (x == _head)
		set_to_head(rchild);
	else if (isLchild(x))
		attach_to_left(parent, rchild);
	else	
		attach_to_right(parent, rchild);
	attach_to_right(x, rchild->Lchild);
	attach_to_left(rchild, x);
}

template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::rotate_to_right(node_pointer const& x)
{
	node_pointer parent = x->Parent;
	node_pointer lchild = x->Lchild;

	if (x == _head)
		set_to_head(lchild);
	else if (isLchild(x))	
		attach_to_left(parent, lchild);
	else
		attach_to_right(parent, lchild);
	attach_to_left(x, lchild->Rchild);
	attach_to_right(lchild, x);
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
	_head->color = BLACK;

}
template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::restructuring2(node_pointer const& x)
{
	//std::cout << "LR\n";
	rotate_to_left(Parent(x));
	restructuring1(x->Lchild);
	_head->color = BLACK;
}

template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::restructuring3(node_pointer const& x)
{
	//std::cout << "RL\n";
	rotate_to_right(Parent(x));
	restructuring4(x->Rchild);
	_head->color = BLACK;
}
template <typename Key, typename T, typename Compare, typename Alloc>
void	map_base<Key, T, Compare, Alloc>::restructuring4(node_pointer const& x)
{
	//std::cout << "RR\n";
	rotate_to_left(GrandParent(x));
	swap_color(Parent(x), Sibling(x));
	_head->color = BLACK;
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
		check_node(GrandParent(x));
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
	map_base<Key, T, Compare, Alloc>::add_node(value_type const& val, node_pointer const& position)
{
	node_pointer new_node;
//position
	new_node = construct_node(val);
	insert_node(new_node, position);
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
			while (temp && temp->Parent && !isLchild(temp))
				temp = temp->Parent;
			if (temp == _head)
				break;
			else if (temp)
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
