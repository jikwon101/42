/*
** Member function : Coplien's form
*/
template <typename _Iters>
list_iterator<_Iters>::list_iterator() : _ptr(0) {}

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
	return (*this);
}

template <typename _Iters>
typename list_iterator<_Iters>::pointer		list_iterator<_Iters>::operator->()	
{
	return (&(_ptr->_val)); 
}
/*
** Mon member function : operator
*/

/*
template <typename T, typename U>
bool	operator==(list_iterator<T> const& lhs, list_iterator<U> const& rhs)
{
	return (lhs._ptr == rhs_ptr);
}

template <typename T, typename U>
bool	operator!=(list_iterator<T> const& lhs, list_iterator<U> const& rhs)
{
	return (lhs._ptr != rhs._ptr);
}
*/
