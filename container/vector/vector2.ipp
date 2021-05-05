/*
** Member function : Coplien's Form
*/
/* Default Constructor */
template <typename T, typename Alloc>
vector<T, Alloc>::vector(alloc_type const & alloc) : _begin(NULL), _end(NULL), _end_cap(NULL, alloc)
{}

/* Fill Constructor */
template <typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n, const value_type & val, alloc_type const& alloc) : _begin(NULL), _end(NULL), _end_cap(NULL, alloc)
{
	_begin = _end = this->alloc().allocate(n);
	construct_at_end(n, val);
	end_cap() = _begin + n;
	return ;
}

/* Range Constructor */
template <typename T, typename Alloc>
template <typename InputIt>
vector<T, Alloc>::vector (InputIt first, InputIt last, alloc_type const & alloc, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type *)
		: _begin(NULL), _end(NULL),_end_cap(NULL, alloc)
{
	difference_type diff;
	
	diff = ft::distance(first, last);
	_begin = _end = this->alloc().allocate(diff);
	end_cap() = _begin + diff;
	for (InputIt it = first ; it != last ; ++it)
	{
		push_back(*it);
	}	
	return ;
}

/* Copy Constructor */
template <typename T, typename Alloc>
vector<T, Alloc>::vector(vector const & x)  :_begin(NULL),_end(NULL), _end_cap(NULL, x.get_allocator())
{
	_begin = _end = this->alloc().allocate(x.capacity());
	end_cap() = _begin + x.capacity();
	construct_at_end(x.begin(), x.end());
}

/* Operator= */
template <typename T, typename Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator=(vector const & rhs)
{
	
	if (this != &rhs)
	{
		assign(rhs.begin(), rhs.end());
	}
	return (*this);
}

