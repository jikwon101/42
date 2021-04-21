#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <exception>
#include "./iterator.hpp"
#include "./iter_category.hpp"

namespace ft
{

	template <typename _ITER_TAG, typename _VAL_TYPE>
	class vector_iterator : public ft::iterator<_ITER_TAG, _VAL_TYPE>
	{
		private:
			typedef vector_iterator<_ITER_TAG, _VAL_TYPE> iterator;
		public:
			typedef typename ft::iterator<_ITER_TAG, _VAL_TYPE>::value_type value_type;
			typedef typename ft::iterator<_ITER_TAG, _VAL_TYPE>::pointer pointer;
			typedef typename ft::iterator<_ITER_TAG, _VAL_TYPE>::reference reference;
		
			value_type * _ptr;				//temp;
			vector_iterator() : _ptr(0) { }
			~vector_iterator(){}
			vector_iterator(reference src)
			{
				_ptr = &src;
			}
			vector_iterator(pointer src)
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
			
			iterator& operator++(){++_ptr; return (*this);}
			iterator operator++(int){iterator ret = *this; ++ret; return (*this);};
			iterator& operator--(){--_ptr; return (*this);};
			iterator operator--(int){iterator ret = *this; --ret; return (*this);};
	
			//operator->;
			bool operator==(iterator const & rhs){return (this->_ptr == rhs._ptr);};
			bool operator!=(iterator const &rhs){return (this->_ptr != rhs._ptr);};
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
	//		operator>;
	//		operator<;
	//		operator<=;
	//		operator>=;
			pointer operator+(int n)
			{
				return (this->_ptr + n);
			}
			pointer operator-(int n)
			{
				return (this->_ptr - n);
			}
	};

	//temp 나중에 삭제 하기
	template <typename _ITER_TAG, typename _VAL_TYPE>
	std::ostream & operator<<(std::ostream & os, vector_iterator<_ITER_TAG, _VAL_TYPE> const & it)
	{
		os << it._ptr;
		return (os);
	}


}

#endif
