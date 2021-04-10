#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
	T *arr;
	unsigned int arr_size;
public:
	Array();
	Array(unsigned int n);
	~Array();
	Array(Array<T> const  & src);
	T& operator[](int idx);
	const T& operator[](int idx) const;
	Array<T>& operator=(Array<T> const & src);
	size_t size() const;
};

template <typename T>
Array<T>::Array()
{
	arr = 0;
	arr_size = 0;
}

template <typename T>
Array<T>::~Array()
{
	if (arr_size > 0)
		delete [] arr;
}
template <typename T>
T& Array<T>::operator[](int idx)
{
	if (idx < 0 || idx > static_cast<int>(this->arr_size) - 1)
		throw (std::exception());
	return (this->arr[idx]);
}

template <typename T>
const T& Array<T>::operator[](int idx) const
{
	if (idx < 0 || idx > static_cast<int>(this->arr_size) - 1)
		throw (std::exception());
	return (this->arr[idx]);
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->arr_size = n;
	arr = new T[n]();
}

template <typename T>
Array<T>::Array(Array<T> const & src)
{
	this->arr_size = src.arr_size;
	this->arr = 0;
	if (src.arr_size > 0)
	{
		this->arr = new T[src.arr_size];
		for (int i = 0 ; i < static_cast<int>(src.arr_size) ; i++)
		{
			this->arr[i] = src.arr[i];
		}
	}
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> const & src)
{
	if (this != &src)
	{
		if (this->arr_size > 0)
			delete [] arr;
		this->arr_size = src.arr_size;
		this->arr = new T[src.arr_size];
		for (int i = 0; i < static_cast<int>(src.arr_size) ; i++)
		{
			this->arr[i] = src.arr[i];
		}
	}
	return (*this);
}

template <typename T>
size_t Array<T>::size(void) const
{
	return (arr_size);
}

#endif
