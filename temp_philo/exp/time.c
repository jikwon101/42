#include <sys/time.h>

#include <stdio.h>
int get_time()
{
	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);
	printf("");
	printf("");
	printf("");
	gettimeofday(&end, NULL);
	long sec = end.tv_sec - start.tv_sec;
	long mic = end.tv_usec - start.tv_usec;
	printf("%lu:%lu\n", sec, mic);
	return (0);
}
int main()
{
	get_time();
}
