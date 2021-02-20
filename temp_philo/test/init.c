#include "one.h"

int init_mutex(void)
{
	int i;

	i = 0;
	m_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nbr_ph);
	if (m_forks == NULL)
		return (ERR);
	while (i < nbr_ph)
		pthread_mutex_init(&m_forks[i++], NULL);
	pthread_mutex_init(&m_write, NULL);
	pthread_mutex_init(&m_state, NULL);
	return (NOERR);
}

t_philo *init_threads(void)
{
	t_philo *ph_set;
	int i;

	i = 0;
	ph_set = (t_philo *)malloc(sizeof(t_philo) * nbr_ph);
	while (i < nbr_ph)
	{
		ph_set[i].idx = i + 1;
		ph_set[i].left_fork = &m_forks[i];
		ph_set[i].right_fork = &m_forks[(i + 1) % nbr_ph];
		ph_set[i].remain = must_eat;
		//ph_set[i].last_meal = get_time();
		//ph_set[i].t_start = get_time();
		i++;
	}
	return (ph_set);
}

int	init_state(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (ERR);
	if ((nbr_ph = ft_atoi(av[1])) == -1)
		return (ERR);
	if ((t_die = ft_atoi(av[2])) == -1)
		return (ERR);
	if ((t_eat = ft_atoi(av[3])) == -1)
		return (ERR);	
	if ((t_sleep = ft_atoi(av[4])) == -1)
		return (ERR);	
	if (ac == 6)
	{
		if ((must_eat = ft_atoi(av[5])) == -1)
			return (ERR);	
	}
	else
		must_eat = -1;
	state = NORMAL;
	return (NOERR);
}
