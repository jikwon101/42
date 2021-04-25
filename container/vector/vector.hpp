#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cstddef>
#include <iostream>
#include <exception>
#include <cmath>
#include <memory>
#include "../iterator/iterator.hpp"
#include "../iterator/iter_category.hpp"
#include "../iterator/vector_iterator.hpp"
#include "../iterator/vector_const_iterator.hpp"

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
			typedef typename ft::random_access_iterator_tag					iterator_category;
			typedef typename ft::vector_iterator<iterator_category, value_type> iterator;
			typedef typename ft::vector_const_iterator<iterator_category, value_type> const_iterator;
			explicit vector(allocator_type const &alloc = allocator_type() );
			explicit vector(size_type n, const value_type & val = value_type(), allocator_type const& alloc = allocator_type());
			template <typename InputIt>
			vector(InputIt first, InputIt last, allocator_type const& alloc = allocator_type(), 
			typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type * = NULL);
			vector(vector const & x);
			vector& operator= (vector const & x);
			~vector();

			allocator_type	get_allocator() const;
	
			//iterator
			iterator begin();
			const_iterator begin() const;
			const_iterator cbegin() const;
			iterator end();
			const_iterator end() const;
			const_iterator cend() const;


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
			void		push_back(value_type const & val);
			void		pop_back(void);
			iterator	erase(iterator position);
			void		clear();
			void		swap(vector &x);
			iterator	insert(iterator position, const value_type& val);
			void		insert(iterator position, size_type n, const value_type& val);
			//template <typename InputIt>
			//void		insert(iterator position, InputIt first, InputIt last);
	};

// 소멸자
template <typename T, typename Alloc>
vector<T,Alloc>::~vector()
{
	if (_arr)
		delete [] _arr;
}

// default 생성자
template <typename T, typename Alloc>
vector<T,Alloc>::vector(allocator_type const & alloc) : _arr(0), _size(0), _capacity(0) 
{
	std::cout << "default\n";
}

// fill 생성자
template <typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n, const value_type & val, allocator_type const& alloc)
{
	allocator_type	new_alloc(alloc);
	
	std::cout << "size\n";			//temp
	_arr = new_alloc.allocate(n);
	_size = n;
	_capacity = n;
	for (size_type i = 0; i < n ; i++)
	{
		_arr[i] = val;
	}
}

// range 생성자
template <typename T, typename Alloc>
template <typename InputIt>
vector<T, Alloc>::vector (InputIt first, InputIt last, allocator_type const & alloc, 
		typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type *)
{
	allocator_type	new_alloc(alloc);
	difference_type	diff;
	InputIt			it;
	int				i;

	std::cout << "Iterator\n";
	diff = ft::distance(first, last);
	_arr = new_alloc.allocate(diff);
	i = 0;
	for (it = first ; it != last ; ++it)
	{
		*(_arr + ft::distance(first, it)) = *it;
	}
	this->_size = diff;
	this->_capacity = diff;
}

// copy 생성자
template <typename T, typename Alloc>
vector<T,Alloc>::vector(vector const & x)
{
	std::cout << "copy\n";
	*this = x;
}

// operator=
template <typename T, typename Alloc>
vector<T,Alloc>& vector<T,Alloc>::operator=(vector const & x)
{
		std::cout << "operotr=\n";
	if (this != &x)
	{
		if (this->_size > 0)
			delete [] this->_arr;
		this->_size = x._size;
		this->_capacity = x._size;
		this->_arr = get_allocator().allocate(this->_size);
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

//get_allocator
template <typename T, typename Alloc>
typename vector<T, Alloc>::allocator_type	vector<T, Alloc>::get_allocator() const
{
	return (allocator_type());
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
	//static size_type pointerBitWidth = 64;
	//return (static_cast<size_type>((pow(2, pointerBitWidth) / sizeof(value_type))) - 1);
	return (this->get_allocator().max_size());
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

	if (n > max_size())
		throw (std::length_error("Length error"));
	if (this->_capacity >= n)
		return ;
	temp = get_allocator().allocate(n);
	for (size_type i = 0 ; i < this->_size ; i++)
	{
		temp[i] = this->_arr[i];
	}
	get_allocator().deallocate(this->_arr, this->_capacity);
	this->_capacity = n;
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
		temp = get_allocator().allocate(n);
		for (size_type i = 0 ; i < this->_size ; i++)
		{
			temp[i] = this->_arr[i];
		}
		for (size_type i = this->_size ; i < n ; i++)
		{
			temp[i] = val;
		}
		get_allocator().deallocate(this->_arr, this->_capacity);
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
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
{
	return ((_arr[0]));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cbegin() const
{
	return ((_arr[0]));
}

//end
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
{
	return ((_arr[_size]));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
{
	return ((_arr[_size]));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cend() const
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

template <typename T, typename Alloc>
void	vector<T, Alloc>::swap(vector &x)
{
	swap(*this, x);
	/*
	pointer temp_ptr;
	size_type temp_size;
	size_type temp_capacity;

	temp_ptr = this->_arr;
	temp_size = this->_size;
	temp_capacity = this->_capacity;

	this->_arr = x._arr;
	this->_size = x._size;
	this->_capacity = x._capacity;

	x._arr = temp_ptr;
	x._size = temp_size;
	x._capacity = temp_capacity;
	*/
}

template <typename T, typename Alloc>
void	swap(vector<T, Alloc> &x, vector<T, Alloc>& y)
{
	typename vector<T, Alloc>::pointer temp_ptr;
	typename vector<T, Alloc>::size_type temp_size;
	typename vector<T, Alloc>::size_type temp_capacity;

	temp_ptr = x._arr;
	temp_size = x._size;
	temp_capacity = x._capacity;

	x._arr = y._arr;
	x._size = y._size;
	x._capacity = y._capacity;

	y._arr = temp_ptr;
	y._size = temp_size;
	y._capacity = temp_capacity;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::insert(iterator position, const value_type& val)
{
	pointer		temp;
	iterator	cur;
	iterator	prev;

	if (this->_size < this->_capacity)
	{
		for (cur = end() - 1; cur != position ; --cur)
		{
			prev = cur - 1;
			*cur = *prev;
		}
		*cur = val;
		this->_size++;
	}
	else if (this->_size == this->_capacity)
	{
		int i;

		i = this->_size;
		temp = get_allocator().allocate(this->_capacity * 2);
		for  (cur = end() - 1; cur >= position ; --cur)
		{
			temp[i] = *cur;
			i--;
		}
		cur = &temp[i];
		temp[i] = val;
		for (--i ; i >= 0 ; --i)
		{
			temp[i] = this->_arr[i];
		}
		this->_size++;
		this->_capacity *= 2;
		this->_arr = temp;
	}
	return (cur);
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
	iterator cur;
	iterator prev;
	iterator last;

	if (this->_size + n <= this->_capacity)
	{
		last = position + (n - 1);
		for (cur = last + n  + 1; cur != last ; --cur)
		{
			prev = cur - n;
			*cur = *prev;
		}
		for (cur = position - 1; cur <= last ; ++cur)
		{
			*cur = val;
		}
	}
	else if (this->_size + n > this->_capacity)
	{
			//temp
	}
}

/*
template <typename T, typename Alloc>
template <typename InputIt>
void	vector<T, Alloc>::insert(iterator position, InputIt first, InputIt last)
{
	std::cout << "hello\n";
}
*/
}
#endif
