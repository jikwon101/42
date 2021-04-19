#ifndef OPERATOR_HPP
# define OPERATOR_HPP

#include "vector.hpp"

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

#endif
