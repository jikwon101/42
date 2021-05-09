/*
** Member function : Coplien's form
*/
template <typename _Iters>
vector_iterator<_Iters>::vector_iterator() : _ptr(0) {}

template <typename _Iters>
vector_iterator<_Iters>::~vector_iterator(){}
	
template <typename _Iters>
vector_iterator<_Iters>::vector_iterator(iterator_type const src) : _ptr(src) {}

template <typename _Iters>
template <typename U> 
vector_iterator<_Iters>::vector_iterator(vector_iterator<U> const& rhs) 
{
	_ptr = rhs.base();
}

template <typename _Iters>
vector_iterator<_Iters>&	vector_iterator<_Iters>::operator=(vector_iterator const& rhs)
{
	if (this != &rhs)
	{
		this->_ptr = rhs.base();
	}
	return (*this);
}

/*
** Member function
*/
template <typename _Iters>
typename vector_iterator<_Iters>::iterator_type		vector_iterator<_Iters>::base() const 
{
	return (_ptr);
}

template <typename _Iters>
typename vector_iterator<_Iters>::reference			vector_iterator<_Iters>::operator*() const 
{
	return (*_ptr); 
}
	
template <typename _Iters>
vector_iterator<_Iters>		vector_iterator<_Iters>::operator+(difference_type n) const
{
	return (this->_ptr + n); 
}
	
template <typename _Iters>
vector_iterator<_Iters>&	vector_iterator<_Iters>::operator++()
{
	++_ptr; 
	return (*this);
}

template <typename _Iters>
vector_iterator<_Iters>		vector_iterator<_Iters>::operator++(int) 
{
	vector_iterator ret(*this);
	++_ptr; 
	return (ret);
}

template <typename _Iters>
vector_iterator<_Iters>&	vector_iterator<_Iters>::operator+=(difference_type n) 
{
	this->_ptr += n;
	return (*this);
}

template <typename _Iters>
vector_iterator<_Iters>		vector_iterator<_Iters>::operator-(difference_type n) const
{
	return (this->_ptr - n); 
}

template <typename _Iters>
vector_iterator<_Iters>&	vector_iterator<_Iters>::operator--() 
{
	--_ptr; 
	return (*this);
}

template <typename _Iters>
vector_iterator<_Iters>		vector_iterator<_Iters>::operator--(int) 
{
	vector_iterator ret(*this);
	--_ptr; 
	return (*this);
}

template <typename _Iters>
vector_iterator<_Iters>&	vector_iterator<_Iters>::operator-=(difference_type n)
{
	this->_ptr -= n;
	return (*this);
}

template <typename _Iters>
typename vector_iterator<_Iters>::pointer		vector_iterator<_Iters>::operator->()	
{
	return (_ptr); 
}

template <typename _Iters>
typename vector_iterator<_Iters>::reference		vector_iterator<_Iters>::operator[](int n) const
{ 
	vector_iterator temp(_ptr);

	temp += n;
	return (*temp);
}

/*
** Mon member function : operator
*/
template <typename T, typename U>
bool	operator==(vector_iterator<T> const& lhs, vector_iterator<U> const& rhs)
{
	return (lhs.base() == rhs.base());
}

template <typename T, typename U>
bool	operator!=(vector_iterator<T> const& lhs, vector_iterator<U> const& rhs)
{
	return (lhs.base() != rhs.base());
}

template <typename T, typename U>
bool	operator>(vector_iterator<T> const& lhs, vector_iterator<U> const& rhs)
{
	return (lhs.base() > rhs.base());
}

template <typename T, typename U>
bool	operator>=(vector_iterator<T> const& lhs, vector_iterator<U> const& rhs)
{
	return (lhs.base() >= rhs.base());
}

template <typename T, typename U>
bool	operator<(vector_iterator<T> const& lhs, vector_iterator<U> const& rhs)
{
	return (lhs.base() < rhs.base());
}
		
template <typename T, typename U>
bool	operator<=(vector_iterator<T> const& lhs, vector_iterator<U> const& rhs)
{
	return (lhs.base() <= rhs.base());
}

template <typename T, typename U>
typename iterator_traits<T>::difference_type	operator-(vector_iterator<T> const& lhs, vector_iterator<U> const& rhs)
{
	return (lhs.base() - rhs.base());
}

