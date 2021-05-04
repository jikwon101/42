#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "./get_next_line.h"


int main()
{
	int fd_ft = open("/Users/jieunkwon/Desktop/42seoul/private_git/container/vector/temp/result_ft.txt", O_RDONLY);
	int fd_std = open("/Users/jieunkwon/Desktop/42seoul/private_git/container/vector/temp/result_std.txt", O_RDONLY);
	char *line_ft;
	char *line_std;
	int res_ft = 10;
	int res_std = 10;

	if (fd_ft == -1 || fd_std == -1)
	{
		printf("%s", "Error open files\n");
		return (1);
	}
	printf("%30.30s%10s|%30.30s\n", "< FT >","", "< STD >");
	for (int i = 0 ; i < 16 ; i++)	
		printf("-----");			// 5
	printf("\n");
	while (1)
	{
		if (res_ft > 0)
			res_ft = get_next_line(fd_ft, &line_ft);
		printf("%2s","");				// [1]
		printf("%30.30s", line_ft);		//
		printf("%8s|", "");				// [2] : [1] + [2] = 10
		if (res_std > 0)
			res_std = get_next_line(fd_std, &line_std);
		printf("%5s","");				// [3] : random
		printf("%30.30s\n",line_std);	//
		if (res_ft == 0 && res_std == 0)
			break;
		if (res_ft == -1 || res_std == -1)
			return (1);
	}
}
