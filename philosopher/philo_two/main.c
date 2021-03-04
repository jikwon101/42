/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:41:00 by jikwon            #+#    #+#             */
/*   Updated: 2021/03/04 18:05:11 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two.h"

void	do_eat(t_philo *one)
{
	int64_t	target;

	sem_wait(g_info.s_fork);
	sem_wait(g_info.s_fork);
	print_msg("has taken forks\n", one, get_time());
	one->last_meal = get_time();
	print_msg("is eating\n", one, one->last_meal);
	target = one->last_meal + g_info.t_eat;
	while (get_time() < target)
		usleep(50);
	sem_post(g_info.s_fork);
	sem_post(g_info.s_fork);
	one->remain > 0 ? one->remain -= 1 : 0;
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
	return (clean_sema(NOERR));
}
