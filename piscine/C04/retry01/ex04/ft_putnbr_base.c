/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:36:03 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/05 10:04:10 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	len(char *str)
{
	long	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

void	to_base(long nbr, char *base)
{
	long	size_base;
	long	m;
	long	n;

	size_base = len(base);
	m = nbr / size_base;
	n = nbr % size_base;
	if (m != 0)
		to_base(m, base);
	write(1, &base[n], 1);
	return ;
}

int		check_base(char *base, int i, int j)
{
	int		count;
	char	temp;

	if (len(base) <= 1)
		return (0);
	while (base[i] != 0)
	{
		if ((base[i] == '+') || (base[i] == '-'))
			return (0);
		temp = base[i];
		count = 0;
		j = 0;
		while (j < len(base))
		{
			if ((temp == base[j]) && (j != i))
				count++;
			j++;
		}
		if (count != 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (check_base(base, 0, 0) == 0)
		return ;
	else if (nbr >= 0)
	{
		to_base(nbr, base);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		to_base(-(long)(nbr), base);
	}
	return ;
}
