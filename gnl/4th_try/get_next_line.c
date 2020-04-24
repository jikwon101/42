/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 18:04:13 by jikwon            #+#    #+#             */
/*   Updated: 2020/04/24 21:03:00 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	to_line(char **line, char *w_nl, char **buff, char *temp_buff)
{
	char	*temp;

	if (temp_buff != NULL)
		free(temp_buff);
	if (w_nl != NULL)
	{
		*line = ft_strdup(*buff, (w_nl - *buff));
		temp = ft_strdup(w_nl + 1, ft_strlen(w_nl + 1));
		free(*buff);
		*buff = temp;
		return (1);
	}
	if (*buff != NULL)
	{
		*line = *buff;
		*buff = NULL;
	}
	else
		*line = ft_strdup("", 1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buff;
	int			res;
	char		*w_nl;
	char		*temp2;
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((temp = (char *)malloc(BUFFER_SIZE + 1)) == 0)
		return (-1);
	while ((w_nl = ft_strchr(buff, '\n')) == 0
			&& (res = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[res] = '\0';
		temp2 = (buff == NULL) ? ft_strdup(temp, res) : ft_strjoin(buff, temp);
		if (buff != NULL)
			free(buff);
		buff = temp2;
	}
	if (res < 0)
	{
		free(temp);
		return (-1);
	}
	return (to_line(line, w_nl, &buff, temp));
}
