#include <stdio.h>
#include <stdlib.h>


int	ft_new(char **line)
{
	if (*line)
		printf("*line\n");
	if (!(*line))
		printf("!(*line)\n");
	if (*line == 0)
		printf("*line == 0\n");
	if (*line == NULL)
		printf("*line == NULL\n");
	return (0);
}	


int ft_new1(char *line)
{

	if (line)
		printf("line\n");
	if (!(line))
		printf("!(line)\n");
	if (line == 0)
		printf("line == 0\n");
	if (line == NULL)
		printf("line == NULL\n");
	return (0);
}

int 	main()
{
	char *new = 0;
	
	ft_new(&new);
	printf("^^^^^\n");
	ft_new1(new);
	printf("----------------\n");
	char *temp;
	temp = (char *)malloc(3);
	ft_new(&temp);
	printf("^^^^^\n");
	ft_new1(temp);
	return (0);
}
/*
int main()
{
	char *new =0;

	if (new)
		printf("new\n");
	if (!new)
		printf("!new\n");
	new = (char *)malloc(3);
	if (new)
		printf("m new\n");
	if (!new)
		printf("m !new\n");
}
*/
