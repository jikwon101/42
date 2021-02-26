#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <pthread.h>
#include <signal.h>

void kill_process(pid_t *ph)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (ph[i] > 0)
			kill(ph[i], SIGTERM);
		i++;
	}
	return ;
}
int new()
{
	pid_t pid[5];
	int i = 0;

	while (i < 5)
		pid[i++] = 0;
	i= 0;
	while (i < 5)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			int j = 0;
			while (j < 3)
			{
				printf("I am %dtimes %d\n", j, i);
				usleep(1 * 1000000);
				j++;
			}
			return (0);
		}
		else
		{
			if (i == 3)
			{
				kill_process(pid);
				exit(0);
			}
		}
		i++;
	}
	int status[5];
	i = 0;
	while (i < 5)
	{
		waitpid(pid[i], &status[i], 0);
		i++;
	}
	return (0);
}
/*
int main()
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		new();
		printf("XX\n");
		
	}
	else
	{
		waitpid(pid, 0, 0);
	}
	printf("OO\n");
}*/

int main()
{
	while (1)
		;
}
