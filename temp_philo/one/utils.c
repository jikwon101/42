#include "one.h"
//return m

uint64_t get_time(void)
{
	struct timeval s_time;

	gettimeofday(&s_time, NULL);
	return (s_time.tv_sec * CF + s_time.tv_usec / CF);
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
typedef struct s_tmp
{
	t_philo *one;
	const char *str;
} t_tmp;

void *print_temp(void *arg)
{
	t_tmp *temp;
	temp = (t_tmp *)arg;
	pthread_mutex_lock(&m_write);
	if (temp->one->remain!= 0 && state != DIED)
	{
		ft_putnbr(get_time() - temp->one->t_start);
		ft_putstr("ms idx ");
		ft_putnbr(temp->one->idx);
		ft_putstr(temp->str);
	}
	pthread_mutex_unlock(&m_write);
	return (0);
}
void print_msg_thread(const char *str, t_philo *one)
{
	pthread_t t_msg;
	t_tmp temp;

	temp.one = one;
	temp.str = str;
	pthread_create(&t_msg, NULL, print_temp, &temp);
	pthread_join(t_msg, NULL);
}
