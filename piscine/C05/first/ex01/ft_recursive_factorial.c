/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:33:30 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/13 09:22:39 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
	{
		result = nb * ft_recursive_factorial(nb - 1);
		return (result);
	}
}
