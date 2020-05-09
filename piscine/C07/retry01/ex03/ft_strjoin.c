/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 03:22:27 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/13 08:54:54 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_len_strs(char **strs, int size)
{
	int	i;
	int	total_len;
	int	len;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		len = ft_len(strs[i]);
		total_len += len;
		i++;
	}
	return (total_len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len_dest;
	int	len_src;

	len_dest = ft_len(dest);
	len_src = ft_len(src);
	i = 0;
	while (i < len_src)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total;
	int		i;

	if (size == 0)
	{
		if ((result = (char *)malloc(sizeof(char) * 1)) == 0)
			return (0);
		*result = 0;
		return (result);
	}
	total = ft_len_strs(strs, size) + (ft_len(sep) * (size - 1)) + 1;
	if ((result = (char *)malloc(sizeof(char) * total)) == 0)
		return (0);
	*result = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i != (size - 1))
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
