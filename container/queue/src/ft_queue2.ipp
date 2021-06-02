template <typename T, typename Container>
queue<T, Container>::queue(const container_type& cntr)
	: c(cntr)
{}

template <typename T, typename Container>
queue<T, Container>::~queue()
{}

template <typename T, typename Container>
queue<T, Container>&	
	queue<T, Container>::operator=(const queue& other)
{
	if (this != &other)
	{
		c = other.c;
	}
	return (*this);
}

template <typename T, typename Container>
bool	
	queue<T, Container>::empty() const
{
	return (c.empty());
}

template <typename T, typename Container>
typename queue<T, Container>::size_type	
	queue<T, Container>::size() const
{
	return (c.size());
}

template <typename T, typename Container>
typename queue<T, Container>::value_type&
	queue<T, Container>::front()
{
	return (c.front());
}

template <typename T, typename Container>
const typename queue<T, Container>::value_type&
	queue<T, Container>::back() const
{
	return (c.front());
}
template <typename T, typename Container>
typename queue<T, Container>::value_type&
	queue<T, Container>::back()
{
	return (c.back());
}

template <typename T, typename Container>
const typename queue<T, Container>::value_type&
	queue<T, Container>::front() const
{
	return (c.back());
}

template <typename T, typename Container>
void
	queue<T, Container>::push(const value_type& val)
{
	return (c.push_back(val));
}

template <typename T, typename Container>
void
	queue<T, Container>::pop()
{
	return (c.pop_back());
}
	
template <typename T, typename Container>
bool	operator==(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
{
	return (lhs.c == rhs.c);
}

template <typename T, typename Container>
bool	operator!=(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
{
	return (lhs.c != rhs.c);
}

template <typename T, typename Container>
bool	operator<(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
{
	return (lhs.c < rhs.c);
}

template <typename T, typename Container>
bool	operator<=(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
{
	return (lhs.c <= rhs.c);
}

template <typename T, typename Container>
bool	operator>(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
{
	return (lhs.c > rhs.c);
}

template <typename T, typename Container>
bool	operator>=(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
{
	return (lhs.c >= rhs.c);
}
