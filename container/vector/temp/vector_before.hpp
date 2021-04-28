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
			const_iterator cbegin() const throw();
			iterator end();
			const_iterator end() const;
			const_iterator cend() const throw();


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
			iterator	erase(iterator first, iterator last);
			void		clear();
			void		swap(vector &x);
			iterator	insert(iterator position, const value_type& val);
			void		insert(iterator position, size_type n, const value_type& val);
			template <typename InputIt>
			void	insert(iterator position, InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type* = NULL);
	};


#include "vector2.hpp"

	/*
// 소멸자
template <typename T, typename Alloc>
vector<T,Alloc>::~vector()
{
	get_allocator().deallocate(this->_arr, this->_capacity);
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
vector<T, Alloc>::vector (InputIt first, InputIt last, allocator_type const & alloc, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type *)
{
	allocator_type	new_alloc(alloc);
	difference_type	diff;
	InputIt			it;
	int				i;

	std::cout << "Iterator\n";			//temp
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
	std::cout << "copy\n";			//temp
	this->_size = x._size;
	this->_capacity = x._capacity;
	this->_arr = x.get_allocator().alloacate(this->_capacity);
	for (size_type i = 0; i < this->_size ; i++)
	{
		this->_arr[i] = x._arr[i];
	}
}

// operator=
template <typename T, typename Alloc>
vector<T,Alloc>& vector<T,Alloc>::operator=(vector const & x)
{
	std::cout << "operotr=\n";		//temp
	if (this != &x)
	{
		get_allocator().deallocate(this->_arr, this->_capacity);
		this->_size = x._size;
		this->_capacity = x._size;
		this->_arr = get_allocator().allocate(this->_capacity);
		for (size_type i = 0 ; i < this->_size ; i++)
		{
			this->_arr[i] = x._arr[i];
		}
	}
	return (*this);
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
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cbegin() const throw()
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
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cend() const throw()
{
	return ((_arr[_size]));
}

//operator []
template <typename T, typename Alloc>
typename vector<T,Alloc>::reference vector<T,Alloc>::operator[] (size_type n)
{
	return (this->_arr[n]);
}

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
	pointer temp;

	if (this->_size > n)
	{
		this->_size = n;
		return ;
	}
	else if (this->_size < n && n <= this->_capacity)
	{
		size_type cnt;

		cnt = n - this->_size;
		for (size_type i = 0 ; i < cnt ; i++)
		{
			push_back(val);
		}
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
		this->_arr = temp;
	}
}

//erase
template <typename T, typename Alloc>
typename vector<T,Alloc>::iterator vector<T,Alloc>::erase(iterator position)
{
	iterator res(position);
	iterator target;

	target = this->end() - 1;
	for (; position != target ; ++position)
	{
		*position = *(position + 1);
	}
	this->_size--;
	return (res);
}

template <typename T, typename Alloc>
typename vector<T,Alloc>::iterator vector<T,Alloc>::erase(iterator first, iterator last)
{
	iterator res(first);
	iterator target;
	difference_type diff;

	diff = ft::distance(first, last);
	target = this->end() - diff;
	for (; first != target ; ++first)
	{
		*first = *(first + diff);
	}
	this->_size -= (diff);
	return (res);
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::clear(void)
{
	this->_size = 0;
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
	catch (std::exception & err)
	{
		std::cout << "Error : " << err.what() << std::endl;
		return ;
	}
	for (size_type i = 0 ; i < _size ; i++)
	{
		temp[i] = _arr[i];
	}
	temp[_size] = val;
	alloc.deallocate(_arr, this->_capacity);
	_arr = temp;
	_size++;
	_capacity *= 2;
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::pop_back(void)
{
	_size--;
}
*/

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::insert(iterator position, const value_type& val)
{
	pointer		temp;
	iterator	cur;
	iterator	prev;

	if (this->_size < this->_capacity)
	{
		for (cur = end() ; cur != position ; --cur)
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
		get_allocator().deallocate(this->_arr, this->_capacity); // check
		this->_size++;
		this->_capacity *= 2;
		this->_arr = temp;
	}
	return (cur);
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
	pointer temp;
	iterator cur;
	iterator last;

	if (this->_size + n <= this->_capacity)
	{
		last = position + (n - 1);
		for (cur = last + n + 1; cur != last ; --cur)
		{
			*cur = *(cur - n);
		}
		for (cur = position ; cur <= last ; ++cur)
		{
			*cur = val;
		}
		this->_size += n;
	}
	else if (this->_size + n > this->_capacity)
	{
		int i;
		size_type alloc_cnt;
		i = (this->_size - 1 + n);
		alloc_cnt = this->_capacity < n ? n : this->_capacity;
		temp = get_allocator().allocate(alloc_cnt);
		for  (cur = end() - 1; cur >= position ; --cur)
		{
			temp[i] = *cur;
			i--;
		}
		for (int cnt = 0 ; cnt < n ; cnt++)
		{
			temp[i--] = val;
		}
		for (; i >= 0 ; --i)
		{
			temp[i] = this->_arr[i];
		}
		get_allocator().deallocate(this->_arr, this->_capacity);
		this->_size += n;
		this->_capacity += alloc_cnt;
		this->_arr = temp;
	}
}


template <typename T, typename Alloc>
template <typename InputIt>
void	vector<T, Alloc>::insert(iterator position, InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type*)
{
	difference_type n;
	iterator cur;
	iterator last_target;
	InputIt cur_value(first);

	n = ft::distance(first, last);
	if (this->_size + n <= this->_capacity)
	{	
		last_target = position + (n - 1);
		for (cur = last_target + n + 1; cur != last_target ; --cur)
		{
			*cur = *(cur - n);
		}
		for (cur = position ; cur <= last_target ; ++cur)
		{
			*cur = *cur_value;
			++cur_value;
		}
		this->_size += n;
	}
	else
	{
	}
}


//assign

//swap
template <typename T, typename Alloc>
void	vector<T, Alloc>::swap(vector &x)
{
	swap(*this, x);
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

}
#endif
