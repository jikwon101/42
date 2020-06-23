#include "./libft_bonus/libft.h"
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	printf("fd : %d\n", fd);
	while ((get_next_line(fd, &line) >0))
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);


}
