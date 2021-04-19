#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cstddef>
#include <iostream>
#include <exception>
#include <cmath>
#include <memory>
#include "../iterator/iterator.hpp"
#include "../iterator/iter_category.hpp"
#include "../iterator/random_access_iterator.hpp"

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
			typedef typename ft::random_access_iterator_tag					iterator_type;
			typedef typename ft::vector_iterator<iterator_type, value_type> iterator;
			explicit vector(allocator_type const &aloc = allocator_type() );
			explicit vector(size_type n, const value_type & val = value_type(),allocator_type const& alloc = allocator_type());
			template <typename InputIterator>
			vector (InputIterator first, InputIterator last, allocator_type const & alloc = allocator_type(), typename ft::enable_if<ft::is_iterator<InputIterator>::value>::type isIter = InputIterator());
			vector (vector const & x);
			vector& operator= (vector const & x);
			~vector() throw();
	
			//iterator
			iterator begin();
			//	const_iterator begin() const;
			iterator end();
			//	const_iterator end() const;


			// element access
			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;
			reference at(size_type n);
			const_reference at(size_type n) const;
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;

			// capacity
			size_type size() const;
			size_type capacity() const;
			size_type max_size() const;
			bool	empty() const;
			void	reserve(size_type n);
			void	resize(size_type n, value_type val = value_type());
			
			// modifier
			void push_back(value_type const & val);
			void	pop_back(void);
			iterator erase(iterator position);
			void	clear();
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
vector<T,Alloc>::vector(allocator_type const & aloc) : _arr(0), _size(0), _capacity(0) {(void)aloc;}

// fill 생성자
template <typename T, typename Alloc>
vector<T,Alloc>::vector(size_type n, value_type const& val, allocator_type const &alloc)
{
	//_arr = alloc.allocate(n);
	_arr = new value_type[n];
	_size = n;
	_capacity = n;
	for (size_type i = 0; i < n ; i++)
	{
		_arr[i] = val;
	}
}

// range constructor
template <typename T, typename Alloc>
template <typename InputIterator>
vector<T, Alloc>::vector (InputIterator first, InputIterator last, allocator_type const &alloc, typename ft::enable_if<ft::is_iterator<InputIterator>::value>::type isIter )
{
	(void)isIter;
	//difference_type diff;

//	diff = ft::distance(first, last);
	//_arr = alloc.allocate(4);
//	std::cout << "distance : " << diff << std::endl;
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

// empty
template <typename T, typename Alloc>
bool	vector<T, Alloc>::empty() const
{
	if (_size == 0)
		return (true);
	return (false);
}

//reserve
template <typename T, typename Alloc>
void	vector<T,Alloc>::reserve(size_type n)
{
	value_type *temp;

//	 max_size 정의 후에 수정.
//	if (n > max_size)
//		throw (std::exception ()); // length_error 로 바꾸기 
	
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
		for (size_t i = 0 ; i < (n - _size) ; i++)
			push_back(val);
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

template <typename T, typename Alloc>
typename vector<T,Alloc>::iterator vector<T,Alloc>::erase(iterator position)
{
	iterator res(position);

	while (position != this->end())
	{
		*position = *(position + 1);
		++position;
	}
	this->_size--;
	return (res);
}


template <typename T, typename Alloc>
void	vector<T, Alloc>::clear(void)
{
	this->_size = 0;
}

//begin
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
{
	return ((_arr[0]));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
{
	return ((_arr[_size]));
}

template <typename T, typename Alloc>
void vector<T, Alloc>::push_back(value_type const & val)
{
	allocator_type alloc;
	pointer temp;

	if (_size < _capacity)
	{
		_arr[_size] = val;
		_size++;
		return ;
	}
	try
	{
		temp = alloc.allocate(_capacity * 2);
	}
	catch (std::exception &err)
	{
		std::cout << "Error : " << err.what() <<std::endl;
		return ;
	}
	for (size_type i = 0 ; i < _size ; i++)
	{
		temp[i] = _arr[i];
	}
	temp[_size] = val;
	alloc.deallocate(_arr, this->capacity());
	_arr = temp;
	_size++;
	_capacity *= 2;
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::pop_back(void)
{
	_size--;
}

}
#endif
