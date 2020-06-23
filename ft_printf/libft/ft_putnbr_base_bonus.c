/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 11:36:24 by jikwon            #+#    #+#             */
/*   Updated: 2020/05/09 14:48:50 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

int		ft_count(unsigned long int nbr, int base_len)
{
	int	result;

	result = 0;
	if (nbr == 0)
		result = 1;
	while (nbr != 0)
	{
		result++;
		nbr = nbr / base_len;
	}
	return (result);
}

char	*ft_putnbr_base(unsigned long int nbr, char *base)
{
	int		count;
	char	*result;
	int		temp;

	count = ft_count(nbr, ft_strlen(base));
	if ((result = (char *)malloc(count + 1)) == 0)
		return (0);
	result[count] = '\0';
	while (count > 0)
	{
		temp = nbr % ft_strlen(base);
		result[count - 1] = base[temp];
		nbr = nbr / ft_strlen(base);
		count--;
	}
	return (result);
}
