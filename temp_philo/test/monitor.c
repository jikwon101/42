#include "one.h"

void *check_death(void *arg)
{
	t_philo *one;
	long gap;
	one = (t_philo *)arg;
	while (state != DIED)
	{
		gap = get_time() - one->last_meal;
		if (gap > t_die)
		{
		
			pthread_mutex_lock(&m_write);
			printf("%d : died . %lu ms\n", one->idx, gap);
			pthread_mutex_unlock(&m_write);
			print_msg(" is died\n", one);
			pthread_mutex_lock(&m_state);
			state = DIED;
			pthread_mutex_unlock(&m_state);
			break;
		}
	}
	return (NOERR);
}

void *check_full(void *arg)
{
	t_philo *ph_set;
	int	i;

	i = 0;
	ph_set = (t_philo *)arg;
	while (state != DIED && state != FULL)
	{
		while (i < nbr_ph)
		{
			if (ph_set[i].remain > 0)
				i = 0;
			else
				i++;
		}
		pthread_mutex_lock(&m_state);
		state = FULL;
		pthread_mutex_unlock(&m_state);
	}
	return (NOERR);
}
