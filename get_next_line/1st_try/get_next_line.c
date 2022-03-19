/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon </var/mail/jikwon>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 17:21:39 by jikwon            #+#    #+#             */
/*   Updated: 2020/04/15 18:33:27 by jikwon           ###   ########.fr       */
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

int		prep_cpy(char *temp_set_fd, char **line, unsigned int  size)
{
	char	*temp;
	int		i;

	i = 0;
	if (!(*line))
	{
		printf("HERE !!!\n");
		if ((*line = (char *)malloc(0 + size + 1)) == 0)
			return (-1);
		mem_cpy(*line, temp_set_fd, &i);
	}
	else
	{
		printf("HERE Yes\n");
		temp = ft_strdup(*line);
		free(*line);
		if ((*line = (char *)malloc(ft_strlen(temp) + size + 1)) == 0)
			return (-1);
		mem_cpy(*line, temp_set_fd, &i);
		mem_cpy(*line, temp_set_fd, &i);
	}
	return (0);
}

void	mv_forward(char *temp_set_fd, int i)
{
	int		j;
	int		len;
	char	temp;

	j = 0;
	len = ft_strlen(temp_set_fd);
	while (j < len)
	{
		temp = temp_set_fd[i];
		temp_set_fd[j] = temp;
		i++;
		j++;
	}
	while (j < len)
	{
		temp_set_fd[j] = '\0';
		j++;
	}
	return ;
}

//ifthere is \n in temp_Set return 1, otherwise return 0
int		check_tempset(char *temp_set_fd, char **line)
{
	unsigned int	i;
	int				nl_check;

	if (temp_set_fd[0] == '\0')
		return (0);
	i = 0;
	nl_check = 0;
	while (temp_set_fd[i])
	{
		if (temp_set_fd[i] == '\n')
		{
			nl_check = 1;
			break;
		}
		i++;
	}
	if (nl_check == 0)
	{
		prep_cpy(temp_set_fd, line, BUFFER_SIZE);
		return (1);
	}
	prep_cpy(temp_set_fd, line, i);
	mv_forward(temp_set_fd, i + 1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static	char	*temp_set[1024];
	int				res;
	int				i;

	if (!temp_set[fd])
	{
		if ((temp_set[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == 0)
			return (-1);
		i = 0;
		while (i < BUFFER_SIZE + 1)
			(temp_set[fd])[i++] = '\0';
	}
	if (check_tempset(temp_set[fd], line))
		return (1);
	while (1)
	{
		if ((res = read(fd, temp_set[fd], BUFFER_SIZE)) > 0)
		{
			if (check_tempset(temp_set[fd], line))
				return (1);
		}
		else if (res == 0)
		{
			free(temp_set[fd]);
			return (0);
		}
		else if (res == -1)
		{
			free(temp_set[fd]);
			return (-1);
		}
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
