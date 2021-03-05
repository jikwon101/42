#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		while (1)
			;
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
	return (0);
}
