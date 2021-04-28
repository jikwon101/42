#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include <exception>
#include "./iterator.hpp"
#include "./iter_category.hpp"

namespace ft
{
	// in vector class
	// typedef vector_iterator<value_type> iteratr;
	
	template <typename _VAL_TYPE> 
	class vector_iterator : public ft::iterator<ft::random_access_iterator_tag, _VAL_TYPE>
	{
		private:
			typedef ft::random_access_iterator_tag _ITER_TAG;
			typedef vector_iterator<_VAL_TYPE> iterator;
		public:
			typedef typename ft::iterator<_ITER_TAG, typename iterator_traits<_VAL_TYPE>::value_type >::value_type value_type;
			typedef typename ft::iterator<_ITER_TAG, typename iterator_traits<_VAL_TYPE>::value_type >::pointer pointer;
			typedef typename ft::iterator<_ITER_TAG, typename iterator_traits<_VAL_TYPE>::value_type >::reference reference;
		/*
			value_type * _ptr;				//temp;
			vector_iterator() : _ptr(0) { }
			~vector_iterator(){}
			vector_iterator(const reference src)
			{
				_ptr = &src;
			}
			vector_iterator(const pointer src)
			{
				_ptr = src;
			}
			vector_iterator(iterator const& rhs)
			{
				this->_ptr = rhs._ptr; 
			}

			reference operator*(){return (*_ptr);}
		

			iterator& operator=(iterator const & rhs)
			{
				this->_ptr = rhs._ptr; 
				return (*this);
			}

			
			//temp
			iterator& operator++(){++_ptr; return (*this);}
			iterator operator++(int){iterator ret = *this; ++ret; return (*this);}
			iterator& operator--(){--_ptr; return (*this);};
			iterator operator--(int){iterator ret = *this; --ret; return (*this);}
	
			pointer operator->()
			{
				return (_ptr);
			}
			bool operator==(iterator const & rhs){return (this->_ptr == rhs._ptr);}
			bool operator!=(iterator const &rhs){return (this->_ptr != rhs._ptr);}
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
			// return type == iterator or pointer? 
			iterator operator+(int n)
			{
				return (this->_ptr + n);
			}
			iterator operator-(int n)
			{
				return (this->_ptr - n);
			}

			*/
	};

	template <typename _VAL_TYPE>
	class vector_iterator<const _VAL_TYPE *> : public ft::iterator<ft::random_access_iterator_tag, _VAL_TYPE>
	{
	};

	//temp 나중에 삭제 하기
	/*
	template <typename _ITER_TAG, typename _VAL_TYPE>
	std::ostream & operator<<(std::ostream & os, vector_iterator<_ITER_TAG, _VAL_TYPE> const & it)
	{
		os << it._ptr;
		return (os);
	}
*/

}

#endif
