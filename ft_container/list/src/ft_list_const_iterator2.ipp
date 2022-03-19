/*
** Member function : Coplien's form
*/
template <typename _Iters>
list_const_iterator<_Iters>::list_const_iterator() : _ptr(0) {}

template <typename _Iters>
list_const_iterator<_Iters>::~list_const_iterator(){}
	
template <typename _Iters>
list_const_iterator<_Iters>::list_const_iterator(iterator_type const& src) : _ptr(src) {}

template <typename _Iters>
list_const_iterator<_Iters>::list_const_iterator(list_iterator<value_type> const& rhs)
{
	_ptr = rhs._ptr;
}

template <typename _Iters>
list_const_iterator<_Iters>::list_const_iterator(list_const_iterator const& rhs)
{
	_ptr = rhs._ptr;
}

template <typename _Iters>
list_const_iterator<_Iters>&	list_const_iterator<_Iters>::operator=(list_iterator<value_type> const& rhs)
{
	this->_ptr = rhs._ptr;
	return (*this);
}

template <typename _Iters>
list_const_iterator<_Iters>&	list_const_iterator<_Iters>::operator=(list_const_iterator const& rhs)
{
	if (this != &rhs)
		this->_ptr = rhs._ptr;
	return (*this);
}

/*
** Member function
*/
template <typename _Iters>
typename list_const_iterator<_Iters>::const_reference			list_const_iterator<_Iters>::operator*() const 
{
	return (_ptr->_val);
}
	
template <typename _Iters>
list_const_iterator<_Iters>&	list_const_iterator<_Iters>::operator++()
{
	_ptr = _ptr->_next;
	return (*this);
}

template <typename _Iters>
list_const_iterator<_Iters>		list_const_iterator<_Iters>::operator++(int) 
{
	list_const_iterator ret(*this);
	_ptr = _ptr->_next;
	return (ret);
}


template <typename _Iters>
list_const_iterator<_Iters>&	list_const_iterator<_Iters>::operator--() 
{
	_ptr = _ptr->_prev;
	return (*this);
}

template <typename _Iters>
list_const_iterator<_Iters>		list_const_iterator<_Iters>::operator--(int) 
{
	list_const_iterator ret(*this);
	_ptr = _ptr->_prev;
	return (ret);
}

template <typename _Iters>
typename list_const_iterator<_Iters>::const_pointer		list_const_iterator<_Iters>::operator->()	
{
	return (&(_ptr->_val)); 
}

template <typename _Iters>
bool	list_const_iterator<_Iters>::operator==(ft::list_iterator<value_type> const& x) const
{
	return (_ptr == x._ptr);
}

template <typename _Iters>
bool	list_const_iterator<_Iters>::operator!=(ft::list_iterator<value_type> const& x) const
{
	return (_ptr != x._ptr);
}


/*
** Mon member function : operator
*/
template <typename T>
bool	operator==(ft::list_const_iterator<T> const& lhs, ft::list_const_iterator<T> const& rhs)
{
	return (&(*lhs) == &(*rhs));
}

template <typename T>
bool	operator!=(ft::list_const_iterator<T> const& lhs, ft::list_const_iterator<T> const& rhs)
{
	return (&(*lhs) != &(*rhs));
}
