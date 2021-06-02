#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <exception>
#include <memory>
#include "./ft_vector_iterator.hpp"
#include "../utils/function.hpp"
#include "../iterator/reverse_iterator.hpp"
namespace ft
{
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
			pointer	_end_cap;

		public:
			explicit vector(alloc_type const &alloc = alloc_type() );
			explicit vector(size_type n, const value_type & val = value_type(), alloc_type const& alloc = alloc_type());
			vector(vector const & x);
			template <typename InputIt>
			vector(InputIt first, InputIt last, alloc_type const& alloc = alloc_type(), typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type * = NULL);
			vector&			operator= (vector const & x);
			~vector();
			alloc_type	get_allocator() const;
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
			reference				operator[] (size_type n);
			const_reference			operator[] (size_type n) const;
			reference				at(size_type n);
			const_reference			at(size_type n) const;
			reference				front();
			const_reference			front() const;
			reference				back();
			const_reference			back() const;
			size_type		size() const;
			size_type		capacity() const;
			size_type		max_size() const;
			bool			empty() const;
			void			reserve(size_type n);
			void			resize(size_type n, value_type val = value_type());
			
			void			push_back(value_type const & val);
			void			pop_back(void);
			iterator		erase(iterator position);
			iterator		erase(iterator first, iterator last);
			void			clear();
			void			swap(vector &x);
			iterator		insert(iterator position, const value_type& val);
			void			insert(iterator position, size_type n, const value_type& val);
			template <typename InputIt>
			void			insert(iterator position, InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type* = NULL);
			void			assign(size_type n, value_type const& val);
			template <typename InputIt>
			void			assign(InputIt first, InputIt last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type * = NULL);

		private:
			void	destruct_by(pointer _new_end);
			void	destruct_range(pointer _start, pointer _last);
			void	destruct_at(pointer _pos);
			void	construct_one_at_end(const_reference rhs);
			void	construct_at_end(size_type n, const_reference rhs);
			template <typename InputIt>
			void	construct_at_end(InputIt _first, InputIt _last, typename ft::is_iterator<!ft::is_arithmetic<InputIt>::value, InputIt>::type * = NULL);
			void	append(size_type n, const_reference rhs);	
			void	vector_allocate(size_type n);
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
	#include "./src/ft_vector2.ipp"
	#include "./src/ft_vector3.ipp"


}
#endif
