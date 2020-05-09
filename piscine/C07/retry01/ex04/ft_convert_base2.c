/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:29:09 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/13 08:55:40 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_space(char str);
int		w_len(char *str);
int		check_base(char *base);
int		w_sign(char *str);

int		find_index(char *base, char to_find)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

int		w_count(long nbr, char *base_to)
{
	int	count;
	int	base_size;

	count = 0;
	base_size = w_len(base_to);
	while ((nbr / base_size) != 0)
	{
		nbr /= base_size;
		count++;
	}
	return (count);
}

char	*putnbr_base(long nbr, char *base_to)
{
	int		count;
	char	*result;
	long	start;

	count = 0;
	start = nbr;
	nbr = (nbr >= 0) ? nbr : ((-1) * nbr);
	count = w_count(nbr, base_to);
	count = (start >= 0) ? (count + 1) : (count + 2);
	if ((result = (char *)malloc(sizeof(char) * count)) == 0)
		return (0);
	result[count] = 0;
	while (--count >= 0)
	{
		result[count] = base_to[nbr % w_len(base_to)];
		nbr = nbr / w_len(base_to);
	}
	if (start < 0)
		result[0] = '-';
	return (result);
}

int		ft_atoi_base(char *str, char *base_from)
{
	int	i;
	int	nbr;

	nbr = 0;
	i = 0;
	while (is_space(str[i]) == 1)
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (str[i])
	{
		if (find_index(base_from, str[i]) == -1)
			return (w_sign(str) * nbr);
		nbr = nbr * w_len(base_from) + find_index(base_from, str[i]);
		i++;
	}
	nbr = w_sign(str) * nbr;
	return (nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		mid_result;
	char	*result;

	if ((check_base(base_from) != 1) || (check_base(base_to) != 1))
		return (0);
	mid_result = ft_atoi_base(nbr, base_from);
	result = putnbr_base(mid_result, base_to);
	return (result);
}
