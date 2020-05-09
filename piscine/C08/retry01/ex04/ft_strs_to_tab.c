/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:55:09 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/14 04:10:18 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_len(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char					*ft_strdup(char *src)
{
	char	*newstr;
	int		len;
	int		i;

	len = ft_len(src);
	if (!(newstr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		newstr[i] = src[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*result;

	if (!(result = malloc((ac + 1) * sizeof(struct s_stock_str))))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		result[i].size = ft_len(av[i]);
		result[i].str = av[i];
		result[i].copy = ft_strdup(av[i]);
		i++;
	}
	result[i] = (struct s_stock_str){0};
	return (result);
}
