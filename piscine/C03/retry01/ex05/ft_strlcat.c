/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:07:34 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/04 12:20:31 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_dest;

	j = 0;
	len_dest = len(dest);
	i = 0;
	if (len_dest > size)
		return (len(src) + size);
	while (i + 1 < size - len_dest)
	{
		dest[i + len_dest] = src[j];
		j++;
		i++;
		if (src[j] == 0)
			break ;
	}
	dest[i + len_dest] = 0;
	return (len(src) + len_dest);
}
