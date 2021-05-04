#ifndef VECTOR_HPP
# define VECTOR_HPP

//#include <cstddef>
#include <cmath>
#include <iostream>
#include <exception>
#include <memory>
#include "../iterator/vector_iterator.hpp"
#include "../iterator/function.hpp"
#include "../iterator/reverse_iterator.hpp"

namespace ft
{
	template <typename T, typename U>
	class Pair
	{
	private:
		Pair(){}
	public:
		T pointer;
		U alloc;
		T& first()
		{
			return (pointer);
		}
		const T& first() const
		{
			return (pointer);
		}
		U& second()
		{
			return (alloc);
		}
		const  U& second() const
		{
			return (alloc);
		}
		Pair(T ptr, U alloc)
		{
			this->pointer = ptr;
			this->alloc = alloc;
		}
		~Pair(){}
	};

	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T												value_type;
			typedef Alloc											alloc_type;
			typedef std::allocator_traits<alloc_type>				alloc_traits;
			typedef typename alloc_traits::size_type				size_type;
			typedef typename alloc_traits::difference_type			difference_type;
			typedef typename alloc_traits::pointer					pointer;
			typedef typename alloc_traits::const_pointer			const_pointer;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef typename ft::vector_iterator<pointer>			iterator;
			typedef typename ft::vector_iterator<const_pointer> 	const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		private:
			pointer _begin;
			pointer _end;
			Pair<pointer, alloc_type> _end_cap;

		public:
			/* 
			** Constructor & Destuctor
			*/
			explicit vector(alloc_type const &alloc = alloc_type() );
			explicit vector(size_type n, const value_type & val = value_type(), alloc_type const& alloc = alloc_type());
			template <typename InputIt>
			vector(InputIt first, InputIt last, alloc_type const& alloc = alloc_type(), 
					typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type * = NULL);
			vector(vector const & x);
			vector&			operator= (vector const & x);
			virtual ~vector();
			/* 
			** Allocator
			*/
			alloc_type	get_allocator() const;
			/*
			** Iterator
			*/
			iterator				begin();
			const_iterator			begin() const;
			const_iterator			cbegin() const throw();
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			iterator				end();
			const_iterator			end() const;
			const_iterator			cend() const throw();
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

			/*
			** Element access
			*/
			reference				operator[] (size_type n);
			const_reference			operator[] (size_type n) const;
			reference				at(size_type n);
			const_reference			at(size_type n) const;
			reference				front();
			const_reference			front() const;
			reference				back();
			const_reference			back() const;

			/*
			** Capacity
			*/
			size_type		size() const;
			size_type		capacity() const;
			size_type		max_size() const;
			bool			empty() const;
			void			reserve(size_type n);
			void			resize(size_type n, value_type val = value_type());
			
			/*
			** Modifier
			*/
			void			push_back(value_type const & val);
			void			pop_back(void);
			iterator		erase(iterator position);
			iterator		erase(iterator first, iterator last);
			void			clear();
			void			swap(vector &x);
			iterator		insert(iterator position, const value_type& val);
			void			insert(iterator position, size_type n, const value_type& val);
			template <typename InputIt>
			void			insert(iterator position, InputIt first, InputIt last, 
									typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type* = NULL);
			void			assign(size_type n, value_type const& val);
			template <typename InputIt>
			void			assign(InputIt first, InputIt last, 
									typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type * = NULL);

		private:
			alloc_type& alloc();
			const alloc_type& alloc() const;
			pointer& end_cap();
			const pointer& end_cap() const;

			void destruct_by(pointer _new_end);
			/*
			{
				pointer _pos(_end);
				for (--_pos; _pos != _new_end; --_pos)
				{
					alloc().destroy(_pos);
				}
				_end = _new_end;
				return ;
			}*/
			void destruct_range(pointer _start, pointer _last);
			/*
			{
				for (; _start != _last ; ++_start)
					alloc().destroy(_start);
			}*/
			void	construct_at_end(size_type n, const_reference rhs);
			/*
			{
				pointer new_end;

				new_end = _end + n;
				for (; _end != new_end ; ++_end)
					alloc().construct(_end, rhs);
				_end = new_end;
			}*/
			void	construct_at_end(size_type n);
			/*
			{
				pointer new_end;

				new_end = _end + n;
				for (; _end != new_end ; ++_end)
					alloc().construct(_end, value_type());
				_end = new_end;

			}*/
			void append(size_type n);
			void append(size_type n, const_reference rhs);
		

	};
	template <typename T, typename Alloc>
	void	swap(vector<T, Alloc> &x, vector<T, Alloc> &y);
	template <typename T, typename Alloc>
	bool	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
	template <typename T, typename Alloc>
	bool	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
	template <typename T, typename Alloc>
	bool	operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
	template <typename T, typename Alloc>
	bool	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
	template <typename T, typename Alloc>
	bool	operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
	template <typename T, typename Alloc>
	bool	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
	#include "vector2.hpp"
	#include "vector3.ipp"


}
#endif
