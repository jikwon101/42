/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 18:04:13 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/24 02:29:44 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char *str, int size)
{
	char	*result;

	if (str == NULL)
		return (0);
	result = (char *)malloc(size + 1);
	if (!result)
		return (0);
	result[size] = '\0';
	ft_memcpy(result, str, size);
	return (result);
}

int	to_line(char **line, char *w_nl, char **fd_set, char *temp_buff)
{
	char	*temp;

	if (temp_buff != NULL)
		free(temp_buff);
	if (w_nl != NULL)
	{
		*line = ft_strndup(*fd_set, (w_nl - *fd_set));
		temp = ft_strndup(w_nl + 1, ft_strlen(w_nl + 1));
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
		*line = ft_strndup("", 1);
	return (0);
}

static void	addstr(char **fd_set, int fd, char *buff, int res)
{
	char	*temp;

	if (!fd_set[fd])
		temp = ft_strndup(buff, res);
	else
		temp = ft_strjoin(fd_set[fd], buff);
	if (fd_set[fd] != NULL)
		free(fd_set[fd]);
	fd_set[fd] = temp;
}

int	get_next_line(int fd, char **line)
{
	static char	*fd_set[1024];
	char		*buff;
	int			res;
	char		*w_nl;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	w_nl = ft_strchr(fd_set[fd], '\n');
	res = read(fd, buff, BUFFER_SIZE);
	while (w_nl == 0 && res > 0)
	{
		buff[res] = '\0';
		addstr(fd_set, fd, buff, res);
		w_nl = ft_strchr(fd_set[fd], '\n');
		res = read(fd, buff, BUFFER_SIZE);
	}
	if (res < 0)
	{
		free(buff);
		return (-1);
	}
	return (to_line(line, w_nl, &fd_set[fd], buff));
}
