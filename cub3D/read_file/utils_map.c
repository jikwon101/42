/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 01:47:36 by jikwon            #+#    #+#             */
/*   Updated: 2020/07/31 11:57:57 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

int		ft_is_map(char *line)
{
	char	*trim;

	if (line == NULL)
		return (0);
	trim = ft_strtrim(line, " 012WESN");
	if (!ft_strcmp(trim, ""))
	{
		free(trim);
		return (1);
	}
	free(trim);
	return (0);
}

void	ft_temp_map(char **doc, char *line)
{
	char	*temp;

	temp = (*doc == NULL) ? ft_strdup("") : ft_strjoin(*doc, "\n");
	if (*doc != NULL)
		free(*doc);
	*doc = ft_strjoin(temp, line);
	free(temp);
	return ;
}

int		ft_lenx(char **t_map)
{
	int	cnt;

	cnt = 0;
	while (t_map[cnt])
		cnt++;
	return (cnt);
}

int		ft_check_sp(char *doc)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (doc[i])
	{
		if (doc[i] == '2')
			cnt++;
		i++;
	}
	return (cnt);
}
