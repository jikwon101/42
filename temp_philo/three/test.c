#include "three.h"

int main()
{
	pid_t pid;

	pid = fork();
	if (pid ==0 )
	{
		exit (0);
	}
	else
	{
		waitpid(pid, NULL, 0);
		kill(pid, SIGTERM);
	}
	printf("ho\n");
}
