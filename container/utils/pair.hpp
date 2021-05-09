#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <typename T, typename U>
	class Pair
	{
		private:
			T _m1;
			U _m2;
		public:
			T& first();
			const T& first() const;
			U& second();
			const  U& second() const;
			Pair();
			Pair(T v1, U v2);
			Pair(Pair const& rhs);
			Pair& operator=(Pair const& rhs);
			~Pair();
	};
	#include "pair.ipp"

}
#endif
