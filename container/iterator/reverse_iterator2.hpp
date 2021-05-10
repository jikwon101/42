/*
** Member functions : Copliens's Form
*/
template <typename _Iter>
reverse_iterator<_Iter>::~reverse_iterator() {}

template <typename _Iter>
reverse_iterator<_Iter>::reverse_iterator() : _base(0) {}

template <typename _Iter>
reverse_iterator<_Iter>::reverse_iterator(iterator_type it) : _base(it) {}

template <typename _Iter>
template <typename It>
reverse_iterator<_Iter>::reverse_iterator(const reverse_iterator<It>& rev_it)
{
	_base = rev_it.base();
}

template <typename _Iter>
reverse_iterator<_Iter>&	reverse_iterator<_Iter>::operator=(reverse_iterator const& rhs)
{
	if (this != &rhs)
	{
		this->_base = rhs.base();
	}
	return (*this);
}

/*
** Member function
*/
template <typename _Iter>
typename reverse_iterator<_Iter>::iterator_type		reverse_iterator<_Iter>::base() const
{
	return (_base);
}

template <typename _Iter>
typename reverse_iterator<_Iter>::reference			reverse_iterator<_Iter>::operator*() const
{
	iterator_type res = _base;
	--res;
	return (*res);
	//return (*(_base - 1));
}


template <typename _Iter>
reverse_iterator<_Iter>			reverse_iterator<_Iter>::operator+(difference_type n) const
{
	reverse_iterator res(_base - n);
	return (res);
}


template <typename _Iter>
reverse_iterator<_Iter>&		reverse_iterator<_Iter>::operator++()
{
	--_base;
	return (*this);
}

template <typename _Iter>
reverse_iterator<_Iter>			reverse_iterator<_Iter>::operator++(int n)
{
	reverse_iterator ret(*this);
	--_base;
	return (ret);
}

template <typename _Iter>
reverse_iterator<_Iter>&		reverse_iterator<_Iter>::operator+=(difference_type n)
{
	_base -= n;
	return (*this);
}

template <typename _Iter>
reverse_iterator<_Iter>			reverse_iterator<_Iter>::operator-(difference_type n) const
{
	reverse_iterator res(_base + n);
	return (res);
}

template <typename _Iter>
reverse_iterator<_Iter>&		reverse_iterator<_Iter>::operator--()
{
	++_base;
	return (*this);
}

template <typename _Iter>
reverse_iterator<_Iter>			reverse_iterator<_Iter>::operator--(int n)
{
	reverse_iterator ret(*this);
	++_base;
	return (ret);
}

template <typename _Iter>
reverse_iterator<_Iter>&		reverse_iterator<_Iter>::operator-=(difference_type n)
{
	_base += n;
	return (*this);
}

template <typename _Iter>
typename reverse_iterator<_Iter>::pointer		reverse_iterator<_Iter>::operator->() const
{
	return (_base.base());
}

template <typename _Iter>
typename reverse_iterator<_Iter>::reference		reverse_iterator<_Iter>::operator[] (difference_type n) const
{
	iterator_type temp(_base);
	temp -= n;
	return (*(temp - 1));
}


/*
** Non member function : Operator
*/
template <typename Iter>
bool	operator==(const reverse_iterator<Iter>lhs, const reverse_iterator<Iter>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <typename Iter>
bool	operator!=(const reverse_iterator<Iter>lhs, const reverse_iterator<Iter>& rhs)
{
	return (lhs.base() != rhs.base());
}

template <typename Iter>
bool	operator<(const reverse_iterator<Iter>lhs, const reverse_iterator<Iter>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <typename Iter>
bool	operator<=(const reverse_iterator<Iter>lhs, const reverse_iterator<Iter>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template <typename Iter>
bool	operator>(const reverse_iterator<Iter>lhs, const reverse_iterator<Iter>& rhs)
{
	return (lhs.base() > rhs.base());
}

template <typename Iter>
bool	operator>=(const reverse_iterator<Iter>lhs, const reverse_iterator<Iter>& rhs)
{
	return (lhs.base() >= rhs.base());
}
	
template <typename Iter>
reverse_iterator<Iter>		operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& rev_it)
{
	return (rev_it + n);
}

template <typename T, typename U>
typename reverse_iterator<T>::difference_type	operator-(const reverse_iterator<T>&lhs, const reverse_iterator<U>& rhs)
{
	return (rhs.base() - lhs.base());
}
