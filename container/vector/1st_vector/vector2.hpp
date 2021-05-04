/*
** Member function : Coplien's Form
*/

/* Default Constructor */
template <typename T, typename Alloc>
vector<T,Alloc>::vector(allocator_type const & alloc) : _size(0), _capacity(0) 
{
	std::cout << "defalult\n";
	_arr = allocator_type().allocate(0);
	allocator_type().construct(_arr);
}

/* Fill Constructor */
template <typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n, const value_type & val, allocator_type const& alloc) 
{
	allocator_type	new_alloc(alloc);
	
	std::cout << "size\n";
	_arr = new_alloc.allocate(n);
	new_alloc.construct(_arr, val);		//temp
	_size = n;
	_capacity = n;
	/*
	for (size_type i = 0; i < n ; i++)
	{
		_arr[i] = val;
	}
	*/
	return ;
}

/* Range Constructor */
template <typename T, typename Alloc>
template <typename InputIt>
vector<T, Alloc>::vector (InputIt first, InputIt last, allocator_type const & alloc, 
							typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type *)
		: _arr(0) ,_size(0), _capacity(0)
{
	std::cout << "iter\n";
	allocator_type	new_alloc(alloc);
	difference_type	diff;
	InputIt			it;

	diff = ft::distance(first, last);
	_arr = new_alloc.allocate(diff);
	for (it = first ; it != last ; ++it)
	{
		*(_arr + ft::distance(first, it)) = *it;
	}
	this->_size = diff;
	this->_capacity = diff;
	return ;
}

/* Copy Constructor */
template <typename T, typename Alloc>
vector<T,Alloc>::vector(vector const & x) 
{
	std::cout << "copy\n";
	this->_size = x._size;
	this->_capacity = x._capacity;
	this->_arr = x.get_allocator().allocate(this->_capacity);
	//x.get_allocator().construct(this->_arr);
	for (size_type i = 0; i < this->_size ; i++)
	{
		this->_arr[i] = x._arr[i];
	}
	return ;
}

/* Operator= */
template <typename T, typename Alloc>
vector<T,Alloc>& vector<T,Alloc>::operator=(vector const & x)
{
	if (this != &x)
	{
		get_allocator().deallocate(this->_arr, this->_capacity);
		this->_size = x._size;
		this->_capacity = x._size;
		this->_arr = get_allocator().allocate(this->_capacity);
		for (size_type i = 0 ; i < this->_size ; i++)
		{
			this->_arr[i] = x._arr[i];
		}
	}
	return (*this);
}

/* Desturctor */
template <typename T, typename Alloc>
vector<T,Alloc>::~vector()
{
	std::cout << "destructor\n";
	for (size_type i = 0; i < this->_size; i++)
		get_allocator().destroy(this->_arr + i);		//temp
	get_allocator().deallocate(this->_arr, this->_capacity);
}


/*
** Memeber function : Allocator
*/

/* Get_allocator */
template <typename T, typename Alloc>
typename vector<T, Alloc>::allocator_type	vector<T, Alloc>::get_allocator() const
{
	return (allocator_type());
}


/* 
** Member function : Iterator 
*/

