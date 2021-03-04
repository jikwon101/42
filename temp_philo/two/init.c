/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:39:10 by jikwon            #+#    #+#             */
/*   Updated: 2021/03/04 13:50:15 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two.h"

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
