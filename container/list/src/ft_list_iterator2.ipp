/*
** Member function : Coplien's form
*/
template <typename _Iters>
list_iterator<_Iters>::list_iterator() : _ptr(NULL) {}

template <typename _Iters>
list_iterator<_Iters>::~list_iterator(){}
	
template <typename _Iters>
list_iterator<_Iters>::list_iterator(iterator_type const& src) : _ptr(src) {}


template <typename _Iters>
list_iterator<_Iters>::list_iterator(list_iterator const& rhs)
{
	_ptr = rhs._ptr;
}

template <typename _Iters>
list_iterator<_Iters>&	list_iterator<_Iters>::operator=(list_iterator const& rhs)
{
	if (this != &rhs)
		this->_ptr = rhs._ptr;
	return (*this);
}

/*
** Member function
*/
template <typename _Iters>
typename list_iterator<_Iters>::reference			list_iterator<_Iters>::operator*() const 
{
	return (_ptr->_val);
}
	
template <typename _Iters>
list_iterator<_Iters>&	list_iterator<_Iters>::operator++()
{
	_ptr = _ptr->_next;
	return (*this);
}

template <typename _Iters>
list_iterator<_Iters>		list_iterator<_Iters>::operator++(int) 
{
	list_iterator ret(*this);
	_ptr = _ptr->_next;
	return (ret);
}


template <typename _Iters>
list_iterator<_Iters>&	list_iterator<_Iters>::operator--() 
{
	_ptr = _ptr->_prev;
	return (*this);
}

template <typename _Iters>
list_iterator<_Iters>		list_iterator<_Iters>::operator--(int) 
{
	list_iterator ret(*this);
	_ptr = _ptr->_prev;
	return (ret);
}

template <typename _Iters>
typename list_iterator<_Iters>::pointer		list_iterator<_Iters>::operator->()	
{
	return (&(_ptr->_val)); 
}

template <typename _Iters>
bool	list_iterator<_Iters>::operator==(ft::list_const_iterator<value_type> const& x) const
{
	return (_ptr == x._ptr);
}

template <typename _Iters>
bool	list_iterator<_Iters>::operator!=(ft::list_const_iterator<value_type> const& x) const
{
	return (_ptr != x._ptr);
}

/*
** Mon member function : operator
*/

template <typename T>
bool	operator==(ft::list_iterator<T> const& lhs, ft::list_iterator<T> const& rhs)
{
	return (&(*lhs) == &(*rhs));
}

template <typename T>
bool	operator!=(ft::list_iterator<T> const& lhs, ft::list_iterator<T> const& rhs)
{
	return (&(*lhs) != &(*rhs));
}
