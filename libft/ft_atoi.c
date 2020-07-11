/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:21:47 by jikwon            #+#    #+#             */
/*   Updated: 2020/06/25 16:05:47 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == ' '
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

static	int	w_sign(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (is_space(str[i]) == 1)
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
	}
	return (sign);
}

int			ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	num;

	i = 0;
	num = 0;
	sign = w_sign(nptr);
	while (is_space(nptr[i]) == 1)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	num = sign * num;
	return (num);
}
