/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:07:56 by jikwon            #+#    #+#             */
/*   Updated: 2021/03/04 14:32:51 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

void	kill_process(t_philo *ph_set)
{
	int	i;

	i = 0;
	while (i < g_info.nbr_of_philo)
	{
		kill(ph_set[i].pid, SIGTERM);
		i++;
	}
	free(ph_set);
	return ;
}

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

void	print_msg(const char *str, t_philo *one, int64_t time)
{
	if (one->remain == 0 || one->state == DIED)
		return ;
	sem_wait(g_info.s_write);
	printf("%lldms idx %d %s", time - one->t_start, one->idx, str);
	sem_post(g_info.s_write);
}
