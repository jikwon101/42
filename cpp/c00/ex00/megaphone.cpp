#include <iostream>

int		is_lower(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

char	*case_converter(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_lower(str[i]))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int		main(int ac, char **av)
{
	int	i;
	
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (ac > 1)
	{
		for (i = 1; av[i]; i++)
		{
			std::cout << case_converter(av[i]);
		}
	}
	std::cout << std::endl;
	return (0);
}
