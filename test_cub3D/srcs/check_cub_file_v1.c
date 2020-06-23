#include "libft.h"
#include <fcntl.h> //open
#include <stdio.h> //ferror
#include <stdlib.h>
typedef struct s_info
{
	int render_size_x;
	int render_size_y;
	char *path_NO;
	char *path_SO;
	char *path_WE;
	char *path_EA;
	char *path_S;
	int	color_FL[3];
	int	color_CL[3];
}		t_info;

int ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}
int ft_atoi_len(char *str, int len)
{
	int nbr;
	int i;

	i = 0;
	nbr = 0;
	while (ft_isdigit(str[i]) && i < len)
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}
int count_digit(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		i++;
		count++;
	}
	return (count);
}

int check_resolution(char *doc, t_info *cub_info)
{
	char *temp_info;
	int i;
	int len;

	i = 2;
	if (!(temp_info = ft_strstr(doc, "R ")))
		return (0);
	while (ft_is_space(temp_info[i]))
		i++;
	if (!ft_isdigit(temp_info[i]))
		return (0);
	if ((len = count_digit(temp_info + i)) <= 0)
		return (0);
	cub_info->render_size_x = ft_atoi_len(temp_info + i, len);
	i = i + len;
	while (ft_is_space(temp_info[i]))
		i++;
	if (!ft_isdigit(temp_info[i]))
		return (0);
	if ((len = count_digit(temp_info + i)) <= 0)
		return (0);
	cub_info->render_size_y = ft_atoi_len(temp_info + i, len);
	return (1);
}

int check_NO(char *doc, t_info *cub_info)
{return (1);}
int check_SO(char *doc, t_info *cub_info)
{return (1);}
int check_WE(char *doc, t_info *cub_info)
{return (1);}
int check_EA(char *doc, t_info *cub_info)
{return (1);}
int check_color(char *doc, t_info *cub_info)
{return (1);}
int check_elm(char *doc, t_info *cub_info)
{
	char *temp;

	//printf("1\n");
	if (!check_resolution(doc, cub_info))
		return (0);
	//printf("2\n");
	if (!check_NO(doc, cub_info))
		return (0);
	//printf("3\n");
	if (!check_SO(doc, cub_info))
		return (0);
	//printf("4\n");
	if (!check_WE(doc, cub_info))
		return (0);
	//printf("5\n");
	if (!check_EA(doc, cub_info))
		return (0);
	//printf("6\n");
	if (!check_color(doc, cub_info))
		return (0);
	//printf("7\n");
	return (1);
}
int main(int argc, char **argv)
{
	int fd;
	char buff[50];
	int byte;
	char *doc;
	char *temp;
	t_info *cub_info;
	
	doc = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("1_Check your cub file");
		return (1);
	}
	while ((byte = read(fd, buff, 50)) != 0)
	{
		
		buff[byte] = '\0';
		temp = (doc == NULL) ? ft_strdup(buff) : ft_strjoin(doc, buff);
		if (doc != NULL)
			free(doc);
		doc = temp;
	}
	if (byte == -1)
	{
		perror("2_Check your cub file");
		free(temp);
		return (1);
	}
	cub_info = malloc(sizeof(t_info *));
	if (!check_elm(doc, cub_info))
	{
		perror("3_Check your cub file");
		free(temp);
		free(cub_info);
		return (1);
	}
	printf("x : %d, y : %d\n", cub_info->render_size_x, cub_info->render_size_y);
	free(cub_info);
	free(temp);
	close(fd);
	return (0);
}
