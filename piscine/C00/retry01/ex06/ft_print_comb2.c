/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 20:48:09 by jikwon            #+#    #+#             */
/*   Updated: 2020/01/26 14:43:05 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		i_to_a(int num)
{
	int	m;
	int	n;

	m = (num / 10) + 48;
	n = (num % 10) + 48;
	write(1, &m, 1);
	write(1, &n, 1);
	return (0);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			i_to_a(i);
			write(1, " ", 1);
			i_to_a(j);
			if (i == 98 && j == 99)
				break ;
			write(1, ",", 1);
			write(1, " ", 1);
			j++;
		}
		i++;
	}
}
