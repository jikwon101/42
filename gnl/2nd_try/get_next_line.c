/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon </var/mail/jikwon>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 17:21:39 by jikwon            #+#    #+#             */
/*   Updated: 2020/04/16 15:29:18 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"

//delete below
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char *ft_strdup(char *s)
{
	int		len;
	char	*result;
	int		i;

	len = ft_strlen(s);
	if ((result = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}
//i : index to start copy
void	mem_cpy(char *dest, char *src, int *i)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dest[*i] = src[j];
		(*i)++;
		j++;
	}
	return ;
}

void	mv_forward(char **temp_set_fd, int nl_check, int j)
{
	int		i;
	char	*temp;
	
	i = j + 1;
	if (nl_check == 0)
	{
		free(*temp_set_fd);
		*temp_set_fd = NULL;
		return ;
	}
	temp = ft_strdup(*temp_set_fd + j + 1);
	free(*temp_set_fd);
	*temp_set_fd = temp;
	return ;
}

void	ft_cpy_line(char **line, char *src, int count)
{
	int	i;

	i = 0;
	if ((*line = (char *)malloc(count + 1)) == 0)
		return ;
	while (i < count)
	{
		(*line)[i] = src[i];
		i++;
	}
	return ;
}

int 	check_fd_set(char **fd_set_fd, char **line)
{
	int	nl_check;
	int	i;

	i = 0;
	nl_check = 0;
	while ((*fd_set_fd)[i])
	{
		if ((*fd_set_fd)[i] == '\n')
		{
			nl_check = 1;
			break;
		}
		i++;
	}
	ft_cpy_line(line, *fd_set_fd, i);
	mv_forward(fd_set_fd, nl_check, i);
	if (nl_check == 1)
		return (1);
	else
		return (0);
}

void	ft_merge(char **fd_set_fd, char *temp, int res)
{
	int		cnt;
	char	*temp_fd_set;
	int		i;

	i = 0;
	if (!(*fd_set_fd))
	{
		cnt = 0 + res;
		if ((*fd_set_fd = (char *)malloc(cnt + 1)) == 0)
			return ;
		mem_cpy(*fd_set_fd, temp, &i);
	}
	else
	{
		temp_fd_set = ft_strdup(*fd_set_fd);
		free(*fd_set_fd);
		cnt = ft_strlen(temp_fd_set) + res + 1;
		if ((*fd_set_fd = (char *)malloc(cnt + 1)) == 0)
			return ;
		mem_cpy(*fd_set_fd, temp_fd_set, &i);
		mem_cpy(*fd_set_fd, temp, &i);
	}
	return ;
}

int		read_file(int fd, char **fd_set_fd, char *temp)
{
	int	res;

	res = read(fd, temp, BUFFER_SIZE);
	if (res > 0)
	{
		ft_merge(fd_set_fd, temp, res);
		return (1);
	}
	else if (res == 0)
		return (0);
	else
		return (-1);
}


int		get_next_line(int fd, char **line)
{
	static	char	*(fd_set[1024]) = {NULL,};
	int				res;
	char			temp[BUFFER_SIZE + 1];

	printf("fd:%d\n", fd);
	if (fd_set[fd])
	{	
		if (check_fd_set(&fd_set[fd], line))
			return (1);
	}
	while (1)
	{
		if ((res = read_file(fd, &fd_set[fd], temp))== 1)
		{
			if (check_fd_set(&fd_set[fd], line))
				return (1);
		}
		else
			free(fd_set[fd]);
		if (res == 0)
			return (0);
		else if (res == -1)
			return (-1);
	}
}

#include <fcntl.h>

int main()
{
	char *line = 0;
	int ret;
	int i;
	int fd;

	fd = open("text.txt", O_RDONLY);
	i = 1;
	//while ((
				
	ret = get_next_line(fd, &line);
	
	//++i;
	printf("%d|%s|\n", ret, line);
	free(line);
	/*
	printf("%d|%s|\n", ret, line);
	free(line);
	*/
	return (0);
}
