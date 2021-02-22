#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <pthread.h>
#include <signal.h>
# define NORMAL 0
# define DIED 1
# define FULL 2
# define CONVERT_FACTOR 1000L
# define ERR 1
# define NOERR 0
typedef struct s_info
{
	int nbr_of_philo;
	uint64_t t_die;
	uint64_t t_eat;
	uint64_t t_sleep;
	int must_eat;
	sem_t *s_write;
	sem_t *s_eat;
	sem_t *s_death;
}		t_info;


typedef struct s_philo
{
	int idx;
	pid_t pid;
	int remain;
	int state;
	uint64_t last_meal;
	uint64_t t_start;
}	t_philo;

t_info g_info;
void init_info(void)
{
	g_info.nbr_of_philo = 2;
	g_info.t_die = 310;
	g_info.t_eat = 200;
	g_info.t_sleep = 100;
	g_info.must_eat = 2;
}
uint64_t get_time(void)
{
	struct timeval s_time;

	gettimeofday(&s_time, NULL);
	return (s_time.tv_sec * CONVERT_FACTOR + s_time.tv_usec / CONVERT_FACTOR);
}

void init_sema(void)
{
	sem_unlink("s_write");
	sem_unlink("s_eat");
	sem_unlink("s_death");
	g_info.s_write = sem_open("s_write", O_CREAT, 0644, 1);
	g_info.s_eat = sem_open("s_eat", O_CREAT, 0644, g_info.nbr_of_philo/2);
	g_info.s_death = sem_open("s_death", O_CREAT, 0644, 0);
}
t_philo *init_philo(void)
{
	int i;
	t_philo *ph_set;

	i = 0;
	ph_set = (t_philo *)malloc(sizeof(t_philo) * (g_info.nbr_of_philo));
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
void do_eat(t_philo *one)
{
	sem_wait(g_info.s_eat);
	sem_wait(g_info.s_write);
	printf("%d is eating\n", one->idx);
	sem_post(g_info.s_write);
	usleep(g_info.t_eat * 1000L);
	one->remain = one->remain > 0 ? one->remain - 1 : one->remain;
	sem_post(g_info.s_eat);
}
void *check_death(void *arg)
{
	t_philo *one;

	one = (t_philo *)arg;
	while (one->state != DIED)
	{
		if (get_time() - one->last_meal > g_info.t_die)
		{
			sem_wait(g_info.s_write);
			printf("%d is died\n", one->idx);
			sem_post(g_info.s_write);
			one->state = DIED;
			sem_post(g_info.s_death);
		}
	}
	return (NOERR);
}
int	routine(t_philo *one)
{
	pthread_t death;
	
	pthread_create(&death, NULL, &check_death, one);
	pthread_detach(death);
	while (one->state != DIED)
	{
		do_eat(one);
		printf("%d is sleeping\n", one->idx);
		usleep(g_info.t_sleep * 1000L);
		printf("%d is thinking\n", one->idx);
	}
	return (NOERR);
}

void kill_process(t_philo *ph_set)
{
	int i;

	i = 0;
	while (i < g_info.nbr_of_philo)
	{
		kill(ph_set[i].pid, SIGINT);
		i++;
	}
	return ;
}

int make_process(t_philo *ph_set)
{
	int i;

	i = 0;	
	while (i < g_info.nbr_of_philo)
	{
		ph_set[i].pid = fork();
		if (ph_set[i].pid > 0)
		{
			routine(&ph_set[i]);
			return (0);
		}
	}
	i = 0;
	while (i < g_info.nbr_of_philo)
		waitpid(ph_set[i++].pid, NULL, 0);
	return (0);
}
int main()
{
	t_philo *ph_set;

	init_info();
	init_sema();
	ph_set = init_philo();
	make_process(ph_set);
	sem_wait(g_info.s_death);
	kill_process(ph_set);
	printf("DIED\n");

}

