#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <deque>
#include <list>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), value);
	if  (it == container.end())
	{
		throw (std::exception());
	}
	return (it);
}

#endif
