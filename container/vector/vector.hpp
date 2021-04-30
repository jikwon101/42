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
		public:
			typedef T												value_type;
			typedef std::allocator<value_type>						allocator_type;
			typedef size_t 											size_type;
			typedef ptrdiff_t										difference_type;
			typedef value_type* 									pointer;
			typedef const value_type*								const_pointer;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef typename ft::vector_iterator<pointer>			iterator;
			typedef typename ft::vector_iterator<const_pointer> 	const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		
		private:
			T *_arr;
			size_t _size;
			size_t _capacity;

		public:
			/* 
			** Constructor & Destuctor
			*/
			explicit vector(allocator_type const &alloc = allocator_type() );
			explicit vector(size_type n, const value_type & val = value_type(), allocator_type const& alloc = allocator_type());
			template <typename InputIt>
			vector(InputIt first, InputIt last, allocator_type const& alloc = allocator_type(), 
					typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type * = NULL);
			vector(vector const & x);
			vector&			operator= (vector const & x);
			~vector();

			/*
			** Allocator
			*/
			allocator_type	get_allocator() const;
	
			/*
			** iterator
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

	};

	template <typename T, typename Alloc>
	void	swap(vector<T, Alloc> &x, vector<T, Alloc> &y);
#include "vector2.hpp"

}
#endif
