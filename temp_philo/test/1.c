#include <sys/time.h>
#include <stdio.h>

int main()
{
	struct timeval s_time;

	gettimeofday(&s_time, NULL);
	printf("%ld : %d \n", s_time.tv_sec, s_time.tv_usec);
	printf("%ld\n", s_time.tv_sec * 1000L + s_time.tv_usec / 1000L);
}
