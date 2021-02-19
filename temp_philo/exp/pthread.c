#include <pthread.h>
#include <stdio.h>

void *ft_start(void *data)
{
	int i;
	int a = *(int *)data;
	while (i < 10)
	{
		printf("%d\n", i * a);
		i++;
	}	
	return (void *)(i * 100);
}
int main()
{
	int a =100;
	pthread_t thread_t;
	int status;

	pthread_create(&thread_t, NULL, ft_start, (void *)&a);
	pthread_join(thread_t, (void **)&status);
	printf("Thread ENd %d\n", status);
	return 1;
}
