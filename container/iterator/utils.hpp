#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	//enable_if
	template <bool B, typename T = void>
	struct enable_if
	{
	};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	//is_const
	template <typename T>
	struct is_const
	{
		static const bool value = false;
	};

	template <typename T>
	struct is_const<const T>
	{
		static const bool value = true;
	};
	//util
	template <typename T>
	T	max(T a, T b)
	{
		if (a > b)
			return (a);
		return (b);
	}

	//is_arithmetic
	template <typename T>
	struct is_arithmetic
	{
		static const bool value = false;
	};

	template <>
	struct is_arithmetic<bool>
	{
		static const bool value = true;
	};
	
	template <>
	struct is_arithmetic<char>
	{
		static const bool value = true;
	};
	
	template <>
	struct is_arithmetic<signed char>
	{
		static const bool value = true;
	};
	
	template <>
	struct is_arithmetic<unsigned char>
	{
		static const bool value = true;
	};

	template <>
	struct is_arithmetic<wchar_t>
	{
		static const bool value = true;
	};

	template <>
	struct is_arithmetic<short>
	{
		static const bool value = true;
	};

	template <>
	struct is_arithmetic<unsigned short>
	{
		static const bool value = true;
	};

	template <>
	struct is_arithmetic<int>
	{
		static const bool value = true;
	};

	template <>
	struct is_arithmetic<unsigned int>
	{
		static const bool value = true;
	};

	template <>
	struct is_arithmetic<long>
	{
		static const bool value = true;
	};

	template <>
	struct is_arithmetic<unsigned long>
	{
		static const bool value = true;
	};
			
	template <>
	struct is_arithmetic<float>
	{
		static const bool value = true;
	};

	template <>
	struct is_arithmetic<double>
	{
		static const bool value = true;
	};

	template <>
	struct is_arithmetic<long double>
	{
		static const bool value = true;
	};

}
#endif
