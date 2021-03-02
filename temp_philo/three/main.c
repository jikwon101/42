#include "three.h"

t_info g_info;

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
	return (NOERR);
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

/*
** 0644  	-rw-w--w--
** (owning) User  : read & write
** 			Group : read
**			Other : read
*/

int		init_sema(void)
{
	int forks;

	forks = g_info.nbr_of_philo / 2;
	sem_unlink("s_write");
	sem_unlink("s_eat");
	sem_unlink("s_death");
	sem_unlink("s_full");
	if ((g_info.s_write =
		sem_open("s_write", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (ERR);
	if ((g_info.s_eat =
		sem_open("s_eat", O_CREAT, 0644, forks)) == SEM_FAILED)
		return (ERR);
	if ((g_info.s_death =
		sem_open("s_death", O_CREAT, 0644, 0)) == SEM_FAILED)
		return (ERR);
	if ((g_info.s_full =
		sem_open("s_full", O_CREAT, 0644, 0)) == SEM_FAILED)
		return (ERR);
	return (NOERR);
}

t_philo	*init_philo(void)
{
	int		i;
	t_philo	*ph_set;

	i = 0;
	ph_set =
		(t_philo *)malloc(sizeof(t_philo) * (g_info.nbr_of_philo));
	if (ph_set == NULL)
		return (NULL);
	while (i < g_info.nbr_of_philo)
	{
		ph_set[i].idx = i + 1;
		ph_set[i].remain = g_info.must_eat;
		ph_set[i].last_meal = get_time();
		ph_set[i].t_start = get_time();
		ph_set[i].state = NORMAL;
		i++;
	}
	return (ph_set);
}

void	print_msg(const char *str, t_philo *one, int64_t time)
{
	if (one->remain == 0 || one->state == DIED)
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
	one->remain = one->remain > 0 ? one->remain - 1 : one->remain;
}

void	*check_death(void *arg)
{
	t_philo	*one;
	int64_t	now;

	one = (t_philo *)arg;
	while (one->state != DIED)
	{
		now = get_time();
		if (now - one->last_meal > g_info.t_die)
		{
			print_msg("is died\n", one, now);
			one->state = DIED;
		}
	}
	sem_post(g_info.s_death);
	return (NOERR);
}

void	*check_full(void *arg)
{
	t_philo	*one;

	one = (t_philo *)arg;
	if (g_info.must_eat == -1)
		return (NOERR);
	while (one->remain != 0)
		usleep(100);
	print_msg("is full\n", one, get_time());
	sem_post(g_info.s_full);
	return (NOERR);
}

int		routine(t_philo *one)
{
	pthread_t	death;
	pthread_t	full;
	int64_t		target;

	pthread_create(&death, NULL, &check_death, (void *)one);
	pthread_detach(death);
	pthread_create(&full, NULL, &check_full, (void *)one);
	pthread_detach(full);
	one->t_start = get_time();
	one->last_meal = one->t_start;
	if (one->idx % 2 == 0)
		usleep(g_info.t_eat * CONVERT_FACTOR);
	while (one->state != DIED)
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

void	kill_process(t_philo *ph_set)
{
	int	i;

	i = 0;
	while (i < g_info.nbr_of_philo)
	{
		kill(ph_set[i].pid, SIGTERM);
		i++;
	}
	return ;
}

void	*read_state_death(void *arg)
{
	t_philo	*ph_set;

	ph_set = (t_philo *)arg;
	sem_wait(g_info.s_death);
	sem_wait(g_info.s_write);
	printf("Someone is died\n");
	sem_post(g_info.s_write);
	kill_process(ph_set);
	return (NOERR);
}

void	*read_state_full(void *arg)
{
	int		full;
	t_philo	*ph_set;

	full = 0;
	ph_set = (t_philo *)arg;
	if (g_info.must_eat == -1)
		return (NOERR);
	while (full != g_info.nbr_of_philo)
	{
		sem_wait(g_info.s_full);
		full++;
	}
	sem_wait(g_info.s_write);
	printf("All are full\n");
	sem_post(g_info.s_write);
	kill_process(ph_set);
	return (NOERR);
}

int		make_monitor(t_philo *ph_set)
{
	pthread_t	state_death;
	pthread_t	state_full;

	if ((pthread_create(&state_death, NULL,
					read_state_death, (void *)ph_set)) != NOERR)
		return (ERR);
	pthread_detach(state_death);
	if ((pthread_create(&state_full, NULL,
					read_state_full, (void *)ph_set)) != NOERR)
		return (ERR);
	pthread_detach(state_death);
	return (NOERR);
}

int		make_process(t_philo *ph_set)
{
	int	i;

	i = 0;
	while (i < g_info.nbr_of_philo)
	{
		ph_set[i].pid = fork();
		if (ph_set[i].pid == 0)
		{
			routine(&ph_set[i]);
			exit(0);
		}
		else if (ph_set[i].pid > 0)
			usleep(50);
		else
			return (ERR);
		i++;
	}
	if (make_monitor(ph_set) == ERR)
		return (ERR);
	i = -1;
	while (++i < g_info.nbr_of_philo)
		waitpid(ph_set[i].pid, &ph_set[i].exit_status, 0);
	return (NOERR);
}

int		clear_sema(int code)
{
	sem_unlink("s_write");
	sem_unlink("s_eat");
	sem_unlink("s_death");
	sem_unlink("s_full");
	sem_close(g_info.s_write);
	sem_close(g_info.s_eat);
	sem_close(g_info.s_death);
	sem_close(g_info.s_full);
	return (code);
}

int		main(int ac, char **av)
{
	t_philo	*ph_set;
	pid_t	process;

	if ((init_info(ac, av) == ERR) || (init_sema() == ERR))
		return (ERR);
	process = fork();
	if (process == 0)
	{
		if ((ph_set = init_philo()) == NULL)
			return (ERR);
		if (make_process(ph_set) == ERR)
			kill_process(ph_set);
		free(ph_set);
		exit(0);
	}
	else if (process > 0)
		waitpid(process, NULL, 0);
	else
		return (clear_sema(ERR));
	return (clear_sema(NOERR));
}
