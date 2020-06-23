#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int ft_print(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		printf("|%s|", array[i]);
		i++;
	}
	printf("\n");
	return (0);
}

int check_R(char **elem)
{
	printf("check_R\n");
	ft_print(elem);
return (1);}

int check_path(char **elem, char *option)
{	printf("check_path [%s]\n", option);
	ft_print(elem);
return (1);}

int check_color(char **elem, char *option)
{	printf("check_color [%s]\n", option);
	ft_print(elem);
return (1);}

int check_elem(char **elem)
{
	int result;
	if (!ft_strncmp((const char *)elem[0], "R", 1))
		result = check_R(elem);
	else if (!ft_strncmp((const char *)elem[0], "NO", 2))
		result = check_path(elem, "NO");
	else if (!ft_strncmp((const char *)elem[0], "SO", 2))
		result = check_path(elem, "SO");
	else if (!ft_strncmp((const char *)elem[0], "WE", 2))
		result = check_path(elem, "WE");
	else if (!ft_strncmp((const char *)elem[0], "EA", 2))
		result = check_path(elem, "EA");
	else if (!ft_strncmp((const char *)elem[0], "S", 1))
		result = check_path(elem, "S");
	else if (!ft_strncmp((const char *)elem[0], "F", 1))
		result = check_color(elem, "F");
	else if (!ft_strncmp((const char *)elem[0], "C", 1))
		result = check_color(elem, "C");
	else
		return (0);
	if (!result)
		return (0);
	return (1);
}

void ft_free(char **tgr)
{
	int	i;

	i = 0;
	while (tgr[i])
	{
		free(tgr[i]);
		i++;
	}
	free(tgr);
	return ;
}

int main(int argc, char **argv)
{
	char **result1;
	char **result2;
	int i;
	int j;
	int temp;
	
	int fd;
	char buff[51];
	int byte;
	char *doc;
	char *temp_d;

	doc = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("check file\n");
		return (1);
	}
	while ((byte = read(fd, buff, 50)) != 0)
	{
		buff[byte] = '\0';
		temp_d = (doc == NULL) ? ft_strdup(buff) : ft_strjoin(doc, buff);
		if (doc != NULL)
			free(doc);
		doc = temp_d;
	}
	i = 0;
	result1 = ft_split(doc, '\n');
	while (result1[i])
	{
		j = 0;
		result2 = ft_split(result1[i], ' ');
		temp = check_elem(result2);
		ft_free(result2);
		if (!temp)
			break;
		i++;
	}
	ft_free(result1);
	if (i < 8)
		printf("\nNot satisfied\n");
	else 
		printf("\nSatistied\n");
	return (0);
}
