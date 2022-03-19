template <typename T, typename Container>
stack<T, Container>::stack(const container_type& cntr)
	: c(cntr)
{}

template <typename T, typename Container>
stack<T, Container>::~stack()
{}

template <typename T, typename Container>
stack<T, Container>&	
	stack<T, Container>::operator=(const stack& other)
{
	if (this != &other)
	{
		c = other.c;
	}
	return (*this);
}

template <typename T, typename Container>
bool	
	stack<T, Container>::empty() const
{
	return (c.empty());
}

template <typename T, typename Container>
typename stack<T, Container>::size_type	
	stack<T, Container>::size() const
{
	return (c.size());
}

template <typename T, typename Container>
typename stack<T, Container>::value_type&
	stack<T, Container>::top()
{
	return (c.back());
}

template <typename T, typename Container>
const typename stack<T, Container>::value_type&
	stack<T, Container>::top() const
{
	return (c.back());
}

template <typename T, typename Container>
void
	stack<T, Container>::push(const value_type& val)
{
	return (c.push_back(val));
}

template <typename T, typename Container>
void
	stack<T, Container>::pop()
{
	return (c.pop_back());
}
	
template <typename T, typename Container>
bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (lhs.c == rhs.c);
}

template <typename T, typename Container>
bool	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (lhs.c != rhs.c);
}

template <typename T, typename Container>
bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (lhs.c < rhs.c);
}

template <typename T, typename Container>
bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (lhs.c <= rhs.c);
}

template <typename T, typename Container>
bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (lhs.c > rhs.c);
}

template <typename T, typename Container>
bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (lhs.c >= rhs.c);
}
