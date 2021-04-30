#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cstddef>
#include <iostream>
#include <exception>
#include <memory>
#include "../iterator/iterator.hpp"
#include "../iterator/vector_iterator.hpp"
#include "../iterator/utils.hpp"
#include "../iterator/function.hpp"
#include "../iterator/reverse_iterator.hpp"
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
			typedef typename ft::vector_iterator<pointer>	iterator;
			typedef typename ft::vector_iterator<const_pointer> const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
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
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			iterator end();
			const_iterator end() const;
			const_iterator cend() const throw();
			reverse_iterator rend();
			const_reverse_iterator rend() const;

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
			void	assign(size_type n, value_type const& val);
			template <typename InputIt>
			void	assign(InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type * = NULL);

	};

#include "vector2.hpp"
/*
template <typename t, typename alloc>
typename vector<t, alloc>::reverse_iterator vector<t,alloc>::rbegin()
{
	reverse_iterator ret(end());
	return (ret);
}
template <typename t, typename alloc>
typename vector<t, alloc>::const_reverse_iterator vector<t,alloc>::rbegin() const
{
	reverse_iterator ret(end());
	return (ret);
}
template <typename t, typename alloc>
typename vector<t, alloc>::reverse_iterator vector<t,alloc>::rend()
{
	reverse_iterator ret(begin());
	return (ret);
}
template <typename t, typename alloc>
typename vector<t, alloc>::const_reverse_iterator vector<t,alloc>::rend() const
{
	reverse_iterator ret(begin());
	return (ret);
}

template <typename t, typename alloc>
typename vector<t, alloc>::iterator	vector<t, alloc>::insert(iterator position, const value_type& val)
{
	iterator	cur;
	iterator	prev;

	if (this->_size  + 1 <= this->_capacity)
	{
		// 값을 대입하려는 위치가 기준.(cur)
		for (cur = end() ; _size && cur > position ; --cur)
		{
			prev = cur - 1;
			*cur = *prev;
		}
		*cur = val;
		this->_size++;
		return	(cur);
	}
	else
	{
		int			i;
		size_type	alloc_cnt;
		pointer		temp;

		i = this->_size;
		alloc_cnt = ft::max((_capacity * 2), (_size + 1));
		try
		{
			temp = get_allocator().allocate(alloc_cnt);
		}
		catch (std::exception &err)
		{
			std::cout << "error : " << err.what() << std::endl;
		}
		// 대입하려는 값의 위치가 기준.(cur)
		for  (cur = end() - 1; _size && cur >= position ; --cur)
		{
			temp[i] = *cur;
			i--;
		}
		temp[i] = val;
		cur = &temp[i];
		for (--i ; i >= 0 ; --i)
		{
			temp[i] = this->_arr[i];
		}
		get_allocator().deallocate(this->_arr, this->_capacity);
		this->_size++;
		this->_capacity = alloc_cnt;
		this->_arr = temp;
	}
	return (cur);
}

template <typename t, typename alloc>
void	vector<t, alloc>::insert(iterator position, size_type n, const value_type& val)
{
	iterator cur;
	iterator last;

	if (this->_size + n <= this->_capacity)
	{
		last = position + (n - 1);
		// 값을 대입할 곳의 위치 기준(cur)
		for (cur = end() - 1 + n ; _size && cur > last ; --cur)
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
		int			i;
		size_type	alloc_cnt;
		pointer		temp;

		alloc_cnt = ft::max((_capacity * 2), (_size + n));
		try
		{
			temp = get_allocator().allocate(alloc_cnt);
		}
		catch (std::exception &err)
		{
			std::cout << "error : " << err.what() << std::endl;
		}
		i = (this->_size - 1 + n);
		for  (cur = end() - 1; _size && cur >= position ; --cur)
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
		this->_capacity = alloc_cnt;
		this->_arr = temp;
	}
}

template <typename t, typename alloc>
template <typename inputit>
void	vector<t, alloc>::insert(iterator position, inputit first, inputit last, typename ft::is_iterator<!ft::is_arithmetic<inputit>::value, inputit>::type*)
{
	difference_type n;
	iterator cur;
	iterator last_target;
	inputit cur_value;

	n = ft::distance(first, last);
	if (this->_size + n <= this->_capacity)
	{
		last_target = position + (n - 1);
		for (cur = end() - 1 + n ; _size && cur > last_target ; --cur)
		{
			*cur = *(cur - n);
		}
		cur_value = last - 1;
		for (int cnt = 0; cnt < n ; cnt++)
		{
			*cur = *cur_value;
			--cur_value;
			--cur;
		}
		this->_size += n;
	}
	else
	{
		int			i;
		size_type	alloc_cnt;
		pointer		temp;

		alloc_cnt = ft::max((_capacity * 2), (_size + n));
		try
		{
			temp = get_allocator().allocate(alloc_cnt);
		}
		catch (std::exception &err)
		{
			std::cout << err.what() << std::endl;
		}
		i = (this->_size - 1 + n);
		for  (cur = end() - 1; _size && cur >= position ; --cur)
		{
			temp[i] = *cur;
			i--;
		}
		cur_value = last - 1;
		for (int cnt = 0; cnt < n ; cnt++)
		{
			temp[i--] = *cur_value;
			--cur_value;
		}
		for (; i >= 0 ; --i)
		{
			temp[i] = this->_arr[i];
		}
		get_allocator().deallocate(this->_arr, this->_capacity);
		this->_size += n;
		this->_capacity = alloc_cnt;
		this->_arr = temp;
	}
}

// assign
template <typename t, typename alloc>
void	vector<t, alloc>::assign(size_type n, value_type const& val)
{
	if (n <= this->_capacity)
	{
		for (int i = 0 ; i < n ; i++)
		{
			this->_arr[i] = val;
		}
		_size = n;
		return ;
	}
	get_allocator().deallocate(this->_arr, this->_capacity);
	try
	{
		this->_arr = get_allocator().allocate(n);
	}
	catch (std::exception &err)
	{
		std::cout << "error : " << err.what() << std::endl;
	}
	for (int i = 0; i < n ; i++)
	{
		this->_arr[i] = val;
	}
	_size = n;
	_capacity = n;
	return ;
}

template <typename t, typename alloc>
template <typename inputit>
void	vector<t, alloc>::assign(inputit first, inputit last, typename ft::is_iterator<!ft::is_arithmetic<inputit>::value, inputit>::type *)
{
	int i = 0;
	difference_type n;

	n = ft::distance(first, last);
	if (n <= this->_capacity)
	{
		for (; first != last ; ++first)
		{
			this->_arr[i++] = *first;
		}
		_size = n;
		return ;	
	}
	get_allocator().deallocate(this->_arr, this->_capacity);
	try
	{
		this->_arr = get_allocator().allocate(n);
	}
	catch(std::exception &err)
	{
		std::cout << "error : " << err.what() << std::endl;
	}
	for (; first != last ; ++first)
	{
		this->_arr[i++] = *first;
	}
	_size = n;
	_capacity = n;
	return ;

	
}

//swap
template <typename t, typename alloc>
void	vector<t, alloc>::swap(vector &x)
{
	swap(*this, x);
}

template <typename t, typename alloc>
void	swap(vector<t, alloc> &x, vector<t, alloc>& y)
{
	typename vector<t, alloc>::pointer temp_ptr;
	typename vector<t, alloc>::size_type temp_size;
	typename vector<t, alloc>::size_type temp_capacity;

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
*/
}
#endif
