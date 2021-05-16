#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <typename T1, typename T2>
	struct Pair
	{
		typedef T1 first_type;
		typedef T2 second_type;
		T1	first;
		T2	second;
		Pair();
		Pair(T1 const& v1, T2 const& v2);
		template <typename U1, typename U2>
		Pair(U1 const& v1, U2 const& u2);
		template <typename U1, typename U2>
		Pair(Pair<U1, U2> const& rhs);
		Pair& operator=(Pair const& rhs);
		~Pair();
	};
	#include "pair.ipp"
	

}
#endif
