template <typename T, typename Compare, typename Alloc>
set_base<T, Compare, Alloc>::set_base(allocator_type const& alloc)
		: _head(NULL), _headnext(NULL), _size(0)
{
	(void)alloc;
	node_pointer _this = reinterpret_cast<node_pointer>(&_head);
	_head = _headnext = _this;
}

template <typename T, typename Compare, typename Alloc>
set_base<T, Compare, Alloc>::~set_base() 
{
	clear_node();
}

template <typename T, typename Compare, typename Alloc>
set_base<T, Compare, Alloc>::set_base(set_base const& x) 
{
	node_pointer	pos;
	
	_head = _headnext = end_node();
	if (!x._size)
		return ;
	pos = x.Farleft_after(x._head);
	while (pos != x.end_node())
	{
		add_node(pos);
		x.next_node(pos);
	}
}

template <typename T, typename Compare, typename Alloc>
set_base<T, Compare, Alloc>&	set_base<T, Compare, Alloc>::operator=(set_base const& x) 
{
	if (this != &x)
	{
		node_pointer	pos;

		clear_node();
		if (!x._size)
			return ;
		pos = x.Farleft_after(x._head);
		while (pos != x.end_node())
		{
			add_node(pos);
			x.next_node(pos);
		}
	}
	return (*this);
}

