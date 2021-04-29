//util
/*
template <typename T>
T	max(T a, T b)
{
	if (a > b)
		return (a);
	return (b);
}
*/
// 소멸자
template <typename T, typename Alloc>
vector<T,Alloc>::~vector()
{
	get_allocator().deallocate(this->_arr, this->_capacity);
}

// default 생성자
template <typename T, typename Alloc>
vector<T,Alloc>::vector(allocator_type const & alloc) : _arr(0), _size(0), _capacity(0) 
{
	//std::cout << "default\n";
}

// fill 생성자
template <typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n, const value_type & val, allocator_type const& alloc)
{
	allocator_type	new_alloc(alloc);
	
	//std::cout << "size\n";			//temp
	_arr = new_alloc.allocate(n);
	_size = n;
	_capacity = n;
	for (size_type i = 0; i < n ; i++)
	{
		_arr[i] = val;
	}
}

// range 생성자
template <typename T, typename Alloc>
template <typename InputIt>
vector<T, Alloc>::vector (InputIt first, InputIt last, allocator_type const & alloc, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type *)
{
	allocator_type	new_alloc(alloc);
	difference_type	diff;
	InputIt			it;
	int				i;

//	std::cout << "Iterator\n";			//temp
	diff = ft::distance(first, last);
	_arr = new_alloc.allocate(diff);
	i = 0;
	for (it = first ; it != last ; ++it)
	{
		*(_arr + ft::distance(first, it)) = *it;
	}
	this->_size = diff;
	this->_capacity = diff;
}

// copy 생성자
template <typename T, typename Alloc>
vector<T,Alloc>::vector(vector const & x) 
{
//	std::cout << "copy\n";			//temp
	this->_size = x._size;
	this->_capacity = x._capacity;
	this->_arr = x.get_allocator().alloacate(this->_capacity);
	for (size_type i = 0; i < this->_size ; i++)
	{
		this->_arr[i] = x._arr[i];
	}
}

// operator=
template <typename T, typename Alloc>
vector<T,Alloc>& vector<T,Alloc>::operator=(vector const & x)
{
//	std::cout << "operotr=\n";		//temp
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

//begin
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
//end
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
//operator []
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

//get_allocator
template <typename T, typename Alloc>
typename vector<T, Alloc>::allocator_type	vector<T, Alloc>::get_allocator() const
{
	return (allocator_type());
}

// at
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::at(size_type n)
{
	if (n < 0 || n >= this->_size)
		throw (std::out_of_range("Out of range"));
	return (this->_arr[n]);
}

// const at
template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::at(size_type n) const
{
	if (n < 0 || n >= this->_size)
		throw (std::out_of_range("Out of range"));
	return (this->_arr[n]);
}

// front
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::front()
{
	return (this->_arr[0]);
}

// const front
template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::front() const
{
	return (this->_arr[0]);
}

//back
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::back()
{
	return (this->_arr[this->_size - 1]);
}

// const back
template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::back() const
{
	return (this->_arr[this->_size - 1]);
}


// size
template <typename T, typename Alloc>
typename vector<T,Alloc>::size_type vector<T,Alloc>::size() const
{
	return (this->_size);
}

//capacity
template <typename T, typename Alloc>
typename vector<T,Alloc>::size_type vector<T,Alloc>::capacity() const
{
	return (this->_capacity);
}

//max size
template <typename T, typename Alloc>
typename vector<T,Alloc>::size_type vector<T,Alloc>::max_size() const
{
	return (this->get_allocator().max_size());
}

// empty
template <typename T, typename Alloc>
bool	vector<T, Alloc>::empty() const
{
	if (_size == 0)
		return (true);
	return (false);
}

//reserve
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

//resize
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

//erase
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

template <typename T, typename Alloc>
void	vector<T, Alloc>::clear(void)
{
	this->_size = 0;
}

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
}
