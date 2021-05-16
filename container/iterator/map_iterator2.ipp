/*
** Member function : Coplien's form
*/
template <typename _Iters>
map_iterator<_Iters>::map_iterator() : _ptr(0) {}

template <typename _Iters>
map_iterator<_Iters>::~map_iterator(){}
	
template <typename _Iters>
map_iterator<_Iters>::map_iterator(iterator_type const& src) : _ptr(src) {}


template <typename _Iters>
map_iterator<_Iters>::map_iterator(map_iterator const& rhs)
{
	_ptr = rhs._ptr;
}

template <typename _Iters>
map_iterator<_Iters>&	map_iterator<_Iters>::operator=(map_iterator const& rhs)
{
	if (this != &rhs)
		this->_ptr = rhs._ptr;
	return (*this);
}

/*
** Member function
*/
template <typename _Iters>
typename map_iterator<_Iters>::reference			map_iterator<_Iters>::operator*() const 
{
	return (_ptr->data);
}

template <typename _Iters>
bool	map_iterator<_Iters>::isRchild(iterator_type const& node)
{
	iterator_type rchild;

	rchild = node->Parent->Rchild;
	if (rchild)
	{
		if (rchild == node)
			return (true);
	}
	return (false);
}
template <typename _Iters>
bool	map_iterator<_Iters>::isLchild(iterator_type const& node)
{
	iterator_type lchild;

	lchild = node->Parent->Lchild;
	if (lchild)
	{
		if (lchild == node)
			return (true);
	}
	return (false);
}

template <typename _Iters>
map_iterator<_Iters>&	map_iterator<_Iters>::operator--()
{
	iterator_type pos;

	if (_ptr->Lchild)
		_ptr = _ptr->Lchild;
	else
	{
		for (pos = _ptr ; pos && !isRchild(pos) ; )
		{
			pos = pos->Parent;
		}
		if (pos)
			_ptr = pos->Parent;
	}
	return (*this);
}

template <typename _Iters>
map_iterator<_Iters>		map_iterator<_Iters>::operator--(int) 
{
	map_iterator ret(*this);
	_ptr = _ptr->_next;
	return (ret);
}


template <typename _Iters>
typename map_iterator<_Iters>::iterator_type map_iterator<_Iters>::left(iterator_type const& hint)
{
	iterator_type pos = hint;

	while (pos->Lchild)
		pos = pos->Lchild;
	return (pos);
}
template <typename _Iters>
map_iterator<_Iters>&	map_iterator<_Iters>::operator++() 
{
	iterator_type pos;

	if (_ptr->Rchild)
		_ptr = left(_ptr->Rchild);
	else
	{
		pos = _ptr;
		while (pos && !isLchild(pos))
			pos = pos->Parent;
		if (pos)
			_ptr = pos->Parent;
	}
	return (*this);

}

template <typename _Iters>
map_iterator<_Iters>		map_iterator<_Iters>::operator++(int) 
{
	map_iterator ret(*this);
	iterator_type pos;

	if (_ptr->Rchild)
		_ptr = left(_ptr->Rchild);
	else
	{
		pos = _ptr;
		while (pos && !isLchild(pos))
			pos = pos->Parent;
		if (pos)
			_ptr = pos->Parent;
	}
	return (*this);
}

template <typename _Iters>
typename map_iterator<_Iters>::pointer		map_iterator<_Iters>::operator->()	
{
	return (&(_ptr->_val)); 
}
/*
** Mon member function : operator
*/

/*
template <typename T, typename U>
bool	operator==(map_iterator<T> const& lhs, map_iterator<U> const& rhs)
{
	return (lhs._ptr == rhs_ptr);
}

template <typename T, typename U>
bool	operator!=(map_iterator<T> const& lhs, map_iterator<U> const& rhs)
{
	return (lhs._ptr != rhs._ptr);
}
*/
