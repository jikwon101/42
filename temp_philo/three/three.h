/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:27:16 by jikwon            #+#    #+#             */
/*   Updated: 2021/03/04 14:15:06 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREE_H
# define THREE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>

# define NORMAL 0
# define DIED 1
# define ERR 1
# define NOERR 0
# define NONDIGIT -1
# define CONVERT_FACTOR 1000L

typedef struct	s_info
{
	int		nbr_of_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		must_eat;
	sem_t	*s_write;
	sem_t	*s_eat;
	sem_t	*s_death;
	sem_t	*s_full;
}				t_info;

typedef struct	s_philo
{
	int		idx;
	pid_t	pid;
	int		remain;
	int		state;
	int		exit_status;
	int64_t	last_meal;
	int64_t	t_start;
}				t_philo;

t_info			g_info;

/*
** main.c
*/

int				process(t_philo *ph_set);
void			do_eat(t_philo *ph_set);
int				routine(t_philo *one);

/*
** monitor.c
*/

void			*check_death(void *arg);
void			*check_full(void *arg);
int				make_monitor(t_philo *ph_set);
void			*read_state_death(void *arg);
void			*read_state_full(void *arg);

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

void			kill_process(t_philo *ph_set);
int64_t			ft_atoi(char *str);
int64_t			get_time(void);
void			print_msg(const char *str, t_philo *one, int64_t time);
#endif
