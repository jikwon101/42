/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:20:21 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/13 22:36:06 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check(char input, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (input == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		len;

	len = 0;
	while (src[len])
		len++;
	i = 0;
	new = (char *)malloc(len + 1);
	if (new == '\0')
		return (NULL);
	while (i < len)
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*mk_set(char *str, char *sep)
{
	int		i;
	char	*set;
	int		len;

	len = 0;
	while (str[len])
		len++;
	i = 0;
	if ((set = (char *)malloc(len + 1)) == 0)
		return (0);
	while (str[i])
	{
		if (sep == 0)
			set[i] = '0';
		else if (sep != 0)
			set[i] = (check(str[i], sep) == 1) ? '1' : '0';
		i++;
	}
	set[i] = '\0';
	return (set);
}

int		cnt(char *str, char *sep)
{
	int		i;
	char	*set;
	int		count;
	int		len;

	len = 0;
	while (str[len])
		len++;
	set = mk_set(str, sep);
	i = 0;
	count = 0;
	while (i < len - 1)
	{
		if ((set[i] == '1') && (set[i + 1] == '0'))
			count++;
		i++;
	}
	count = (set[0] == '0') ? count + 1 : count;
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	*new;
	char	*set;
	char	**result;
	int		i;
	int		j;

	new = ft_strdup(str);
	set = mk_set(str, charset);
	if (!(result = (char **)malloc(sizeof(char *) * (cnt(str, charset) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (set[i] == '1')
			i++;
		result[j++] = new + i;
		while (set[i] != '1' && str[i] != '\0')
			i++;
		new[i] = '\0';
		if (str[i] != '\0')
			i++;
	}
	result[cnt(str, charset)] = NULL;
	return (result);
}


#include <stdio.h>
int main(void)
{
	char *s1 = "asdfqwer";
	char *s2 = "asdfqwer";
	char **split;

	split =	ft_split(s1, s2);

	for(int i = 0; i < 1; i++)
		printf("%s\n", split[i]);
}
