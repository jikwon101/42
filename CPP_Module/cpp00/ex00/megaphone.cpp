#include <iostream>
#include <cctype>

int		main(int ac, char **av)
{
	int	i;
	
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (ac > 1)
	{
		for (i = 1; av[i]; i++)
		{
			for (int j = 0 ; av[i][j]; j++)
			{
				std::cout << static_cast<char>(toupper((av[i][j])));
			}
		}
	}
	std::cout << std::endl;
	return (0);
}