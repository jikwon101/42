/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:36:44 by jikwon            #+#    #+#             */
/*   Updated: 2021/02/25 20:46:15 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

int		init_mutex(void)
{
	int	i;

	i = 0;
	g_info.m_forks = (pthread_mutex_t *)malloc(
					sizeof(pthread_mutex_t) * g_info.nbr_of_philo);
	if (g_info.m_forks == NULL)
		return (ERR);
	while (i < g_info.nbr_of_philo)
		pthread_mutex_init(&g_info.m_forks[i++], NULL);
	pthread_mutex_init(&g_info.m_write, NULL);
	pthread_mutex_init(&g_info.m_state, NULL);
	return (NOERR);
}

t_philo	*init_threads(void)
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
		ph_set[i].left_fork = &g_info.m_forks[i];
		ph_set[i].right_fork =
				&g_info.m_forks[(i + 1) % g_info.nbr_of_philo];
		ph_set[i].remain = g_info.must_eat;
		i++;
	}
	return (ph_set);
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
