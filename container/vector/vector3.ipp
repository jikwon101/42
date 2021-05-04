template <typename T, typename Alloc>
typename vector<T, Alloc>::alloc_type&			vector<T, Alloc>::alloc() 
{
	return (_end_cap.second());
}
template <typename T, typename Alloc>
const typename vector<T, Alloc>::alloc_type&	vector<T, Alloc>::alloc() const
{
	return (_end_cap.second());
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::pointer&				vector<T, Alloc>::end_cap() 
{
	return (_end_cap.first());
}

template <typename T, typename Alloc>
const typename vector<T, Alloc>::pointer&		vector<T, Alloc>::end_cap() const
{
	return (_end_cap.first());
}

template <typename T, typename Alloc>
void	vector<T,Alloc>::destruct_by(pointer _new_end)
{
	pointer _pos(_end);

	for (--_pos; _pos != _new_end; --_pos)
	{
		alloc().destroy(_pos);
	}
	_end = _new_end;
	return ;
}

template <typename T, typename Alloc>
void	vector<T,Alloc>::destruct_range(pointer _start, pointer _last)
{
	for (; _start != _last ; ++_start)
		alloc().destroy(_start);
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::construct_at_end(size_type n)
{
	pointer new_end;

	new_end = _end + n;
	for (; _end != new_end ; ++_end)
		alloc().construct(_end, value_type());
	_end = new_end;
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::construct_at_end(size_type n, const_reference rhs)
{
	pointer new_end;

	new_end = _end + n;
	for (; _end != new_end ; ++_end)
		alloc().construct(_end, rhs);
	_end = new_end;
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::append(size_type n)
{
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::append(size_type n, const_reference rhs)
{
}
