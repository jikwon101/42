#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include <exception>
#include "./iterator.hpp"
#include "./iter_category.hpp"

namespace ft
{
	template <typename _VAL_TYPE>
	class vector_iterator {};
	
	template <typename _VAL_TYPE>
	class vector_iterator<_VAL_TYPE *> : public ft::iterator<ft::random_access_iterator_tag, _VAL_TYPE>
	{
		private:
			_VAL_TYPE* _ptr;

		public:
			vector_iterator() : _ptr(0) { }
			~vector_iterator(){}
			vector_iterator(_VAL_TYPE *const src) { _ptr = src; }
			vector_iterator(vector_iterator const& rhs) { _ptr = rhs._ptr; }
			_VAL_TYPE& operator*() { return (*_ptr); }
		
			vector_iterator& operator=(vector_iterator const& rhs)
			{
				this->_ptr = rhs._ptr; 
				return (*this);
			}

			//temp
			vector_iterator& operator++(){++_ptr; return (*this);}
			vector_iterator operator++(int){vector_iterator ret = *this; ++ret; return (*this);}
			vector_iterator& operator--(){--_ptr; return (*this);};
			vector_iterator operator--(int){vector_iterator ret = *this; --ret; return (*this);}
	
			_VAL_TYPE* operator->()	{ return (_ptr); }
			bool operator==(vector_iterator const & rhs){return (this->_ptr == rhs._ptr);}
			bool operator!=(vector_iterator const &rhs){return (this->_ptr != rhs._ptr);}
			vector_iterator& operator+=(int n) 
			{
				this->_ptr += n;
				return (*this);
			}
			vector_iterator& operator-=(int n)
			{
				this->_ptr -= n;
				return (*this);
			}
			_VAL_TYPE& operator[](int n) { return (*(_ptr += n)); }

			bool operator>(vector_iterator const& other) const {
				return (this->_ptr > other._ptr); }
			bool operator<(vector_iterator const& other) const {
				return (this->_ptr < other._ptr); }
			bool operator<=(vector_iterator const& other) const {
				return (this->_ptr <= other._ptr); }
			bool operator>=(vector_iterator const& other) const {
				return (this->_ptr >= other._ptr); }
			vector_iterator operator+(int n) { 
				return (this->_ptr + n); }
			vector_iterator operator-(int n) {
				return (this->_ptr - n); }

	};

	template <typename _VAL_TYPE>
	class vector_iterator<const _VAL_TYPE *> : public ft::iterator<ft::random_access_iterator_tag, _VAL_TYPE>
	{	
		private:
			_VAL_TYPE* _ptr;
		public:
			vector_iterator() : _ptr(0) { }
			~vector_iterator(){}
			vector_iterator(_VAL_TYPE *const src) { _ptr = src; }
			vector_iterator(vector_iterator const& rhs) { _ptr = rhs._ptr; }
			vector_iterator(vector_iterator<_VAL_TYPE *> const& rhs) 
			{
				//std::cout << *rhs << std::endl;
				_ptr = 0;
				//_ptr = &(*rhs); 
			}
			
			const _VAL_TYPE& operator*() { return (*_ptr); }
		
			vector_iterator& operator=(vector_iterator const& rhs)
			{
				this->_ptr = rhs._ptr; 
				return (*this);
			}
			vector_iterator& operator=(vector_iterator<_VAL_TYPE *> const& rhs)
			{
				//this->_ptr = rhs._ptr;
				return (*this);
			}

			//temp
			vector_iterator& operator++(){++_ptr; return (*this);}
			vector_iterator operator++(int){vector_iterator ret = *this; ++ret; return (*this);}
			vector_iterator& operator--(){--_ptr; return (*this);};
			vector_iterator operator--(int){vector_iterator ret = *this; --ret; return (*this);}
	
			const _VAL_TYPE* operator->()	{ return (_ptr); }
			bool operator==(vector_iterator const & rhs){return (this->_ptr == rhs._ptr);}
			bool operator==(vector_iterator<_VAL_TYPE *> const & rhs){return (this->_ptr == rhs._ptr);}
			bool operator!=(vector_iterator const &rhs){return (this->_ptr != rhs._ptr);}
			bool operator!=(vector_iterator<_VAL_TYPE *> const &rhs){return (this->_ptr != rhs._ptr);}
			vector_iterator& operator+=(int n) 
			{
				this->_ptr += n;
				return (*this);
			}
			vector_iterator& operator-=(int n)
			{
				this->_ptr -= n;
				return (*this);
			}
			const _VAL_TYPE& operator[](int n) { return (*(_ptr += n)); }

			bool operator>(vector_iterator const& other) const {
				return (this->_ptr > other._ptr); }
			bool operator<(vector_iterator const& other) const {
				return (this->_ptr < other._ptr); }
			bool operator<=(vector_iterator const& other) const {
				return (this->_ptr <= other._ptr); }
			bool operator>=(vector_iterator const& other) const {
				return (this->_ptr >= other._ptr); }
			vector_iterator operator+(int n) { 
				return (this->_ptr + n); }
			vector_iterator operator-(int n) {
				return (this->_ptr - n); }

	};

	//temp 나중에 삭제 하기
	/*template <typename _VAL_TYPE>
	std::ostream & operator<<(std::ostream & os, vector_iterator<_VAL_TYPE> const & it)
	{
		os << it._ptr;
		return (os);
	}
	*/
}

#endif
