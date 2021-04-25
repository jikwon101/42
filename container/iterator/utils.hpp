#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{

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
