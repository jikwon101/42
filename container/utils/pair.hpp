#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;
		T1	first;
		T2	second;
		pair();
		pair(T1 const& v1, T2 const& v2);
		template <typename U1, typename U2>
		pair(U1 const& v1, U2 const& u2);
		template <typename U1, typename U2>
		pair(pair<U1, U2> const& rhs);
		pair& operator=(pair const& rhs);
		~pair();
	};
	#include "pair.ipp"
	

}
#endif
