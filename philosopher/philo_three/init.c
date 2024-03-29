/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:06:40 by jikwon            #+#    #+#             */
/*   Updated: 2021/03/04 18:03:22 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

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

/*
** 0644  	-rw-w--w--
** (owning) User  : read & write
** 			Group : read
**			Other : read
*/

int		init_sema(void)
{
	int forks;

	forks = g_info.nbr_of_philo;
	sem_unlink("s_write");
	sem_unlink("s_fork");
	sem_unlink("s_death");
	sem_unlink("s_full");
	if ((g_info.s_write =
		sem_open("s_write", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (ERR);
	if ((g_info.s_fork =
		sem_open("s_fork", O_CREAT, 0644, forks)) == SEM_FAILED)
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
