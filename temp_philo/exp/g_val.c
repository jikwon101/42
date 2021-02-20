#include <pthread.h>
#include <stdio.h>

pthread_mutex_t m_state;
int state;

void  *change(void *arg)
{
	pthread_mutex_lock(&m_state);
	printf("bef_state : %d\n", state);
	state ++;
	printf("aft_state : %d\n", state);
	printf("-------------\n");
	pthread_mutex_unlock(&m_state);
	return (0);
}
int main()
{
	pthread_t t1, t2, t3;
	
	state = 0;
	pthread_mutex_init(&m_state, NULL);
	pthread_create(&t1, NULL, change, NULL);
	pthread_create(&t2, NULL, change, NULL);
	pthread_create(&t3, NULL, change, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
}
