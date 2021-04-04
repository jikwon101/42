#include <iostream>

struct Data
{
	std::string s1;
	int			n;
	std::string s2;
};

void* serialize(void)
{
	int			i;
	size_t		length;
	char 		*result = new char[20];
	std::string	alphanumeric = "0123456789";
	alphanumeric += "abcdefghijklmnopqrstuvwxyz";
	alphanumeric += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	length = alphanumeric.length();
	for (i = 0 ; i < 8 ; i++)
	{
		result[i] = 'a';
		result[i] = alphanumeric[rand() % length];
	}
	*(reinterpret_cast<int *>(result + 8)) = rand() % 2021;
	for (i = 8 + 4 ; i < 20 ; i++)
	{
		result[i] = 'c';
		result[i] = alphanumeric[rand() % length];
	}
	return (result);
}

Data* deserialize(void *raw)
{
	Data	*ptr = new Data;
	char	*temp_raw;
	int		*temp_int;

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

int main()
{
	srand(time(NULL));
	Data *res = deserialize(serialize());
	std::cout << res->s1 << std::endl;
	std::cout << res->n << std::endl;
	std::cout << res->s2 << std::endl;
}
