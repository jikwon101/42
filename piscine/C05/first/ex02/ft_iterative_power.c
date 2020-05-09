/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:22:09 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/13 02:39:02 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	i = power;
	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
	{
		while (i != 0)
		{
			result = result * nb;
			i--;
		}
	}
	return (result);
}
