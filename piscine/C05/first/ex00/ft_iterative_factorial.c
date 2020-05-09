/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:21:36 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/13 09:22:31 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int num;

	num = nb;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	while (nb > 1)
	{
		num = num * (nb - 1);
		nb--;
	}
	return (num);
}
