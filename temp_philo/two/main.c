#include "two.h"

int64_t	ft_atoi(char *str)
{
	int		i;
	int64_t	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			nbr = nbr * 10 + str[i] - '0';
		else
			return (NONDIGIT);
		i++;
	}
	return (nbr);
}

int64_t	get_time(void)
{
	struct timeval	s_time;
	int64_t			temp;

	gettimeofday(&s_time, NULL);
	temp = s_time.tv_sec * CONVERT_FACTOR;
	temp += s_time.tv_usec / CONVERT_FACTOR;
	return (temp);
}

int		init_info(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (ERR);
	if ((g_info.nbr_of_philo = ft_atoi(av[1])) == NONDIGIT)
		return (ERR);
	if ((g_info.t_die = ft_atoi(av[2])) == NONDIGIT)
		return (ERR);
	if ((g_info.t_eat = ft_atoi(av[3])) == NONDIGIT)
		return (ERR);
	if ((g_info.t_sleep = ft_atoi(av[4])) == NONDIGIT)
		return (ERR);
	if (ac == 6)
	{
		if ((g_info.must_eat = ft_atoi(av[5])) == NONDIGIT)
			return (ERR);
	}
	else
		g_info.must_eat = -1;
	g_info.state = NORMAL;
	return (NOERR);
}

int		init_sema(void)
{
	int	forks;

	forks = g_info.nbr_of_philo / 2;
	sem_unlink("s_write");
	sem_unlink("s_eat");
	sem_unlink("s_state");
	if ((g_info.s_write =
		sem_open("s_write", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (ERR);
	if ((g_info.s_eat =
		sem_open("s_eat", O_CREAT, 0644, forks)) == SEM_FAILED)
		return (ERR);
	if ((g_info.s_state =
		sem_open("s_state", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (ERR);
	return (NOERR);
}

t_philo	*init_philo(void)
{
	t_philo	*ph_set;
	int		i;

	i = 0;
	ph_set = (t_philo *)malloc(sizeof(t_philo) * g_info.nbr_of_philo);
	if (ph_set == NULL)
		return (NULL);
	while (i < g_info.nbr_of_philo)
	{
		ph_set[i].idx = i + 1;
		ph_set[i].remain = g_info.must_eat;
		ph_set[i].last_meal = get_time();
		ph_set[i].t_start = get_time();
		i++;
	}
	return (ph_set);
}

void	print_msg(const char *str, t_philo *one, int64_t time)
{
	if (one->remain == 0 || g_info.state != NORMAL)
		return ;
	sem_wait(g_info.s_write);
	printf("%lldms idx %d %s", time - one->t_start, one->idx, str);
	sem_post(g_info.s_write);
}

void	do_eat(t_philo *one)
{
	int64_t	target;

	sem_wait(g_info.s_eat);
	print_msg("has taken forks\n", one, get_time());
	one->last_meal = get_time();
	print_msg("is eating\n", one, one->last_meal);
	target = one->last_meal + g_info.t_eat;
	while (get_time() < target)
		usleep(50);
	sem_post(g_info.s_eat);
	one->remain > 0 ? one->remain -= 1 : 0;
}

void	*check_death(void *arg)
{
	t_philo	*one;
	int64_t	time;

	one = (t_philo *)arg;
	while (g_info.state != DIED)
	{
		time = get_time();
		if (time - one->last_meal > g_info.t_die)
		{
			print_msg("is died\n", one, time);
			sem_wait(g_info.s_state);
			g_info.state = DIED;
			sem_post(g_info.s_state);
			break ;
		}
	}
	return (NOERR);
}

void	*check_full(void *arg)
{
	t_philo	*ph_set;
	int		i;

	ph_set = (t_philo *)arg;
	if (g_info.must_eat == -1)
		return (NOERR);
	while (g_info.state == NORMAL)
	{
		while (i < g_info.nbr_of_philo)
		{
			if (ph_set[i].remain > 0)
				i = 0;
			else
				i++;
		}
		sem_wait(g_info.s_state);
		g_info.state = FULL;
		sem_post(g_info.s_state);
	}
	return (NOERR);
}

void	*routine(void *arg)
{
	t_philo		*one;
	int			i;
	int64_t		target;
	pthread_t	death;

	i = 0;
	one = (t_philo *)arg;
	pthread_create(&death, NULL, &check_death, (void *)one);
	pthread_detach(death);
	if (one->idx % 2 == 0)
		usleep(g_info.t_eat * 2 / 3);
	while (g_info.state == NORMAL)
	{
		do_eat(one);
		print_msg("is sleeping\n", one, get_time());
		target = get_time() + g_info.t_sleep;
		while (get_time() < target)
			usleep(50);
		print_msg("is thinking\n", one, get_time());
	}
	return (NOERR);
}

int		make_threads(t_philo *ph_set)
{
	int			i;
	pthread_t	full;

	i = 0;
	while (i < g_info.nbr_of_philo)
	{
		pthread_create(&ph_set[i].thread, NULL, &routine, &ph_set[i]);
		usleep(50);
		i++;
	}
	pthread_create(&full, NULL, &check_full, ph_set);
	pthread_detach(full);
	i = 0;
	while (i < g_info.nbr_of_philo)
		pthread_join(ph_set[i++].thread, NULL);
	return (NOERR);
}

int		clear_sema(int code)
{
	sem_unlink("s_eat");
	sem_unlink("s_write");
	sem_unlink("s_state");
	sem_close(g_info.s_eat);
	sem_close(g_info.s_write);
	sem_close(g_info.s_state);
	return (code);
}

int		main(int ac, char **av)
{
	t_philo	*ph_set;

	if (init_info(ac, av) == ERR)
		return (ERR);
	if (init_sema() == ERR)
		return (ERR);
	if ((ph_set = init_philo()) == NULL)
		return (ERR);
	make_threads(ph_set);
	if (g_info.state == DIED)
		printf("Someone is died\n");
	else if (g_info.state == FULL)
		printf("All are full\n");
	free(ph_set);
	return (clear_sema(NOERR));
}
