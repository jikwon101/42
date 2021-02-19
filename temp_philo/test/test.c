#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex;
typedef struct s_test
{
	int type;
}	t_test;
t_test test;
void *ft(void *arg)
{
	int *num = (int *)arg;
	test.type = *num;
	return (0);
}
int main()
{
	pthread_t t1, t2;
	int a = 1;
	int b = 2;
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, NULL, ft, (void *)&a);
	pthread_create(&t2, NULL, ft, (void *)&b);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("type:%d\n",  test.type);
	pthread_mutex_destroy(&mutex);
}
