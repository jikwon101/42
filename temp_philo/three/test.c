#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <pthread.h>
#include <signal.h>

sem_t *test;
int temp = 0;

void *function1(void *arg)
{
	int *num;
	num = (int *)arg;
	
	printf("%d is sleeping\n", *num);
	usleep(1 * 1000000);
	sem_post(test);
	return 0;
}
void *function2(void *arg)
{
	int *num;
	num = (int *)arg;
	usleep(1 * 1000000);
	printf("%d is sleeping\n", *num);
	usleep(1 * 1000000);
	sem_post(test);
	return 0;
}
void *function3(void *arg)
{
	int *num;
	num = (int *)arg;
	sem_wait(test);
	printf("all of them are awake\n");
	return 0;
}

void *function_test(void *arg)
{
	int *addr = (int *)arg;

	printf("IN child process1 : %d[%p]\n", *addr, addr);
	(*addr)++;
	printf("IN child process2 : %d[%p]\n", *addr, addr);
	return (0);
}
int main()
{
	pid_t pid;
	pthread_t t1, t2, t3;
	int a = 1;
	int b = 2;
	int c = 3;
	int *addr = &a;
	sem_unlink("s_test");
	test = sem_open("s_test", O_CREAT, 0644, -1);
	printf("a : %p\n", &a);
	printf("addr : %p\n", addr);
	pid = fork();
	if (pid == 0)
	{
		pthread_create(&t1, NULL, &function_test, addr);
		pthread_join(t1, NULL);
		exit (0);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
	printf("IN parent process : %d[%p]\n", *addr, addr);
	sem_unlink("s_test");
	sem_close(test);
}
