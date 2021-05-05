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

			/*
			T& first()
			{
				return (_m1);
			}
			const T& first() const
			{
				return (_m1);
			}
			U& second()
			{
				return (_m2);
			}
			const  U& second() const
			{
				return (_m2);
			}
			Pair(){}
			Pair(T v1, U v2)
			{
				this->_m1 = v1;
				this->_m2 = v2;
			}
			Pair(Pair const& rhs)
			{
				this->_m1 = rhs._m1;
				this->_m2 = rhs._m2;
			}
			Pair& operator=(Pair const& rhs)
			{
				if (this != &rhs)
				{
					this->_m1 = rhs._m1;
					this->_m2 = rhs._m2;
				}
				return (*this);
			}	
			~Pair(){}
			*/
	};
	#include "pair.ipp"

}
#endif
