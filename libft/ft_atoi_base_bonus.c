/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:04:28 by jikwon            #+#    #+#             */
/*   Updated: 2020/07/08 12:14:57 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int ft_index(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);
}
int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int nbr;
	int sign;

	i = 0;
	nbr =  0;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;		
		i++;
	}
	while (str[i])
	{
		nbr = nbr * ft_strlen(base) + ft_index(base, str[i]);
		i++;
	}
	return (sign * nbr);
}
