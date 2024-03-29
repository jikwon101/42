/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:55:45 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/13 02:26:56 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int sb)
{
	int i;

	i = 1;
	if (sb < 0)
		return (0);
	else
	{
		while (i < 46341)
		{
			if ((sb / i == i) && (sb % i == 0))
				return (i);
			i++;
		}
	}
	return (0);
}
