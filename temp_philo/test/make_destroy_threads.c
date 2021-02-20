#include "one.h"
int make_threads(t_philo *ph_set)
{
	int	i;
	pthread_t full;

	i = 0;
	while (i < nbr_ph)
	{
		ph_set[i].last_meal = get_time();
		ph_set[i].t_start = get_time();
		pthread_create(&ph_set[i].thread, NULL, routine, &ph_set[i]);
		usleep(1); 
		i++;
	}
	if (must_eat > 0)
	{
		pthread_create(&full, NULL, &check_full, ph_set);
		pthread_detach(full);
	}
	i = 0;
	while (i < nbr_ph)
		pthread_join(ph_set[i++].thread, NULL);
	if (state == DIED)
		printf("one of them is died\n");
	else if (state == FULL)
		printf("they are  full\n");
	return (NOERR);
}
void finish_threads(t_philo *ph_set)
{
	int i;

	i = 0;
	while (i < nbr_ph)
		pthread_mutex_destroy(&m_forks[i++]);
	pthread_mutex_destroy(&m_write);
	pthread_mutex_destroy(&m_state);
	free(ph_set);
	free(m_forks);
}

