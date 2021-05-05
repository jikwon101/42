#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
	/*
   Empty class to identify the category of an iterator
	*/
	struct input_iterator_tag {};

	struct output_iterator_tag {};

	struct forward_iterator_tag : public input_iterator_tag {};

	struct bidirectional_iterator_tag : public forward_iterator_tag {};

	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	/*
	** Base class
	*/
	template <typename Category, typename T, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T& >
	struct iterator
	{
		typedef T			value_type;
		typedef Category	iterator_category;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};

	// 컴파일 도중에 주어진 타입의 정보를 얻을 수 있게 하는 객체
	template <typename Iterator>
	struct iterator_traits	
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <typename T>
	struct iterator_traits<T *>
	{
		typedef ptrdiff_t 						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};
	
	template <typename T>
	struct iterator_traits<const T *>
	{
		typedef ptrdiff_t 						difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};


}

#endif
