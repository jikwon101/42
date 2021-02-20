#include "one.h"

int ft_atoi(char *str)
{
	int	i;
	int nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			nbr = nbr * 10 + str[i] - '0';
		else
			return (-1);
		i++;
	}
	return (nbr);
}

void ft_putnbr(long long nbr)
{
	char base[] = "0123456789";
	char c;
	long long tmp;

	tmp = nbr;
	nbr = (nbr > 0) ? nbr : -nbr;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	tmp < 0 ? write(1, "-", 1) : 0;
	c = base[nbr % 10];
	write(1, &c, 1);
	return ;
}

void ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return ;
}
