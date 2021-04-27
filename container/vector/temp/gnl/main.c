#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "./get_next_line.h"

int main()
{
	int fd_ft = open("../result_ft.txt", O_RDONLY);
	int fd_std = open("../result_std.txt", O_RDONLY);
	char *line_ft;
	char *line_std;
	int res_ft = 10;
	int res_std = 10;

	printf("%20.20s %20.20s\n", "< FT >", "< STD >");
	while (1)
	{
		if (res_ft > 0)
			res_ft = get_next_line(fd_ft, &line_ft);
		printf("%20.20s ", line_ft);
		if (res_std > 0)
			res_std = get_next_line(fd_std, &line_std);
		printf("%20.20s\n",line_std);
		if (res_ft == 0 && res_std == 0)
			break;
	}
}
