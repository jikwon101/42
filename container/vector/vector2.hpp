/*
** Member function : Coplien's Form
*/
/* Default Constructor */
template <typename T, typename Alloc>
vector<T,Alloc>::vector(alloc_type const & alloc) : _begin(NULL), _end(NULL), _end_cap(NULL, alloc)
{
	//std::cout << "defalult\n";	
}

/* Fill Constructor */
template <typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n, const value_type & val, alloc_type const& alloc) : _begin(NULL), _end(NULL), _end_cap(NULL, alloc)
{
	//std::cout << "size\n";
	_begin = _end = this->alloc().allocate(n);
	construct_at_end(n, val);
	end_cap() = _begin + n;
	return ;
}

/* Range Constructor */
template <typename T, typename Alloc>
template <typename InputIt>
vector<T, Alloc>::vector (InputIt first, InputIt last, alloc_type const & alloc, 
							typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type *)
		: _begin(NULL), _end(NULL),_end_cap(NULL, alloc)
{
	//std::cout << "iter\n";
	difference_type diff;
	
	diff = ft::distance(first, last);
	_begin = _end = this->alloc().allocate(diff);
	end_cap() = _begin + diff;
	for (InputIt it = first ; it != last ; ++it)
	{
		construct_at_end(1, *it);		//write : push_back
	}	
	return ;
}

/* Copy Constructor */
template <typename T, typename Alloc>
vector<T,Alloc>::vector(vector const & x)  :_begin(NULL),_end(NULL), _end_cap(NULL, x.get_allocator())
{
	//std::cout << "copy\n";
	_begin = _end = this->alloc().allocate(x.capacity());
	end_cap() = _begin + x.capacity();
	for (size_type i = 0 ; i < x.size() ; ++i)
		construct_at_end(1, x[i]);
}

/* Operator= */
template <typename T, typename Alloc>
vector<T,Alloc>& vector<T,Alloc>::operator=(vector const & rhs)
{
	
	if (this != &rhs)
	{
		// write
		//assign(rhs.begin(), rhs.end());
	}
	return (*this);
}

/* Desturctor */
template <typename T, typename Alloc>
vector<T,Alloc>::~vector()
{
	if (_begin != NULL)
	{
		clear();
		this->alloc().deallocate(_begin, capacity());
	}
}


/*
** Memeber function : Allocator
*/

/* Get_allocator */
template <typename T, typename Alloc>
typename vector<T, Alloc>::alloc_type	vector<T, Alloc>::get_allocator() const
{
	return (alloc());
}


/* 
** Member function : Iterator
*/

