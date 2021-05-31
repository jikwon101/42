/*
** Member function : Coplien's form
*/
template <typename _Iters>
map_const_iterator<_Iters>::map_const_iterator() : _ptr(0) {}

template <typename _Iters>
map_const_iterator<_Iters>::~map_const_iterator(){}
	
template <typename _Iters>
map_const_iterator<_Iters>::map_const_iterator(iterator_type const& src) : _ptr(src) {}


template <typename _Iters>
map_const_iterator<_Iters>::map_const_iterator(map_const_iterator const& rhs)
{
	_ptr = rhs._ptr;
}

template <typename _Iters>
map_const_iterator<_Iters>&	map_const_iterator<_Iters>::operator=(map_const_iterator const& rhs)
{
	if (this != &rhs)
		this->_ptr = rhs._ptr;
	return (*this);
}

/*
** Member function
*/
template <typename _Iters>
typename map_const_iterator<_Iters>::const_reference			map_const_iterator<_Iters>::operator*() const 
{
	return (_ptr->data);
}

template <typename _Iters>
bool	map_const_iterator<_Iters>::isRchild(iterator_type const& node)
{
	return (node == node->Parent->Rchild);
/*
	iterator_type rchild;

	rchild = node->Parent->Rchild;
	if (rchild)
	{
		if (rchild == node)
			return (true);
	}
	return (false);
*/
}
template <typename _Iters>
bool	map_const_iterator<_Iters>::isLchild(iterator_type const& node)
{
//	iterator_type lchild;

//	lchild = node->Parent->Lchild;
	return (node == node->Parent->Lchild);
/*	if (lchild)
	{
		if (lchild == node)
			return (true);
	}
	return (false);
*/
}

template <typename _Iters>
map_const_iterator<_Iters>&	map_const_iterator<_Iters>::operator--()
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
map_const_iterator<_Iters>		map_const_iterator<_Iters>::operator--(int) 
{
	map_const_iterator ret(*this);
	_ptr = _ptr->_next;
	return (ret);
}


template <typename _Iters>
typename map_const_iterator<_Iters>::iterator_type map_const_iterator<_Iters>::Farleft_after(iterator_type const& hint)
{
	iterator_type pos = hint;

	while (pos->Lchild)
		pos = pos->Lchild;
	return (pos);
}

template <typename _Iters>
map_const_iterator<_Iters>&	map_const_iterator<_Iters>::operator++() 
{
	iterator_type pos;

	if (_ptr->Rchild)
		_ptr = Farleft_after(_ptr->Rchild);
	else
	{
		pos = _ptr;
		while (pos && pos->Parent && !isLchild(pos))
			pos = pos->Parent;
		if (pos)
			_ptr = pos->Parent;
	}
	return (*this);

}

template <typename _Iters>
map_const_iterator<_Iters>		map_const_iterator<_Iters>::operator++(int) 
{
	map_const_iterator ret(*this);
	iterator_type pos;

	if (_ptr->Rchild)
		_ptr = Farleft_after(_ptr->Rchild);
	else
	{
		pos = _ptr;
		while (pos && pos->Parent && !isLchild(pos))
			pos = pos->Parent;
		if (pos)
			_ptr = pos->Parent;
	}
	return (ret);
}

template <typename _Iters>
typename map_const_iterator<_Iters>::const_pointer		map_const_iterator<_Iters>::operator->()	
{
	return (&(_ptr->_val)); 
}
/*
** Mon member function : operator
*/

/*
template <typename T, typename U>
bool	operator==(map_const_iterator<T> const& lhs, map_const_iterator<U> const& rhs)
{
	return (lhs._ptr == rhs_ptr);
}

template <typename T, typename U>
bool	operator!=(map_const_iterator<T> const& lhs, map_const_iterator<U> const& rhs)
{
	return (lhs._ptr != rhs._ptr);
}
*/
