#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *array, int length, void (*f)(T const &elt))
{
	for (int i = 0; i < length ; i++)
	{
		(*f)(array[i]);
	}
}

template <>
void iter(int *array, int length, void (*f)(int const &elt))
{
	for (int i = 0; i < length ; i++)
	{
		(*f)(array[i]);
		(*f)(array[i]);
	}
}

template <typename T>
void print(T const & elem)
{
	std::cout << elem << std::endl;
}

#endif
