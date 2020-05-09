/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:25:05 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/13 09:23:24 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int first;
	int second;
	int result;

	first = 0;
	second = 1;
	if (index < 0)
		return (-1);
	else if (index == 0)
		result = first;
	else if (index == 1)
		result = second;
	else
		result = ft_fibonacci(index - 2) + ft_fibonacci(index - 1);
	return (result);
}
