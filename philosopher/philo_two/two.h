/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:49:04 by jikwon            #+#    #+#             */
/*   Updated: 2021/03/04 18:04:10 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWO_H
# define TWO_H

# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <semaphore.h>
# include <unistd.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/stat.h>

# define ERR 1
# define NOERR 0
# define NORMAL 0
# define DIED 1
# define FULL 2
# define NONDIGIT -1
# define CONVERT_FACTOR 1000L

typedef struct	s_info
{
	int		nbr_of_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		must_eat;
	int		state;
	sem_t	*s_write;
	sem_t	*s_fork;
	sem_t	*s_state;
}				t_info;

typedef struct	s_philo
{
	int			idx;
	pthread_t	thread;
	int			remain;
	int64_t		last_meal;
	int64_t		t_start;
}				t_philo;

t_info			g_info;

/*
** main.c
*/

int				make_threads(t_philo *ph_set);
void			*routin(void *arg);
void			do_eat(t_philo *one);

/*
** monitor.c
*/

void			*check_death(void *arg);
void			*check_full(void *arg);

/*
** init.c
*/

int				init_info(int ac, char **av);
int				init_sema(void);
t_philo			*init_philo(void);

/*
** clean.c
*/

int				clean_sema(int code);

/*
** utils.c
*/

void			print_msg(const char *str, t_philo *one, int64_t time);
int64_t			ft_atoi(char *str);
int64_t			get_time(void);

#endif
