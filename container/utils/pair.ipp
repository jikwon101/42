template <typename T1, typename T2>
pair<T1, T2>::pair() {}

template <typename T1, typename T2>
pair<T1, T2>::pair(const first_type& x, const second_type& y) 
		:first(x), second(y)
{}

template <typename T1, typename T2>
template <typename U1, typename U2>
pair<T1, T2>::pair(pair<U1, U2> const& src) 
		: first(src.first), second(src.second)
{}

template <typename T1, typename T2>
pair<T1, T2>::~pair() {}

template <typename T1, typename T2>
pair<T1, T2>&		pair<T1, T2>::operator=(const pair& src)
{
	if (this != &src)
	{
		this->first = src.first;
		this->second = src.second;
	}
	return (*this);
}

template <typename U1, typename U2>
bool	operator==(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs)
{
	if (lhs.first != rhs.first)
		return (false);
	if (lhs.second != rhs.second)
		return (false);
	return (true);
}

template <typename U1, typename U2>
bool	operator!=(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs)
{
	return (!(lhs == rhs));
}

template <typename U1, typename U2>
bool	operator<(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs)
{
	if (lhs.first > rhs.first)
		return (false);
	if (lhs.second >= rhs.second)
		return (false);
	return (true);
}

template <typename U1, typename U2>
bool	operator<=(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs)
{
	return (!(lhs > rhs));
}

template <typename U1, typename U2>
bool	operator>(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs)
{
	return (rhs < lhs);
}

template <typename U1, typename U2>
bool	operator>=(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs)
{
	return (!(lhs < rhs));
}

