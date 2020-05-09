/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:42:55 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/10 13:17:24 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 != 0 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		main(int argc, char *argv[])
{
	int		i;
	int		gap;

	i = 1;
	while (i < argc - 1)
	{
		gap = ft_strcmp(argv[i], argv[i + 1]);
		if (gap > 0)
		{
			ft_swap(&argv[i], &argv[i + 1]);
			i = 1;
		}
		else
			i++;
	}
	i = 1;
	while (i < argc)
	{
		write(1, argv[i], len(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
