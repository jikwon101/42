/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:27:00 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/04 21:16:07 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		len(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_str_not_null(char *str, char *to_find, int istr, int jfind)
{
	int	count;

	count = 0;
	while (str[istr] != 0)
	{
		if ((str[istr] == to_find[jfind])
				&& (to_find[jfind] != 0))
		{
			istr++;
			jfind++;
			count++;
		}
		else
		{
			istr = istr - count + 1;
			jfind = 0;
			count = 0;
		}
		if (count == len((to_find)))
			return ((str + istr - len(to_find)));
	}
	return ((char*)'\0');
}

char	*ft_strstr(char *str, char *to_find)
{
	int		istr;
	int		jfind;
	int		count;
	char	*result;

	istr = 0;
	jfind = 0;
	count = 0;
	if (to_find[jfind] == 0)
		return (str);
	result = ft_str_not_null(str, to_find, istr, jfind);
	return (result);
}
