#include "one.h"
//return ms
long get_time(void)
{
	struct timeval s_time;
	long ms;

	gettimeofday(&s_time, NULL);
	ms = s_time.tv_sec * CF + s_time.tv_usec / CF;
	return (ms);
}


int print_msg(const char *str, t_philo *one)
{
	pthread_mutex_lock(&m_write);
	if (state != DIED && one->remain != 0)
	{
		ft_putnbr(get_time() - one->t_start);
		ft_putstr("ms idx ");
		ft_putnbr(one->idx);
		ft_putstr(str);
	}
	pthread_mutex_unlock(&m_write);
	return (NOERR);
}	
