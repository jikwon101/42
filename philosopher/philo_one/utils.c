/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:34:42 by jikwon            #+#    #+#             */
/*   Updated: 2021/03/04 12:49:49 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

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
	if (one->remain == 0 || g_info.state != NORMAL)
		return ;
	pthread_mutex_lock(&g_info.m_write);
	printf("%lldms idx %d %s", time - one->t_start, one->idx, str);
	pthread_mutex_unlock(&g_info.m_write);
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
