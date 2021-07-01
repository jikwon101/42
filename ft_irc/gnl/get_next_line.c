/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 18:04:13 by jikwon            #+#    #+#             */
/*   Updated: 2021/06/11 10:38:42 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int	to_line(char **line, char *w_nl, char **fd_set, char *temp_buff)
{
	char	*temp;

	if (temp_buff != NULL)
		free(temp_buff);
	if (w_nl != NULL)
	{
		*line = ft_strdup(*fd_set, (w_nl - *fd_set));
		temp = ft_strdup(w_nl + 1, ft_strlen(w_nl + 1));
		free(*fd_set);
		*fd_set = temp;
		return (1);
	}
	if (*fd_set != NULL)
	{
		*line = *fd_set;
		*fd_set = NULL;
	}
	else
		*line = ft_strdup("", 1);
	return (0);
}

//int	get_next_line(int fd, char **line)
int	get_next_msg(char **buf,  char **line)
{
	char		*w_nl;

	if (!line || !buf || BUFFER_SIZE <= 0)
		return (-1);
	if ((w_nl = ft_strstr(*buf, "\r\n")) == 0)
		return (0);
	int res = (w_nl - *buf);
	*line = (char *)malloc(res);
	if (!*line)
		return (-1);
	memcpy(*line, *buf, res);
	char *temp = (char *)malloc(strlen(*buf) - res);
	memcpy(temp, *buf + res + 2 , strlen(*buf) - res);
	free(*buf);
	*buf = temp;
	temp  = ft_strjoin(*line, "\r\n");
	free(*line);
	*line = temp;
	return (1);
}