template <typename T, typename Compare, typename Alloc>
void
	set_base<T, Compare, Alloc>::clear_node() 
{
	node_pointer	pos;

	while (_size)
	{
		pos = least_leaf();
		erase_node(pos, false);
	}
	_head = _headnext = end_node();
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::construct_node(value_type const& val)
{
	node_allocator_type	alloc;
	node_pointer		res;

	res = alloc.allocate(1);
	alloc.construct(res, val);
	return (res);
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::GrandParent(node_pointer const& src) const
{
	return (src->Parent->Parent);
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::Sibling(node_pointer const& src) const
{
	node_pointer& parent = src->Parent;
	if (parent->Rchild == src)
		return (parent->Lchild);
	return (parent->Rchild);
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::Uncle(node_pointer const& src) const
{
	return (Sibling(src->Parent));
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::find_key(key_type const& k) const
{
	node_pointer	pos;
	key_compare		comp;

	if (!_size)
		return (end_node());
	pos = _head;
	while (pos)
	{
		if (k == pos->data)
			return (pos);
		if (comp(k, pos->data))
			pos = pos->Lchild;
		else
			pos = pos->Rchild;
	}
	return (end_node());
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::find_key(key_type const& k, node_pointer const& start) const
{
	node_pointer	pos;
	key_compare		comp;

	if (!_size)
		return (end_node());
	pos = start;
	while (pos)
	{
		if (k == pos->data)
			return (pos);
		if (comp(k, pos->data))
			pos = pos->Lchild;
		else
			pos = pos->Rchild;
	}
	return (end_node());
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::end_node() const
{
	if (!_size)
		return (_head);
	return (_head->Parent);
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::next_node(node_pointer const& x) const
{
	node_pointer pos;
	node_pointer	temp;

	pos = x;
	if (pos->Rchild)
		pos = Farleft_after(pos->Rchild);
	else if (pos != _head)
	{	
		temp = pos;
		while (temp->Parent != _head && !isLchild(temp))
			temp = temp->Parent;
		if (isLchild(temp))
			pos = temp->Parent;
	}
	return (pos);

}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::prev_node(node_pointer const& x) const
{	
	node_pointer pos;
	node_pointer	temp;

	pos = x;
	if (pos->Lchild)
		pos = Farright_after(pos->Lchild);
	else
	{	
		temp = pos;
		while (temp->Parent != _head && isLchild(temp))
			temp = temp->Parent;
		if (!isLchild(temp))
			pos = temp->Parent;
	}
	return (pos);
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::find_lower_bound(key_type const& k) const
{	
	node_pointer	pos;
	node_pointer	prev;
	key_compare		comp;
	bool			res;
	bool			prevres;
	bool			begin;

	pos = _head;
	begin = comp(k, pos->data);
	res = prevres = comp(k, pos->data);
	while(res == prevres)
	{
		prevres = res;
		prev = pos;
		if ((res = comp(k, pos->data)))
			pos = prev_node(pos);
		else if (comp(pos->data, k))
			pos = next_node(pos);
		else
			return (pos);
		if (res && prev == pos)
			break;
		else if (prev == pos)
			return (end_node());
	}
	if (begin)
		return (pos);
	return (next_node(pos));
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::find_upper_bound(key_type const& k) const
{		
	node_pointer	pos;
	node_pointer	prev;
	key_compare		comp;
	
	pos = Farleft_after(_head);
	while (!comp(k, pos->data))
	{
		prev = pos;
		pos = next_node(pos);
		if (prev == pos)
			return (end_node());
		if (k == prev->data)
			break;
	}
	return (pos);
}

template <typename T, typename Compare, typename Alloc>
ft::pair<bool, typename set_base<T, Compare, Alloc>::node_pointer>
	set_base<T, Compare, Alloc>::check_position(key_type const& k, node_pointer const& hint) const
{
	node_pointer	pos;
	key_compare		comp;

	pos = hint;
	if (comp(pos->data, _head->data))
	{
		while (comp(pos->data, k) && pos != _head)
			pos = pos->Parent;
		if (pos == _head)
			return (ft::pair<bool, node_pointer>(false, pos));
		else
			return (ft::pair<bool, node_pointer>(true, pos));
	}
	else
	{
		while (comp(k, pos->data) && pos != _head)
			pos = pos->Parent;
		if (pos == _head)
			return (ft::pair<bool, node_pointer>(false, pos));
		else
			return (ft::pair<bool, node_pointer>(true, pos));
	}
}


template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::set_to_head(node_pointer const& new_node)
{
	node_pointer _this;

	_this = reinterpret_cast<node_pointer>(&_head);
	if (new_node)
	{
		new_node->Parent = _this;
		_head = new_node;
		_headnext = new_node->Rchild ? new_node->Rchild : new_node;
	}
	else
		_head = _headnext = _this;
	return ;
}

template <typename T, typename Compare, typename Alloc>
void
	set_base<T, Compare, Alloc>::insert_node(node_pointer const& new_node)
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
		if ((isRchild = comp(pos->data, new_node->data)))
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

template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::insert_node(node_pointer const& new_node, node_pointer const& start)
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
		if ((isRchild = comp(pos->data, new_node->data)))
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

template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::recoloring(node_pointer const& x)
{
	Uncle(x)->color = BLACK;
	x->Parent->color = BLACK;
	if (GrandParent(x) != _head)
		GrandParent(x)->color = RED;
}

template <typename T, typename Compare, typename Alloc>
bool	
	set_base<T, Compare, Alloc>::isLchild(node_pointer const& x) const
{
	return (x == x->Parent->Lchild);
}


template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::attach_to_right(node_pointer const& x, node_pointer const& new_right)
{
	x->Rchild = new_right;
	if (new_right)
		new_right->Parent = x;
}
template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::attach_to_left(node_pointer const& x, node_pointer const& new_left)
{
	x->Lchild = new_left;
	if (new_left)
		new_left->Parent = x;
}

template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::rotate_to_left(node_pointer const x)
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

template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::rotate_to_right(node_pointer const x)
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

template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::swap_color(node_pointer const& x, node_pointer const& y)
{
	Color temp;

	temp = getColor(x);
	x->color = getColor(y);
	y->color = temp;
	if (_head == x)
		x->color = BLACK;
	if (_head == y)
		y->color = BLACK;
}

template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::restructuring1(node_pointer const& x)
{
	rotate_to_right(GrandParent(x));
	swap_color(x->Parent, Sibling(x));
	_head->color = BLACK;

}
template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::restructuring2(node_pointer const& x)
{
	rotate_to_left(x->Parent);
	restructuring1(x->Lchild);
}

template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::restructuring3(node_pointer const& x)
{
	rotate_to_right(x->Parent);
	restructuring4(x->Rchild);
}
template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::restructuring4(node_pointer const& x)
{
	rotate_to_left(GrandParent(x));
	swap_color(x->Parent, Sibling(x));
	_head->color = BLACK;
}
template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::check_double_red(node_pointer const& x)
{
	bool	status_parent;
	bool	status_x;

	if ((_head == x) || (getColor(x->Parent) == BLACK))
		return ;
	if (Uncle(x) && getColor(Uncle(x)) == RED)
	{
		recoloring(x);
		check_double_red(GrandParent(x));
	}
	else
	{
		status_parent = isLchild(x->Parent);
		status_x = isLchild(x);
		if (status_parent && status_x)			
			restructuring1(x);
		else if (status_parent && !status_x)	
			restructuring2(x);
		else if (!status_parent && status_x)	
			restructuring3(x);
		else									
			restructuring4(x);
	}
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::add_node(value_type const& val)
{
	node_pointer new_node;

	new_node = construct_node(val);
	insert_node(new_node);
	check_double_red(new_node);
	return (new_node);
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::add_node(value_type const& val, node_pointer const& position)
{
	node_pointer new_node;
	
	new_node = construct_node(val);
	insert_node(new_node, position);
	check_double_red(new_node);
	return (new_node);
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::Farleft_after(node_pointer const& parent) const
{
	node_pointer pos;

	pos = parent;
	if (!_size)
		return (pos);
	while (pos->Lchild)
		pos = pos->Lchild;
	return (pos);
}
template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::Farright_after(node_pointer const& parent) const
{
	node_pointer pos;

	pos = parent;
	while (pos->Rchild)
		pos = pos->Rchild;
	return (pos);
}

template <typename T, typename Compare, typename Alloc>
void
	set_base<T, Compare, Alloc>::destroy_node(node_pointer const& node)
{
	node_allocator_type destructor;

	destructor.destroy(node);
	destructor.deallocate(node, 1);
	_size--;
}

template <typename T, typename Compare, typename Alloc>
void
	set_base<T, Compare, Alloc>::relink(node_pointer const& p, node_pointer const& c, bool isLchild)
{
	if (isLchild)
		p->Lchild = c;
	else
		p->Rchild = c;
	if (c)
		c->Parent = p;
}

template <typename T, typename Compare, typename Alloc>
Color
	set_base<T, Compare, Alloc>::getColor(node_pointer const& node)
{
	if (!node)
		return (BLACK);
	return (node->color);
}

template <typename T, typename Compare, typename Alloc>
void
	set_base<T, Compare, Alloc>::erase_node(node_pointer const& x, bool check)
{
	node_pointer	target;
	node_pointer	temp;
	node_pointer	sibling;
	bool			isDoubleBlack;
	bool			isHead;

	target = x;
	if (_size == 1)
	{
		destroy_node(target);
		set_to_head(NULL);
		return ;
	}
	if (target->Rchild && target->Lchild)
	{
		isHead = (target == _head);
		temp = Farleft_after(target->Rchild);
		switch_node(target, temp);
		if (isHead)
			set_to_head(temp);
	}
	sibling = Sibling(target);
	temp = target->Rchild ? target->Rchild : target->Lchild;
	isDoubleBlack = (getColor(target) == getColor(temp));
	relink(target->Parent, temp, isLchild(target));
	destroy_node(target);
	if (!check)
		return ;
	if (temp && !isDoubleBlack)
		temp->color = BLACK;
	else if (isDoubleBlack)
	{
		if (getColor(sibling) == RED)
			sibling = case_change(sibling);
		check_double_black(temp, sibling);
	}
}

template <typename T, typename Compare, typename Alloc>
void
	set_base<T, Compare, Alloc>::check_double_black(node_pointer const& x, node_pointer const& sibling)
{
	node_pointer pos;

	pos = x;
	if (!isLchild(sibling) && getColor(sibling->Rchild) == RED)
		caseA(sibling);
	else if (!isLchild(sibling) && getColor(sibling->Lchild) == RED)
		caseB(sibling);
	else if (isLchild(sibling) && getColor(sibling->Lchild) == RED)
		caseA(sibling);
	else if (isLchild(sibling) && getColor(sibling->Rchild) == RED)
		caseB(sibling);
	else
		caseC(sibling);
	return ;
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::case_change(node_pointer const& sibling)
{
	node_pointer new_sibling;

	sibling->color = BLACK;
	sibling->Parent->color = RED;
	if (isLchild(sibling))
	{
		new_sibling = sibling->Rchild;
		rotate_to_right(sibling->Parent);
	}
	else
	{
		new_sibling = sibling->Lchild;
		rotate_to_left(sibling->Parent);
	}
	return (new_sibling);
}

template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::caseA(node_pointer const& sibling)
{
	sibling->color = sibling->Parent->color;
	sibling->Parent->color = BLACK;
	if (isLchild(sibling))
	{
		sibling->Lchild->color = BLACK;
		rotate_to_right(sibling->Parent);
	}
	else
	{
		sibling->Rchild->color = BLACK;
		rotate_to_left(sibling->Parent);
	}
}

template <typename T, typename Compare, typename Alloc>
void
	set_base<T, Compare, Alloc>::caseB(node_pointer const& sibling)
{
	sibling->color = RED;
	if (isLchild(sibling))
	{
		sibling->Rchild->color = BLACK;
		rotate_to_left(sibling);
	}
	else
	{
		sibling->Lchild->color = BLACK;
		rotate_to_right(sibling);
	}
}
template <typename T, typename Compare, typename Alloc>
void
	set_base<T, Compare, Alloc>::caseC(node_pointer const& sibling)
{
	sibling->color = RED;
	if (sibling->Parent->color == RED)
		sibling->Parent->color = BLACK;
	else if (sibling->Parent == _head)
		return ;
	else
		check_double_black(sibling->Parent, Sibling(sibling->Parent));
}

template <typename T, typename Compare, typename Alloc>
void	
	set_base<T, Compare, Alloc>::switch_node(node_pointer const& x, node_pointer const& y)
{
	node_pointer	temp;
	Color			temp_color;
	
	if (x == y->Parent)
	{
		relink(x->Parent, y, isLchild(x));
		if (isLchild(x))
		{
			temp = y->Lchild;
			relink(y, x, true);
			relink(x, temp, true);
			temp = y->Rchild;
			relink(y, x->Rchild, false);
			relink(x, temp, false);
		}
		else
		{
			temp = y->Rchild;
			relink(y, x, false);
			relink(x, temp, false);
			temp = y->Lchild;
			relink(y, x->Lchild, true);
			relink(x, temp, true);
		}
		temp_color = x->color;
		x->color = y->color;
		y->color = temp_color;
		return ;
	}
	if (x->Parent && isLchild(x))
		x->Parent->Lchild = y;
	else if (x->Parent)
		x->Parent->Rchild = y;
	else
		_head = y;

	if (x->Lchild)
		x->Lchild->Parent = y;
	if (x->Rchild)
		x->Rchild->Parent = y;

	if (y->Parent && isLchild(y))
		y->Parent->Lchild = x;
	else if (y->Parent)
		y->Parent->Rchild = x;
	else
		_head = x;
	
	if (y->Rchild)
		y->Rchild->Parent = x;
	if (y->Lchild)
		y->Lchild->Parent = x;

	temp = x->Parent;
	x->Parent = y->Parent;
	y->Parent = temp;

	temp = x->Rchild;
	x->Rchild = y->Rchild;
	y->Rchild = temp;
	temp = x->Lchild;
	x->Lchild = y->Lchild;
	y->Lchild = temp;
	temp_color = x->color;
	x->color = y->color;
	y->color = temp_color;
	return ;
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::node_pointer
	set_base<T, Compare, Alloc>::least_leaf()
{
	node_pointer pos;

	pos = Farleft_after(_head);
	while (pos)
	{
		if (!pos->Rchild && !pos->Lchild)
			return (pos);
		if (pos->Rchild)
			pos = Farleft_after(pos->Rchild);
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
	return (pos);
}

template <typename T, typename Compare, typename Alloc>
typename set_base<T, Compare, Alloc>::size_type
	set_base<T, Compare, Alloc>::maxsize() const
{
	return (node_allocator_type().max_size());
}
