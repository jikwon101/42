#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cstddef>
#include <iostream>
#include <exception>
#include <cmath>
#include <memory>
#include "../iterator/iterator.hpp"
#include "../iterator/iter_category.hpp"
#include "../iterator/random_access_iterator.hpp"

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
			typedef std::allocator<value_type>		alloc_type;
			typedef size_t 							size_type;
			typedef ptrdiff_t						difference_type;
			typedef value_type* 					pointer;
			typedef const value_type*				const_pointer;
			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef typename ft::random_access_iterator_tag					iterator_type;
			typedef typename ft::vector_iterator<iterator_type, value_type> iterator;
			

			explicit vector(alloc_type const &alloc = alloc_type() )
			{
				std::cout << "default\n";
			}

			explicit vector(size_type n, value_type const& val = value_type(), alloc_type const& alloc = alloc_type()) 
			{
					std::cout << "size\n";
					_size = n;
					_capacity = n;
					_arr = new value_type[n];
			}
			
			template <typename InputIt>
			vector (InputIt f, InputIt l, alloc_type const& alloc=alloc_type(), typename is_iterator<InputIt, iterator_type>::type* = NULL)
			{
				std::cout << "iterator\n";
			}

			vector(vector const & x){std::cout << "copy\n";}

			vector& operator= (vector const & x) {std::cout << "=\n";}

			~vector() throw() 	{/*delete[] _arr;*/}
			iterator begin()
			{
				return (_arr[0]);
			}
			iterator end()
			{
				return (_arr[_size]);
			}
	
	};
}
#endif


//vector (InputIt first, InputIt last, alloc_type const & alloc = alloc_type(), typename ft::enable_if<ft::is_iterator<InputIt, typename ft::iterator_traits<InputIt>::value_type>::value, typename ft::iterator_traits<InputIt>::value_type>::type = typename ft::iterator_traits<InputIt>::value_type())

//typename ft::enable_if<ft::is_iterator<InputIt, typename ft::iterator_traits<InputIt>::value_type>::value, typename ft::iterator_traits<InputIt>::value_type>::type = typename ft::iterator_traits<InputIt>::value_type())
