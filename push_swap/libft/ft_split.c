/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 20:18:42 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/24 02:00:26 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_tot_cnt(char *str, char c)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 1;
	while (str[i])
	{
		while (str[i] != '\0' && str[i] != c)
			i++;
		if (str[i] != '\0' && str[i] == c)
			cnt++;
		while (str[i] != '\0' && str[i] == c)
			i++;
	}
	if (str[0] == '\0')
		cnt = 0;
	return (cnt);
}

static	int	ft_fill(char *str, char **result, char c, int tot)
{
	int	k;
	int	cnt;

	k = 0;
	while (k < tot)
	{
		cnt = 0;
		while ((*str != '\0') && *str != c)
		{
			cnt++;
			str++;
		}
		result[k] = (char *)malloc(cnt + 1);
		if (!result[k])
			return (k);
		ft_memcpy(result[k], (str - cnt), cnt);
		result[k++][cnt] = '\0';
		while ((*str != '\0') && *str == c)
			str++;
	}
	return (-1);
}

static	void	ft_free(char **result, char *temp_str, int k)
{
	int	i;

	i = 0;
	free(temp_str);
	while (i < k)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return ;
}

char	**ft_split(const char *s, char c)
{
	int		tot;
	char	**result;
	char	tar[2];
	char	*temp_str;
	int		k;

	tar[0] = c;
	tar[1] = '\0';
	temp_str = ft_strtrim(s, tar);
	if (s == NULL)
		return (NULL);
	tot = ft_tot_cnt(temp_str, c);
	result = (char **)malloc(sizeof(char *) * (tot + 1));
	if (!result)
		return (0);
	result[tot] = 0;
	k = ft_fill(temp_str, result, c, tot);
	if (k > -1)
	{
		ft_free(result, temp_str, k);
		return (0);
	}
	free(temp_str);
	return (result);
}
