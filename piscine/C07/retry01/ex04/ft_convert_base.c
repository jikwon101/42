/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:28:52 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/13 08:55:10 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_space(char str)
{
	if ((str == '\n') || (str == '\t') || (str == '\r')
		|| (str == '\v') || (str == '\f') | (str == ' '))
		return (1);
	return (0);
}

int	w_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	w_sign(char *str)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while (is_space(str[i]) == 1)
		i++;
	while (str[i] != 0)
	{
		if ((str[i] == '-') || (str[i] == '+'))
		{
			if (str[i] == '-')
				sign = sign * (-1);
		}
		else
			return (sign);
		i++;
	}
	return (sign);
}

int	check_base(char *base)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	if (w_len(base) <= 1)
		return (0);
	while (base[i] != 0)
	{
		j = i + 1;
		temp = base[i];
		if ((base[i] == '+') || (base[i] == '-') || (is_space(base[i]) == 1))
			return (0);
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
