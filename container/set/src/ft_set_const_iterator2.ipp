/*
** Member function : Coplien's form
*/
template <typename _Iters>
set_const_iterator<_Iters>::set_const_iterator() 
	: _ptr(0) 
{}

template <typename _Iters>
set_const_iterator<_Iters>::~set_const_iterator()
{}
	
template <typename _Iters>
set_const_iterator<_Iters>::set_const_iterator(iterator_type const& src) 
	: _ptr(src) 
{}


template <typename _Iters>
set_const_iterator<_Iters>::set_const_iterator(set_const_iterator const& rhs)
{
	_ptr = rhs._ptr;
}

template <typename _Iters>
set_const_iterator<_Iters>&	
	set_const_iterator<_Iters>::operator=(set_const_iterator const& rhs)
{
	if (this != &rhs)
		this->_ptr = rhs._ptr;
	return (*this);
}

/*
** Member function
*/
template <typename _Iters>
typename set_const_iterator<_Iters>::const_reference
	set_const_iterator<_Iters>::operator*() const 
{
	return (_ptr->data);
}

template <typename _Iters>
bool	set_const_iterator<_Iters>::isRchild(iterator_type const& node)
{
	return (node == node->Parent->Rchild);
}
template <typename _Iters>
bool	set_const_iterator<_Iters>::isLchild(iterator_type const& node)
{
	return (node == node->Parent->Lchild);
}

template <typename _Iters>
set_const_iterator<_Iters>&	
	set_const_iterator<_Iters>::operator--()
{	
	iterator_type pos;

	if (_ptr->Lchild)
		_ptr = Farright_after(_ptr->Lchild);
	else
	{
		pos = _ptr;
		while (pos->Parent->Rchild != pos->Rchild && pos && !isRchild(pos))
			pos = pos->Parent;
		if (pos->Parent->Rchild == pos->Rchild)
			_ptr = pos->Rchild;
		else
			_ptr = pos->Parent;
	}
	return (*this);
}

template <typename _Iters>
set_const_iterator<_Iters>		
	set_const_iterator<_Iters>::operator--(int) 
{
	iterator_type pos;
	set_const_iterator ret(*this);

	if (_ptr->Lchild)
		_ptr = Farright_after(_ptr->Lchild);
	else
	{
		pos = _ptr;
		while (pos->Parent->Rchild != pos->Rchild && pos && !isRchild(pos))
			pos = pos->Parent;
		if (pos->Parent->Rchild == pos->Rchild)
			_ptr = pos->Rchild;
		else
			_ptr = pos->Parent;
	}
	return (ret);
}

template <typename _Iters>
typename set_const_iterator<_Iters>::iterator_type
	set_const_iterator<_Iters>::Farright_after(iterator_type const& hint)
{
	iterator_type pos = hint;

	while (pos->Rchild)
		pos = pos->Rchild;
	return (pos);
}


template <typename _Iters>
typename set_const_iterator<_Iters>::iterator_type
	set_const_iterator<_Iters>::Farleft_after(iterator_type const& hint)
{
	iterator_type pos = hint;

	while (pos->Lchild)
		pos = pos->Lchild;
	return (pos);
}

template <typename _Iters>
set_const_iterator<_Iters>&	
	set_const_iterator<_Iters>::operator++() 
{
	iterator_type pos;

	if (_ptr->Rchild)
		_ptr = Farleft_after(_ptr->Rchild);
	else
	{
		pos = _ptr;
		while (pos && !isLchild(pos))
			pos = pos->Parent;
		_ptr = pos->Parent;
	}
	return (*this);
}

template <typename _Iters>
set_const_iterator<_Iters>		
	set_const_iterator<_Iters>::operator++(int) 
{
	set_const_iterator ret(*this);
	iterator_type pos;

	if (_ptr->Rchild)
		_ptr = Farleft_after(_ptr->Rchild);
	else
	{
		pos = _ptr;
		while (pos && !isLchild(pos))
			pos = pos->Parent;
		_ptr = pos->Parent;
	}
	return (ret);
}

template <typename _Iters>
typename set_const_iterator<_Iters>::const_pointer		
	set_const_iterator<_Iters>::operator->()	
{
	return (&(_ptr->data)); 
}

template <typename _iters>
bool		set_const_iterator<_iters>::operator==(set_iterator<value_type> const& x) const
{
	return (_ptr == x._ptr);
}

template <typename _iters>
bool		set_const_iterator<_iters>::operator!=(set_iterator<value_type> const& x) const
{
	return (_ptr == x._ptr);
}

template <typename u>
bool	operator==(ft::set_const_iterator<u> const& lhs, ft::set_const_iterator<u> const& rhs)
{
	return (lhs._ptr == rhs._ptr);
}

template <typename u>
bool	operator!=(ft::set_const_iterator<u> const& lhs, ft::set_const_iterator<u> const& rhs)
{
	return (lhs._ptr != rhs._ptr);
}

