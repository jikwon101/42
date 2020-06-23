/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:23:51 by jikwon            #+#    #+#             */
/*   Updated: 2020/04/12 21:26:03 by jikwon           ###   ########.fr       */
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
	sign = (num >= 0) ? 1 : -1;
	num = (num >= 0) ? num : -num;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	count = (sign >= 0) ? count : count + 1;
	count = (n == 0) ? 1 : count;
	return (count);
}

char		*ft_itoa(int n)
{
	int			sign;
	long		num;
	char		letter;
	int			count;
	char		*result;

	num = (long)n;
	sign = (num >= 0) ? 1 : -1;
	count = ft_count(n);
	if ((result = (char *)malloc(sizeof(char) * (count + 1))) == 0)
		return (0);
	result[count] = '\0';
	num = (num >= 0) ? num : -num;
	result[0] = '0';
	while (count > 0)
	{
		count--;
		letter = num % 10 + '0';
		result[count] = letter;
		num /= 10;
	}
	if (sign < 0)
		result[0] = '-';
	return (result);
}
