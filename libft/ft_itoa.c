/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:23:51 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/24 02:15:52 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count(int n)
{
	long		num;
	int			count;
	int			sign;

	num = (long)n;
	count = 0;
	if (num >= 0)
		sign = 1;
	else
		sign = -1;
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	if (count < 0)
		count += 1;
	if (n == 0)
		count = 1;
	return (count);
}

static void init_sign(int *sign, long num)
{
	if (num >= 0)
		*sign = 1;
	else
		*sign = -1;
}

char	*ft_itoa(int n)
{
	int			sign;
	long		num;
	int			count;
	char		*result;

	num = (long)n;
	init_sign(&sign, num);
	count = ft_count(n);
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (!result)
		return (0);
	result[count] = '\0';
	if (num < 0)
		num = -num;
	result[0] = '0';
	while (count > 0)
	{
		count--;
		result[count] = num % 10 + '0';
		num /= 10;
	}
	if (sign < 0)
		result[0] = '-';
	return (result);
}
