#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <typename T1, typename T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;
		T1	first;
		T2	second;
		pair();
		pair(const first_type& x, const second_type& y);
		template <typename U1, typename U2>
		pair(pair<U1, U2> const& rhs);
		pair& operator=(const pair& rhs);
		~pair();
	};
	template <typename U1, typename U2>
	bool	operator==(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs);
	template <typename U1, typename U2>
	bool	operator!=(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs);
	template <typename U1, typename U2>
	bool	operator<(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs);
	template <typename U1, typename U2>
	bool	operator<=(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs);
	template <typename U1, typename U2>
	bool	operator>(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs);
	template <typename U1, typename U2>
	bool	operator>=(const pair<U1, U2>& lhs, const pair<U1, U2>& rhs);
	#include "pair.ipp"
}
#endif
