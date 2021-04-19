#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cstddef>
#include <iostream>
#include <exception>
#include <cmath>
#include <memory>
#include "../iterator/iterator.hpp"
#include "../iterator/iter_category.hpp"

namespace ft
{
template <typename T, typename Alloc = std::allocator<T> >
class vector
{
private:
	T *_arr;
	size_t _size;
	size_t _capacity;

public:
	typedef T								value_type;
	typedef std::allocator<value_type>		allocator_type;
	typedef size_t 							size_type;
	typedef ptrdiff_t						difference_type;
	typedef value_type* 					pointer;
	typedef const value_type*				const_pointer;
	typedef value_type&						reference;
	typedef const value_type&				const_reference;
	typedef ft::random_access_iterator_tag	iterator_type;

	class iterator : ft::iterator<iterator_type, value_type>
	{
		private:
			pointer _ptr;
		public:
			iterator() : _ptr(0) { }
			~iterator(){}
			iterator(reference src){ _ptr = &src;}
			iterator(pointer src){_ptr = src;}
			iterator(iterator & rhs){ this->_ptr = rhs._ptr; }
			reference operator*(){return (*_ptr);}
			iterator& operator=(iterator const & rhs){this->_ptr = rhs._ptr; return (*this);}
			iterator& operator++(){++_ptr; return (*this);}
			iterator operator++(int){iterator ret = *this; ++ret; return (*this);};
			iterator& operator--(){--_ptr; return (*this);};
			iterator operator--(int){iterator ret = *this; --ret; return (*this);};

			//operator->;
			bool operator==(iterator const & rhs){return (this->_ptr == rhs->_ptr);};
			bool operator!=(iterator const &rhs){return (this->_ptr != rhs->_ptr);};
			iterator& operator+=(int n)
			{
				this->_ptr += n;
				return (*this);
			}
			iterator &operator-=(int n)
			{
				this->_ptr -= n;
				return (*this);
			}
			reference operator[](int n)
			{
				return (*(_ptr += n));
			}
			/*operator>;
			operator<;
			operator<=;
			operator>=;*/

			pointer operator+(int n)
			{
				return (this->_ptr + n);
			}
			pointer operator-(int n)
			{
				return (this->_ptr - n);
			}
	};
	explicit vector(allocator_type const &aloc = allocator_type() );
	explicit vector(size_type n, const value_type & val = value_type(),allocator_type const& alloc = allocator_type());
	vector (vector const & x);
	vector& operator= (vector const & x);
	~vector() throw();
	
	reference operator[] (size_type n);
	const_reference operator[] (size_type n) const;
	reference at(size_type n);
	const_reference at(size_type n) const;
	reference front();
	const_reference front() const;
	reference back();
	const_reference back() const;

	size_type size() const;
	size_type capacity() const;
	size_type max_size() const;
	void	reserve(size_type n);
	void	resize(size_type n, value_type val = value_type());

	iterator begin();
//	const_iterator begin() const;
	iterator end();
//	const_iterator end() const;
};

// 소멸자
template <typename T, typename Alloc>
vector<T,Alloc>::~vector() throw()
{
	if (_arr)
		delete [] _arr;
}

// default 생성자
template <typename T, typename Alloc>
vector<T,Alloc>::vector(allocator_type const & aloc) : _arr(0), _size(0), _capacity(0) {}

// fille 생성자
template <typename T, typename Alloc>
vector<T,Alloc>::vector(size_type n, const value_type & val, allocator_type const &alloc)
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
template <typename T, typename Alloc>
vector<T,Alloc>::vector(vector const & x)
{
	*this = x;
}

// operator=
template <typename T, typename Alloc>
vector<T,Alloc>& vector<T,Alloc>::operator=(vector const & x)
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

//operator []
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::operator[] (size_type n)
{
	return (this->_arr[n]);
}

//const opeartor[]
template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::operator[] (size_type n) const
{
	return (this->_arr[n]);
}

// at
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::at(size_type n)
{
	if (n < 0 || n >= this->_size)
		throw (std::out_of_range("Out of range"));
	return (this->_arr[n]);
}

// const at
template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::at(size_type n) const
{
	if (n < 0 || n >= this->_size)
		throw (std::out_of_range("Out of range"));
	return (this->_arr[n]);
}

// front
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::front()
{
	return (this->_arr[0]);
}

// const front
template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::front() const
{
	return (this->_arr[0]);
}

//back
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::back()
{
	return (this->_arr[this->_size - 1]);
}

// const back
template <typename T, typename Alloc>
typename vector<T,Alloc>::const_reference vector<T,Alloc>::back() const
{
	return (this->_arr[this->_size - 1]);
}


// size
template <typename T, typename Alloc>
typename vector<T,Alloc>::size_type vector<T,Alloc>::size() const
{
	return (this->_size);
}

//capacity
template <typename T, typename Alloc>
typename vector<T,Alloc>::size_type vector<T,Alloc>::capacity() const
{
	return (this->_capacity);
}

//max size
template <typename T, typename Alloc>
typename vector<T,Alloc>::size_type vector<T,Alloc>::max_size() const
{
	static size_type pointerBitWidth = 64;
	//return ((pow(2, pointerBitWidth) / sizeof(value_type)) - 1);
	//return (pow(2, pointerBitWidth));
	return (static_cast<size_type>((pow(2, pointerBitWidth) / sizeof(value_type))) - 1);
}

//reserve
template <typename T, typename Alloc>
void	vector<T,Alloc>::reserve(size_type n)
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
template <typename T, typename Alloc>
void	vector<T,Alloc>::resize(size_type n, value_type val)
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

//begin
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
{
	iterator res(this->_arr[0]);
	return (res);
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
{
	iterator res(this->_arr[this->_size]);
	return (res);
}

}
#endif