/* Begin */
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
{
	return (_begin);
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
{
	return (_begin);
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cbegin() const throw()
{
	return (_begin);
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
{
	return (reverse_iterator(end()));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const
{
	return (reverse_iterator(end()));
}

/* End */
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
{
	return (_end);
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
{
	return (_end);
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cend() const throw()
{
	return (_end);
}
template <typename t, typename alloc>
typename vector<t, alloc>::reverse_iterator vector<t,alloc>::rend()
{
	return (reverse_iterator(begin()));
}
template <typename t, typename alloc>
typename vector<t, alloc>::const_reverse_iterator vector<t,alloc>::rend() const
{
	return (reverse_iterator(begin()));
}


/*
** Member function : Element Access
*/

//* operator [] */
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::operator[] (size_type n)
{
	return (*(_begin + n));
}
template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::operator[] (size_type n) const
{
	return (*(_begin + n));
}


/* At */
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::at(size_type n)
{
	if (n < 0 || n >= this->_size)
		throw (std::out_of_range("Out of range"));
	return (*(_begin + n));
}

template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::at(size_type n) const
{
	if (n < 0 || n >= this->_size)
		throw (std::out_of_range("Out of range"));
	return (*(_begin + n));
}

/* Front */
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::front()
{
	return (*_begin);
}

template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::front() const
{
	return (*_begin);
}

/* Back */
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::back()
{
	return (*(_end - 1));
}
template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::back() const
{
	return (*(_end - 1));
}


/* 
** Member Function : Capacity
*/ 
template <typename T, typename Alloc>
typename vector<T,Alloc>::size_type vector<T,Alloc>::size() const
{
	return (static_cast<size_type>(_end - _begin));
}
template <typename T, typename Alloc>
typename vector<T,Alloc>::size_type vector<T,Alloc>::capacity() const
{
	return (static_cast<size_type>(end_cap() - _begin));	
}
template <typename T, typename Alloc>
typename vector<T,Alloc>::size_type vector<T,Alloc>::max_size() const
{
	return (ft::min<size_type>(std::numeric_limits<difference_type>::max(), alloc().max_size()));
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::empty() const
{
	return (_begin == _end);
}


template <typename T, typename Alloc>
void	vector<T,Alloc>::reserve(size_type n)
{
	value_type *temp;

	if (n > max_size())
		throw (std::length_error("Length error"));
	// write
	return ;
}

template <typename T, typename Alloc>
void	vector<T,Alloc>::resize(size_type n, value_type val)
{
	// write
}


/*
** Member function : Modifier
*/

/* Push back & Pop back */
template <typename T, typename Alloc>
void vector<T, Alloc>::push_back(value_type const & val)
{
	//write
	return ;
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::pop_back(void)
{
	destruct_by(_end - 1);
	return ;
}

/* Erase */
template <typename T, typename Alloc>
typename vector<T,Alloc>::iterator vector<T,Alloc>::erase(iterator position)
{
	pointer first;

	first = position.base();
	destruct_range(first, first + 1);
	for (pointer it = first.base() ; it != _end.base() - 1 ; ++it)
	{
		*it = *(it + 1);
		destruct_range(it + 1, it + 2);
	}
	_end -= 1;
	return (first);
}

template <typename T, typename Alloc>
typename vector<T,Alloc>::iterator vector<T,Alloc>::erase(iterator first, iterator last)
{
	pointer res;
	difference_type n;

	res = first.base();
	destruct_range(first.base(), last.base());
	n = ft::distance(first, last);
	for (pointer it = first.base() ; it != _end -n; ++it)
	{
		*it = *(it + n);
		destruct_range(it + n, it + n + 1);
	}
	_end -= n;
	return (res);
}

/* Clear */
template <typename T, typename Alloc>
void	vector<T, Alloc>::clear(void)
{
	destruct_by(_begin);
	return ;
}

/* Swap */
template <typename t, typename alloc>
void	vector<t, alloc>::swap(vector &x)
{
	swap(*this, x);
}

/* Insert : Single element */
template <typename t, typename alloc>
typename vector<t, alloc>::iterator	vector<t, alloc>::insert(iterator position, const value_type& val)
{
	// write
	return (begin());
}

/* Insert : Fill */
template <typename t, typename alloc>
void	vector<t, alloc>::insert(iterator position, size_type n, const value_type& val)
{
	// write
	return  ;
}

/* Insert : Range */
template <typename t, typename alloc>
template <typename inputit>
void	vector<t, alloc>::insert(iterator position, inputit first, inputit last, typename ft::is_iterator<!ft::is_arithmetic<inputit>::value, inputit>::type*)
{
	// write
	return ;
}

/* Assign : Fill */
template <typename t, typename alloc>
void	vector<t, alloc>::assign(size_type n, value_type const& val)
{
	// write
	return ;
}

/* Assign : Range */
// Not
template <typename t, typename alloc>
template <typename inputit>
void	vector<t, alloc>::assign(inputit first, inputit last, typename ft::is_iterator<!ft::is_arithmetic<inputit>::value, inputit>::type *)
{
	// write
	return ;
}


/*
** Non-member function 
*/

/* Swap */
template <typename t, typename alloc>
void	swap(vector<t, alloc> &x, vector<t, alloc>& y)
{
	typename vector<t, alloc>::pointer temp_ptr;
	typename vector<t, alloc>::size_type temp_size;
	typename vector<t, alloc>::size_type temp_capacity;

	temp_ptr = x._arr;
	temp_size = x._size;
	temp_capacity = x._capacity;

	x._arr = y._arr;
	x._size = y._size;
	x._capacity = y._capacity;

	y._arr = temp_ptr;
	y._size = temp_size;
	y._capacity = temp_capacity;
}

/* Operator */
template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	typename ft::vector<T,Alloc>::size_type i;

	i = 0;
	while (i < lhs.size() && i < rhs.size())
	{
		if (lhs[i] != rhs[i])
			return (false);
		i++;
	}
	if (lhs.size() == rhs.size())
		return (true);
	return (false);
}

template <class T, class Alloc>
bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (false);
	return (true);
}

template <class T, class Alloc>
bool operator< (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	typename ft::vector<T,Alloc>::size_type i;

	i = 0;
	while (i < lhs.size() && i < rhs.size())
	{
		if (lhs[i] < rhs[i])
			return (true);
		else if (lhs[i] > rhs[i])
			return (false);
		i++;
	}
	if (lhs.size() < rhs.size())
		return (true);
	return (false);
}

template <class T, class Alloc>
bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if ((lhs < rhs) || (lhs == rhs))
		return (true);
	return (false);
}


template <class T, class Alloc>
bool operator> (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs <= rhs)
		return (false);
	return (true);
}

template <class T, class Alloc>
bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs < rhs)
		return (false);
	return (true);
}
