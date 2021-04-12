#ifndef TEST_HPP
# define TEST_HPP

#include "easyfind.hpp"

template <typename T>
void	printContainer(T &container)
{
	std::cout << "IN THE CONTAINER ----------------\n";
	typename T::iterator it;
	it = container.begin();
	for  (it = container.begin() ; it != container.end() ; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;
}

template <typename T>
void	testFind(T &container, int value)
{
	std::cout << "TEST FIND -----------------------\n";
	try
	{
		std::cout << "Trying to find " << value << std::endl;
		typename T::iterator res = easyfind(container, value);
		std::cout << *res << std::endl;
	}
	catch (std::exception & err)
	{
		std::cout << "Not Found\n";
	}
	std::cout << std::endl;
}
#endif
