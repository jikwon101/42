#ifndef VECTOR_CONST_ITERATOR_HPP
# define VECTOR_CONST_ITERATOR_HPP

#include <exception>
#include "./iterator.hpp"
#include "./iter_category.hpp"

namespace ft
{

	template <typename _ITER_TAG, typename _VAL_TYPE>
	class vector_const_iterator : public ft::iterator<_ITER_TAG, _VAL_TYPE>
	{
		private:
			typedef vector_const_iterator<_ITER_TAG, _VAL_TYPE> iterator;
		public:
			typedef typename ft::iterator<_ITER_TAG, _VAL_TYPE>::value_type value_type;
			typedef typename ft::iterator<_ITER_TAG, _VAL_TYPE>::pointer pointer;
			typedef typename ft::iterator<_ITER_TAG, _VAL_TYPE>::reference reference;
		
			value_type * _ptr;						//temp;
			vector_const_iterator() : _ptr(0) { }
			~vector_const_iterator(){}
			vector_const_iterator(reference const src)
			{
				_ptr = &src;
			}
			vector_const_iterator(pointer const src)
			{
				_ptr = src;
			}
			vector_const_iterator(iterator const& rhs)
			{
				this->_ptr = rhs._ptr; 
			}
	
			// const reference?? 왜 안되지?
			value_type const&operator*() const
			{
				return (*_ptr);
			}
					
			iterator& operator++()
			{
				++_ptr; return (*this);
			}
			iterator operator++(int)
			{
				iterator ret = *this; 
				++ret; 
				return (*this);
			}
			iterator& operator--()
			{
				--_ptr; 
				return (*this);
			}
			iterator operator--(int)
			{
				iterator ret = *this; 
				--ret; 
				return (*this);
			}
	
			const pointer operator->() const
			{
				return (_ptr);
			}

			bool operator==(iterator const & rhs) const
			{
				return (this->_ptr == rhs._ptr);
			}
			bool operator!=(iterator const &rhs) const
			{
				return (this->_ptr != rhs._ptr);
			}
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

			// why?
			value_type const& operator[](int n)
			{
				return (*(_ptr += n));
			}
			
			bool operator>(iterator const& other) const
			{
				return (this->_ptr > other._ptr);
			}
			bool operator<(iterator const& other) const
			{
				return (this->_ptr < other._ptr);
			}
			bool operator<=(iterator const& other) const
			{
				return (this->_ptr <= other._ptr);
			}
			bool operator>=(iterator const& other) const
			{
				return (this->_ptr >= other._ptr);
			}
			iterator operator+(int n) const
			{
				return (this->_ptr + n);
			}
			iterator operator-(int n) const
			{
				return (this->_ptr - n);
			}
	};

	//temp 나중에 삭제 하기
	template <typename _ITER_TAG, typename _VAL_TYPE>
	std::ostream & operator<<(std::ostream & os, vector_const_iterator<_ITER_TAG, _VAL_TYPE> const & it)
	{
		os << it._ptr;
		return (os);
	}


}

#endif
