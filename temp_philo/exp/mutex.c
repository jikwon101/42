#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex;
int cnt = 0;

void *count(void *arg)
{
	int i;
	char *name;

	name = (char *)arg;
	pthread_mutex_lock(&mutex);
	i = 0;
	cnt = 0;
	while (i < 10)
	{
		printf("%s cnt: %d\n", name, cnt);
		cnt++;
		usleep(1);
		i++;
	}
	pthread_mutex_unlock(&mutex);
	return ((void *)NULL);
}

int main()
{
	pthread_t t1, t2;

	pthread_mutex_init(&mutex, NULL);
	
	pthread_create(&t1, NULL, count, (void *)"thread1");
	pthread_create(&t2, NULL, count, (void *)"thread2");

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	pthread_mutex_destroy(&mutex);
}