/* Begin */
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
{
	return (&(_arr[0]));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
{
	return (&(_arr[0]));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cbegin() const throw()
{
	return (&(_arr[0]));
}

template <typename t, typename alloc>
typename vector<t, alloc>::reverse_iterator vector<t,alloc>::rbegin()
{
	reverse_iterator ret(end());
	return (ret);
}

template <typename t, typename alloc>
typename vector<t, alloc>::const_reverse_iterator vector<t,alloc>::rbegin() const
{
	reverse_iterator ret(end());
	return (ret);
}

/* End */
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
{
	return (&(_arr[_size]));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
{
	return (&(_arr[_size]));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cend() const throw()
{
	return (&(_arr[_size]));
}

template <typename t, typename alloc>
typename vector<t, alloc>::reverse_iterator vector<t,alloc>::rend()
{
	reverse_iterator ret(begin());
	return (ret);
}
template <typename t, typename alloc>
typename vector<t, alloc>::const_reverse_iterator vector<t,alloc>::rend() const
{
	reverse_iterator ret(begin());
	return (ret);
}


/*
** Member function : Element Access
*/

//* operator [] */
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::operator[] (size_type n)
{
	return (this->_arr[n]);
}

template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::operator[] (size_type n) const
{
	return (this->_arr[n]);
}


/* At */
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::at(size_type n)
{
	if (n < 0 || n >= this->_size)
		throw (std::out_of_range("Out of range"));
	return (this->_arr[n]);
}

template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::at(size_type n) const
{
	if (n < 0 || n >= this->_size)
		throw (std::out_of_range("Out of range"));
	return (this->_arr[n]);
}

/* Front */
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::front()
{
	return (this->_arr[0]);
}

template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::front() const
{
	return (this->_arr[0]);
}

/* Back */
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::back()
{
	return (this->_arr[this->_size - 1]);
}

template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::back() const
{
	return (this->_arr[this->_size - 1]);
}


/* 
** Member Function : Capacity
*/ 

template <typename T, typename Alloc>
typename vector<T,Alloc>::size_type vector<T,Alloc>::size() const
{
	return (this->_size);
}

template <typename T, typename Alloc>
typename vector<T,Alloc>::size_type vector<T,Alloc>::capacity() const
{
	return (this->_capacity);
}

template <typename T, typename Alloc>
typename vector<T,Alloc>::size_type vector<T,Alloc>::max_size() const
{
	//return (0);
	//	return (((static_cast<size_type>(pow(2, 64))) / sizeof(value_type)) - 1);
	//	return (std::numeric_limits<value_type>::max());
	//	return (size_type(-1));
	//	return (std::numeric_limits<value_type>::max() / sizeof(value_type));
	//	return (std::numeric_limits<difference_type>::max());
	//	return (allocator_type().max_size());
	//	return (this->get_allocator().max_size());
	return (ft::min<size_type>(std::numeric_limits<difference_type>::max(), allocator_type().max_size()));
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::empty() const
{
	if (_size == 0)
		return (true);
	return (false);
}

template <typename T, typename Alloc>
void	vector<T,Alloc>::reserve(size_type n)
{
	value_type *temp;

	if (n > max_size())
		throw (std::length_error("Length error"));
	if (this->_capacity >= n)
		return ;
	temp = get_allocator().allocate(n);
	for (size_type i = 0 ; i < this->_size ; i++)
	{
		temp[i] = this->_arr[i];
	}
	get_allocator().deallocate(this->_arr, this->_capacity);
	this->_capacity = n;
	this->_arr = temp;
	return ;
}

template <typename T, typename Alloc>
void	vector<T,Alloc>::resize(size_type n, value_type val)
{
	pointer temp;

	if (this->_size > n)
	{
		this->_size = n;
		return ;
	}
	else if (this->_size < n && n <= this->_capacity)
	{
		size_type cnt;

		cnt = n - this->_size;
		for (size_type i = 0 ; i < cnt ; i++)
		{
			push_back(val);
		}
	}
	else if (this->_capacity < n)
	{
		temp = get_allocator().allocate(n);
		for (size_type i = 0 ; i < this->_size ; i++)
		{
			temp[i] = this->_arr[i];
		}
		for (size_type i = this->_size ; i < n ; i++)
		{
			temp[i] = val;
		}
		get_allocator().deallocate(this->_arr, this->_capacity);
		this->_size = n;
		this->_capacity = n;
		this->_arr = temp;
	}
}


/*
** Member function : Modifier
*/

/* Push back & Pop back */
template <typename T, typename Alloc>
void vector<T, Alloc>::push_back(value_type const & val)
{
	allocator_type	alloc;
	pointer			temp;
	size_type		alloc_cnt;

	if (_size < _capacity)
	{
		_arr[_size] = val;
		_size++;
		return ;
	}
	try
	{
		alloc_cnt = (_capacity * 2 < _size + 1) ? (_size + 1) : (_capacity * 2);
		temp = alloc.allocate(alloc_cnt);
	}
	catch (std::exception & err)
	{
		std::cout << "Error : " << err.what() << std::endl;
		return ;
	}
	for (size_type i = 0 ; i < _size ; i++)
	{
		temp[i] = _arr[i];
	}
	temp[_size] = val;
	alloc.deallocate(_arr, this->_capacity);
	_arr = temp;
	_size++;
	_capacity = alloc_cnt;
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::pop_back(void)
{
	_size--;
	return ;
}

/* Erase */
template <typename T, typename Alloc>
typename vector<T,Alloc>::iterator vector<T,Alloc>::erase(iterator position)
{
	iterator res(position);
	iterator target;

	target = this->end() - 1;
	for (; position != target ; ++position)
	{
		*position = *(position + 1);
	}
	this->_size--;
	return (res);
}

template <typename T, typename Alloc>
typename vector<T,Alloc>::iterator vector<T,Alloc>::erase(iterator first, iterator last)
{
	iterator res(first);
	iterator target;
	difference_type diff;

	diff = ft::distance(first, last);
	target = this->end() - diff;
	for (; first != target ; ++first)
	{
		*first = *(first + diff);
	}
	this->_size -= (diff);
	return (res);
}

/* Clear */
template <typename T, typename Alloc>
void	vector<T, Alloc>::clear(void)
{
	for (size_type i = 0; i < this->_size; i++)
	{
		get_allocator().destory(_arr + i);
	}
	this->_size = 0;
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
	iterator	cur;
	iterator	prev;

	if (this->_size  + 1 <= this->_capacity)
	{
		// 값을 대입하려는 위치가 기준.(cur)
		for (cur = end() ; _size && cur > position ; --cur)
		{
			prev = cur - 1;
			*cur = *prev;
		}
		*cur = val;
		this->_size++;
		return	(cur);
	}
	else
	{
		int			i;
		size_type	alloc_cnt;
		pointer		temp;

		i = this->_size;
		alloc_cnt = ft::max((_capacity * 2), (_size + 1));
		try
		{
			temp = get_allocator().allocate(alloc_cnt);
		}
		catch (std::exception &err)
		{
			std::cout << "error : " << err.what() << std::endl;
		}
		// 대입하려는 값의 위치가 기준.(cur)
		for  (cur = end() - 1; _size && cur >= position ; --cur)
		{
			temp[i] = *cur;
			i--;
		}
		temp[i] = val;
		cur = &temp[i];
		for (--i ; i >= 0 ; --i)
		{
			temp[i] = this->_arr[i];
		}
		get_allocator().deallocate(this->_arr, this->_capacity);
		this->_size++;
		this->_capacity = alloc_cnt;
		this->_arr = temp;
	}
	return (cur);
}

/* Insert : Fill */
template <typename t, typename alloc>
void	vector<t, alloc>::insert(iterator position, size_type n, const value_type& val)
{
	iterator cur;
	iterator last;

	if (this->_size + n <= this->_capacity)
	{
		last = position + (n - 1);
		// 값을 대입할 곳의 위치 기준(cur)
		for (cur = end() - 1 + n ; _size && cur > last ; --cur)
		{
			*cur = *(cur - n);
		}
		for (cur = position ; cur <= last ; ++cur)
		{
			*cur = val;
		}
		this->_size += n;
	}
	else if (this->_size + n > this->_capacity)
	{
		int			i;
		size_type	alloc_cnt;
		pointer		temp;

		alloc_cnt = ft::max((_capacity * 2), (_size + n));
		try
		{
			temp = get_allocator().allocate(alloc_cnt);
		}
		catch (std::exception &err)
		{
			std::cout << "error : " << err.what() << std::endl;
		}
		i = (this->_size - 1 + n);
		for  (cur = end() - 1; _size && cur >= position ; --cur)
		{
			temp[i] = *cur;
			i--;
		}
		for (int cnt = 0 ; cnt < n ; cnt++)
		{
			temp[i--] = val;
		}
		for (; i >= 0 ; --i)
		{
			temp[i] = this->_arr[i];
		}
		get_allocator().deallocate(this->_arr, this->_capacity);
		this->_size += n;
		this->_capacity = alloc_cnt;
		this->_arr = temp;
	}
}

/* Insert : Range */
template <typename t, typename alloc>
template <typename inputit>
void	vector<t, alloc>::insert(iterator position, inputit first, inputit last, typename ft::is_iterator<!ft::is_arithmetic<inputit>::value, inputit>::type*)
{
	difference_type n;
	iterator cur;
	iterator last_target;
	inputit cur_value;

	n = ft::distance(first, last);
	if (this->_size + n <= this->_capacity)
	{
		last_target = position + (n - 1);
		for (cur = end() - 1 + n ; _size && cur > last_target ; --cur)
		{
			*cur = *(cur - n);
		}
		cur_value = last - 1;
		for (int cnt = 0; cnt < n ; cnt++)
		{
			*cur = *cur_value;
			--cur_value;
			--cur;
		}
		this->_size += n;
	}
	else
	{
		int			i;
		size_type	alloc_cnt;
		pointer		temp;

		alloc_cnt = ft::max((_capacity * 2), (_size + n));
		try
		{
			temp = get_allocator().allocate(alloc_cnt);
		}
		catch (std::exception &err)
		{
			std::cout << err.what() << std::endl;
		}
		i = (this->_size - 1 + n);
		for  (cur = end() - 1; _size && cur >= position ; --cur)
		{
			temp[i] = *cur;
			i--;
		}
		cur_value = last - 1;
		for (int cnt = 0; cnt < n ; cnt++)
		{
			temp[i--] = *cur_value;
			--cur_value;
		}
		for (; i >= 0 ; --i)
		{
			temp[i] = this->_arr[i];
		}
		get_allocator().deallocate(this->_arr, this->_capacity);
		this->_size += n;
		this->_capacity = alloc_cnt;
		this->_arr = temp;
	}
}

/* Assign : Fill */
template <typename t, typename alloc>
void	vector<t, alloc>::assign(size_type n, value_type const& val)
{
	if (n <= this->_capacity)
	{
		for (int i = 0 ; i < n ; i++)
		{
			this->_arr[i] = val;
		}
		_size = n;
		return ;
	}
	get_allocator().deallocate(this->_arr, this->_capacity);
	try
	{
		this->_arr = get_allocator().allocate(n);
	}
	catch (std::exception &err)
	{
		std::cout << "error : " << err.what() << std::endl;
	}
	for (int i = 0; i < n ; i++)
	{
		this->_arr[i] = val;
	}
	_size = n;
	_capacity = n;
	return ;
}

/* Assign : Range */
template <typename t, typename alloc>
template <typename inputit>
void	vector<t, alloc>::assign(inputit first, inputit last, typename ft::is_iterator<!ft::is_arithmetic<inputit>::value, inputit>::type *)
{
	int i = 0;
	difference_type n;

	n = ft::distance(first, last);
	if (n <= this->_capacity)
	{
		for (; first != last ; ++first)
		{
			this->_arr[i++] = *first;
		}
		_size = n;
		return ;	
	}
	get_allocator().deallocate(this->_arr, this->_capacity);
	try
	{
		this->_arr = get_allocator().allocate(n);
	}
	catch(std::exception &err)
	{
		std::cout << "error : " << err.what() << std::endl;
	}
	for (; first != last ; ++first)
	{
		this->_arr[i++] = *first;
	}
	_size = n;
	_capacity = n;
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
