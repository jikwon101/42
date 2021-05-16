template <typename T, typename Alloc>
void	vector<T,Alloc>::destruct_by(pointer _new_end)
{
	pointer _pos(_end);

	if (_new_end >= _end)
		return ;
	for (--_pos; _pos >= _new_end; --_pos)
	{
		if (_begin <= _pos && _pos < _end)
			alloc_type().destroy(_pos);
	}
	_end = _new_end;
	return ;
}
template <typename T, typename Alloc>
void	vector<T, Alloc>::destruct_at(pointer _pos)
{
	if (_begin <= _pos && _pos < _end)
		alloc_type().destroy(_pos);
}

template <typename T, typename Alloc>
void	vector<T,Alloc>::destruct_range(pointer _start, pointer _last)
{
	for (; _start != _last ; ++_start)
	{
		if (_begin <= _start && _start < _end)
			alloc_type().destroy(_start);
	}
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::construct_one_at_end(const_reference rhs)
{
	alloc_type().construct(_end++, rhs);
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::construct_at_end(size_type n, const_reference rhs)
{
	pointer new_end;

	new_end = _end + n;
	for (; _end != new_end ; ++_end)
		alloc_type().construct(_end, rhs);
	_end = new_end;
}

template <typename T, typename Alloc>
template <typename InputIt>
void	vector<T, Alloc>::construct_at_end(InputIt _first, InputIt _last, 
		typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type *)
{
	for (; _first != _last ; ++_first)
	{
		alloc_type().construct(_end++, *_first);
	}
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::append(size_type n, const_reference rhs)
{	
	//if (static_cast<size_type>(end_cap() - _end)  >= n)
	if (static_cast<size_type>(_end_cap - _end)  >= n)	//new
	{
		construct_at_end(n, rhs);
	}
	else
	{
		vector new_vec((alloc_type()));
		size_type _new_n;

		_new_n = (capacity() * 2 > size() + n) ? (capacity() * 2) : (size() + n);
		new_vec.vector_allocate(_new_n);
		new_vec.construct_at_end(_begin, _end);
		new_vec.construct_at_end(n, rhs);
		swap(new_vec);
	}

}

template <typename T, typename Alloc>
void	vector<T, Alloc>::vector_allocate(size_type n)
{
	if (n > max_size())
		throw (std::length_error("Length Error"));
	_begin = _end = alloc_type().allocate(n);
	_end_cap = _begin + n;	//new
	//end_cap() = _begin + n;
}
