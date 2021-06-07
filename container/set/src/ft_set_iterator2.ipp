/*
** Member function : Coplien's form
*/
template <typename _Iters>
set_iterator<_Iters>::set_iterator() 
	: _ptr(0)
{}

template <typename _Iters>
set_iterator<_Iters>::~set_iterator()
{}
	
template <typename _Iters>
set_iterator<_Iters>::set_iterator(iterator_type const& src)
	: _ptr(src) 
{}

template <typename _Iters>
set_iterator<_Iters>::set_iterator(set_iterator const& rhs)
{
	_ptr = rhs._ptr;
}

template <typename _Iters>
set_iterator<_Iters>&
	set_iterator<_Iters>::operator=(set_iterator const& rhs)
{
	if (this != &rhs)
		this->_ptr = rhs._ptr;
	return (*this);
}

/*
** Member function
*/
template <typename _Iters>
typename set_iterator<_Iters>::reference
	set_iterator<_Iters>::operator*() const 
{
	return (_ptr->data);
}

template <typename _Iters>
bool	set_iterator<_Iters>::isRchild(iterator_type const& node)
{
	return (node == node->Parent->Rchild);
}
template <typename _Iters>
bool	set_iterator<_Iters>::isLchild(iterator_type const& node)
{
	return (node == node->Parent->Lchild);
}

template <typename _Iters>
set_iterator<_Iters>&
	set_iterator<_Iters>::operator--()
{	
	iterator_type pos;

	if (_ptr->Lchild)
		_ptr = Farright_after(_ptr->Lchild);
	else
	{
		pos = _ptr;
		while (pos && !isRchild(pos))
			pos = pos->Parent;
		_ptr = pos->Parent;
	}
	return (*this);
}

template <typename _Iters>
set_iterator<_Iters>	
	set_iterator<_Iters>::operator--(int) 
{
	iterator_type pos;
	set_iterator ret(*this);

	if (_ptr->Lchild)
		_ptr = Farright_after(_ptr->Lchild);
	else
	{
		pos = _ptr;
		while (pos && !isRchild(pos))
			pos = pos->Parent;
		_ptr = pos->Parent;
	}
	return (ret);

}

template <typename _Iters>
typename set_iterator<_Iters>::iterator_type 
	set_iterator<_Iters>::Farright_after(iterator_type const& hint)
{
	iterator_type pos = hint;

	while (pos->Rchild)
		pos = pos->Rchild;
	return (pos);
}


template <typename _Iters>
typename set_iterator<_Iters>::iterator_type 
	set_iterator<_Iters>::Farleft_after(iterator_type const& hint)
{
	iterator_type pos = hint;

	while (pos->Lchild)
		pos = pos->Lchild;
	return (pos);
}

template <typename _Iters>
set_iterator<_Iters>&
	set_iterator<_Iters>::operator++() 
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
set_iterator<_Iters>	
	set_iterator<_Iters>::operator++(int) 
{
	set_iterator ret(*this);
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
typename set_iterator<_Iters>::pointer	
	set_iterator<_Iters>::operator->()	
{
	return (&(_ptr->data)); 
}

template <typename _iters>
bool		set_iterator<_iters>::operator==(set_const_iterator<value_type> const& x) const
{
	return (_ptr == x._ptr);
}

template <typename _iters>
bool		set_iterator<_iters>::operator!=(set_const_iterator<value_type> const& x) const
{
	return (_ptr == x._ptr);
}

template <typename u>
bool	operator==(ft::set_iterator<u> const& lhs, ft::set_iterator<u> const& rhs)
{
	return (lhs._ptr == rhs._ptr);
}

template <typename u>
bool	operator!=(ft::set_iterator<u> const& lhs, ft::set_iterator<u> const& rhs)
{
	return (lhs._ptr != rhs._ptr);
}

