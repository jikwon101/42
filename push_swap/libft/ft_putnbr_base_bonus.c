/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:19:18 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/24 02:16:58 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt(long nbr, char *base_to)
{
	int	cnt;
	int	base_size;

	cnt = 0;
	base_size = ft_strlen(base_to);
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base_size;
		cnt++;
	}
	return (cnt);
}

static void	init_sign(int *sign, long nbr)
{
	if (nbr < 0)
		*sign = -1;
	else
		*sign = 1;
}

char	*putnbr_base(long nbr, char *base_to)
{
	int		cnt;
	char	*result;
	int		sign;

	cnt = 0;
	init_sign(&sign, nbr);
	if (nbr < 0)
		nbr = -nbr;
	cnt = ft_cnt(nbr, base_to);
	if (sign == -1)
		cnt += 1;
	result = (char *)malloc(cnt + 1);
	if (!result)
		return (0);
	result[cnt] = '\0';
	while (--cnt >= 0)
	{
		result[cnt] = base_to[nbr % ft_strlen(base_to)];
		nbr = nbr / ft_strlen(base_to);
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
