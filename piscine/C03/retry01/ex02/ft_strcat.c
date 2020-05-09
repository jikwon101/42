/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 23:48:48 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/04 12:19:35 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len_dest;
	int	len_src;

	len_dest = 0;
	len_src = 0;
	while (dest[len_dest] != 0)
		len_dest++;
	while (src[len_src] != 0)
		len_src++;
	i = 0;
	while (i < len_src)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = 0;
	return (dest);
}
