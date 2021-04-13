#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cstddef>
#include <iostream>
#include <exception>
#include <cmath>
namespace ft
{

template <typename T>
class vector
{
private:
	T *_arr;
	size_t _size;
	size_t _capacity;

public:
	typedef T value_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	explicit vector();
	explicit vector(size_type n, const value_type & val = value_type());
	vector (vector const & x);
	vector& operator= (vector const & x);
	~vector() throw();

	size_type size() const;
	size_type capacity() const;
	size_type max_size() const;
	void	reserve(size_type n);
	void	resize(size_type n, value_type val = value_type());
};

// 소멸자
template <typename T>
vector<T>::~vector() throw()
{
	if (_arr)
		delete [] _arr;
}

// default 생성자
template <typename T>
vector<T>::vector() : _arr(0), _size(0), _capacity(0) {}

// fille 생성자
template <typename T>
vector<T>::vector(size_type n, const value_type & val)
{
	_arr = new value_type[n];
	_size = n;
	_capacity = n;
	for (size_type i = 0; i < n ; i++)
	{
		_arr[i] = val;
	}
	/*
	for (size_type i = 0; i  < n ; i++)
	{
		std::cout << _arr[i] << std::endl;
	}
	*/
}

// copy 생성자
template <typename T>
vector<T>::vector(vector const & x)
{
	*this = x;
}

// operator=
template <typename T>
vector<T>& vector<T>::operator=(vector const & x)
{
	if (this != &x)
	{
		if (this->_size > 0)
			delete [] this->_arr;
		this->_size = x._size;
		this->_capacity = x._size;
		this->_arr = new value_type[this->_size];
		for (size_type i = 0 ; i < this->_size ; i++)
		{
			this->_arr[i] = x._arr[i];
		}
	}
	return (*this);
}

// size
template <typename T>
typename vector<T>::size_type vector<T>::size() const
{
	return (this->_size);
}

//capacity
template <typename T>
typename vector<T>::size_type vector<T>::capacity() const
{
	return (this->_capacity);
}

//max size
template <typename T>
typename vector<T>::size_type vector<T>::max_size() const
{
	static size_type pointerBitWidth = 64;


	//return ((pow(2, pointerBitWidth) / sizeof(value_type)) - 1);
	//return (pow(2, pointerBitWidth));
	return (static_cast<size_type>((pow(2, pointerBitWidth) / sizeof(value_type))) - 1);
}

//reserve
template <typename T>
void	vector<T>::reserve(size_type n)
{
	value_type *temp;

	/* max_size 정의 후에 수정.
	if (n > max_size)
		throw (std::exception ()); // length_error 로 바꾸기 
	*/
	if (this->_capacity >= n)
		return ;
	temp = new value_type[n];
	this->_capacity = n;
	for (size_type i = 0 ; i < this->_size ; i++)
	{
		temp[i] = this->_arr[i];
	}
	delete [] this->_arr;
	this->_arr = temp;
	return ;
}

//resize
template <typename T>
void	vector<T>::resize(size_type n, value_type val)
{
	value_type *temp;
	if (this->_size > n)
	{
		this->_size = n;
		return ;
	}
	else if (this->_size < n && n <= this->_capacity)
	{
		// insert
	}
	else if (this->_capacity < n)
	{
		temp = new value_type[n];
		for (size_type i = 0 ; i < this->_size ; i++)
		{
			temp[i] = this->_arr[i];
		}
		for (size_type i = this->_size ; i < n ; i++)
		{
			temp[i] = val;
		}
		this->_size = n;
		this->_capacity = n;
	}
}
}
#endif