/* Desturctor */
template <typename T, typename Alloc>
vector<T, Alloc>::~vector()
{
	if (_begin != NULL)
	{
		clear();
		this->alloc().deallocate(_begin, capacity());
		_begin = NULL;
		_end = NULL;
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
template <typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
{
	return (reverse_iterator(begin()));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const
{
	return (reverse_iterator(begin()));
}


/*
** Member function : Element Access
*/

//* operator [] */
template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n)
{
	return (*(_begin + n));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const
{
	return (*(_begin + n));
}


/* At */
template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n)
{
	if (n < 0 || n >= size())
		throw (std::out_of_range("Out of range"));
	return (*(_begin + n));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const
{
	if (n < 0 || n >= size())
		throw (std::out_of_range("Out of range"));
	return (*(_begin + n));
}

/* Front */
template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::front()
{
	return (*_begin);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
{
	return (*_begin);
}

/* Back */
template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::back()
{
	return (*(_end - 1));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
{
	return (*(_end - 1));
}


/* 
** Member Function : Capacity
*/ 
template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
{
	return (static_cast<size_type>(_end - _begin));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
{
	return (static_cast<size_type>(end_cap() - _begin));	
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
{
	return (ft::min<size_type>(std::numeric_limits<difference_type>::max(), alloc().max_size()));
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::empty() const
{
	return (_begin == _end);
}


template <typename T, typename Alloc>
void	vector<T, Alloc>::reserve(size_type n)
{
	if (n > max_size())
		throw (std::length_error("Length Error"));
	if (capacity() < n)
	{
		vector new_vec(alloc());
		new_vec.vector_allocate(n);
		new_vec.construct_at_end(begin(), end());
		swap(new_vec);
	}
	return ;
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::resize(size_type n, value_type val)
{
	size_type _size = size();

	if (n < _size)
		destruct_by(_begin + n);
	else
		append(n - _size, val);
}


/*
** Member function : Modifier
*/

/* Push back & Pop back */
template <typename T, typename Alloc>
void vector<T, Alloc>::push_back(value_type const & val)
{
	append(1, val);
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
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position)
{
	pointer first;

	first = position.base();
	destruct_range(first, first + 1);
	for (pointer it = first ; it != _end - 1 ; ++it)
	{
		*it = *(it + 1);
		destruct_range(it + 1, it + 2);
	}
	_end -= 1;
	return (first);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last)
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
	if (_begin != NULL)
		destruct_by(_begin);
	return ;
}

/* Swap */
template <typename T, typename Alloc>
void	vector<T, Alloc>::swap(vector &x)
{
	pointer temp_begin;
	pointer temp_end;
	Pair<pointer, alloc_type> temp_end_cap;

	temp_begin = x._begin;
	temp_end = x._end;
	temp_end_cap = x._end_cap;

	x._begin = this->_begin;
	x._end = this->_end;
	x._end_cap = this->_end_cap;

	this->_begin = temp_begin;
	this->_end = temp_end;
	this->_end_cap = temp_end_cap;
}


/* Insert : Single element */
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::insert(iterator position, const value_type& val)
{
	if (_end < end_cap())
	{
		if (position == end())
			construct_one_at_end(val);
			//construct_at_end(1, val);
		else
		{
			pointer pos = _end;
			
			construct_one_at_end(back());
			//construct_at_end(1, back());
			while (pos != position.base() && pos > _begin )
			{
				*pos = *(pos - 1);
				--pos;
			}
			*pos = val;
		}
	}
	else
	{
		vector new_vec(alloc());
		size_type _new_n;

		_new_n = (capacity() * 2 > size() + 1) ? (capacity() * 2) : (size() + 1);
		new_vec.vector_allocate(_new_n);
		new_vec.construct_at_end(begin(), position);
		new_vec.construct_at_end(1, val);
		new_vec.construct_at_end(position, end());
		swap(new_vec);
	}
	return (begin());
}

/* Insert : Fill */
template <typename T, typename Alloc>
void	vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
	if (_end + n <= end_cap())
	{
		if (position == end())
			construct_at_end(n, val);
		else
		{
			pointer pos;

			for (size_type i = 0 ; (i < n && (_end - n) >= _begin) ; i++)
			{
				construct_at_end(1, *(_end - n));
			}
			pos = position.base();
			for (size_type i = 0 ; i < n ; i++)
			{
				*(pos++) = val;
			}
		}
	}
	else
	{
		vector new_vec(alloc());
		size_type _new_n;

		_new_n = (capacity() * 2 > size() + n) ? (capacity() * 2) : (size() + n);
		new_vec.vector_allocate(_new_n);
		new_vec.construct_at_end(begin(), position);
		new_vec.construct_at_end(n, val);
		new_vec.construct_at_end(position, end());
		swap(new_vec);
	}
	return  ;
}

/* Insert : Range */
template <typename T, typename Alloc>
template <typename InputIt>
void	vector<T, Alloc>::insert(iterator position, InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type*)
{
	size_type n;

	n = static_cast<size_type>(ft::distance(first, last));

	if (_end + n <= end_cap())
	{
		if (position == end())
			construct_at_end(first, last);
		else
		{
			pointer vector_pos;

			for (size_type i = 0 ; (i < n && (_end - n) >= _begin) ; i++)
			{
				construct_at_end(1, *(_end - n));
			}
			vector_pos = position.base();
			for (InputIt pos = first ; pos != last ; ++pos)
			{
				*(vector_pos++) = *pos;
			}
		}
	}
	else
	{
		vector new_vec(alloc());
		size_type _new_n;

		_new_n = (capacity() * 2 > size() + n) ? (capacity() * 2) : (size() + n);
		new_vec.vector_allocate(_new_n);
		new_vec.construct_at_end(begin(), position);
		new_vec.construct_at_end(first, last);
		new_vec.construct_at_end(position, end());
		swap(new_vec);
	}
	return  ;
}

/* Assign : Fill */
template <typename T, typename Alloc>
void	vector<T, Alloc>::assign(size_type n, value_type const& val)
{
	clear();
	if (static_cast<size_type>(end_cap() - _end) >= n)
		construct_at_end(n, val);
	else
	{
		vector new_vec(alloc());
		size_type _new_n;

		_new_n = n;
		new_vec.vector_allocate(n);
		new_vec.construct_at_end(n, val);
		swap(new_vec);
	}
	return ;
}

/* Assign : Range */
template <typename T, typename Alloc>
template <typename InputIt>
void	vector<T, Alloc>::assign(InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type *)
{
	difference_type n;

	clear();
	n = ft::distance(first, last);
	if ( (end_cap() - _end) >= n)
		construct_at_end(first, last);
	else
	{
		vector new_vec(alloc());
		size_type _new_n;

		_new_n = static_cast<size_type>(n);
		new_vec.vector_allocate(_new_n);
		new_vec.construct_at_end(first, last);
		swap(new_vec);
	}
	return ;
}


/*
** Non-member function 
*/

/* Swap */
template <typename T, typename Alloc>
void	swap(vector<T, Alloc> &x, vector<T, Alloc>& y)
{
	x.swap(y);
}

/* Operator */
template <class T, class Alloc>
bool operator== (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
	typename ft::vector<T, Alloc>::size_type i;

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
bool operator!= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
	if (lhs == rhs)
		return (false);
	return (true);
}

template <class T, class Alloc>
bool operator< (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
	typename ft::vector<T, Alloc>::size_type i;

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
bool operator<= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
	if ((lhs < rhs) || (lhs == rhs))
		return (true);
	return (false);
}


template <class T, class Alloc>
bool operator> (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
	if (lhs <= rhs)
		return (false);
	return (true);
}

template <class T, class Alloc>
bool operator>= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
	if (lhs < rhs)
		return (false);
	return (true);
}
