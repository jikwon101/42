#include "Data.hpp"

void*	serialize(void)
{
	int			i;
	char 		*result = new char[20];
	static std::string	alphanumeric = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static const size_t	length = alphanumeric.length();
	
	for (i = 0 ; i < 8 ; i++)
	{
		result[i] = alphanumeric[rand() % length];
	}
	*(reinterpret_cast<int *>(result + 8)) = rand() % 2021;
	for (i = 8 + 4 ; i < 20 ; i++)
	{
		result[i] = alphanumeric[rand() % length];
	}
	return (result);
}

Data*	deserialize(void *raw)
{
	Data	*ptr = new Data;
	char	*temp_raw;
	int		*temp_int;

	if (!raw)
		return (0);
	temp_raw = reinterpret_cast<char *>(raw);
	for (int i = 0; i < 8 ; i++)
	{
		ptr->s1 += temp_raw[i];
	}
	temp_int = reinterpret_cast<int *>(temp_raw + 8);
	ptr->n = *temp_int;
	for (int i = 0 ; i < 8 ; i++)
	{
		ptr->s2 += temp_raw[i + 8 + 4];
	}
	return (ptr);
}
