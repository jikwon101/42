#include "three.h"

int main()
{
	pid_t pid;
	char *test = (char *)malloc(4);
	pid = fork();
	if (pid == 0)
	{
		printf("child : %p\n", test);
		free(test);
		
		exit(0);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		free(test);
		printf("parent : %p\n", test);
	}
	return (0);
	
}
