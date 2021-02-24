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
	sem_t *s_full;
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
	g_info.nbr_of_philo = 5;
	g_info.t_die = 800;
	g_info.t_eat = 200;
	g_info.t_sleep = 200;
	g_info.must_eat = 5;
}
uint64_t get_time(void)
{
	struct timeval s_time;

	gettimeofday(&s_time, NULL);
	return (s_time.tv_sec * CONVERT_FACTOR + s_time.tv_usec / CONVERT_FACTOR);
}

int init_sema(void)
{
	sem_unlink("s_write");
	sem_unlink("s_eat");
	sem_unlink("s_death");
	sem_unlink("s_full");
	g_info.s_write = sem_open("s_write", O_CREAT, 0644, 1);
	g_info.s_eat = sem_open("s_eat", O_CREAT, 0644, g_info.nbr_of_philo/2);
	g_info.s_death= sem_open("s_death", O_CREAT, 0644, 0);
	g_info.s_full = sem_open("s_full", O_CREAT, 0644, 0);
	return (NOERR);
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

void ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

void ft_putnbr(long num)
{
	char c ;
	if (num >= 10)
		ft_putnbr(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}

void print_msg(const char *str, t_philo *one)
{
	if (one->remain == 0 || one->state == DIED)
		return ;
	sem_wait(g_info.s_write);
	ft_putnbr(get_time() - one->t_start);
	ft_putstr("ms idx ");
	ft_putnbr(one->idx);
	ft_putstr(str);
	sem_post(g_info.s_write);
}

void print_temp(const char *str)
{
	sem_wait(g_info.s_write);
	ft_putstr("ms ");
	ft_putstr(str);
	sem_post(g_info.s_write);

}

void do_eat(t_philo *one)
{
	uint64_t target;

	sem_wait(g_info.s_eat);
	//print_msg(" has taken forks\n", one);
	one->last_meal = get_time();
	//print_msg(" is eating\n", one);
	one->remain = one->remain > 0 ? one->remain - 1 : one->remain;
	target = get_time() + g_info.t_eat;
	while (get_time() < target)
		usleep(50);
	sem_post(g_info.s_eat);
}

void *check_death(void *arg)
{
	t_philo *one;
	long time;
	one = (t_philo *)arg;
	while (one->state != DIED)
	{
		if ((time = get_time() - one->last_meal) > g_info.t_die)
		{
			print_msg(" is died\n", one);
			one->state = DIED;
		}
	}
	sem_post(g_info.s_death);
	return (NOERR);
}

void *change_state(void *arg)
{
	t_philo *one;

	one = (t_philo *)arg;
	while (one->state != DIED)
		;
	sem_post(g_info.s_death);
	return (NOERR);
}

void *check_full(void *arg)
{
	t_philo *one;

	one = (t_philo *)arg;
	if (g_info.must_eat == -1)
		return (NOERR);
	while (one->remain != 0)
		;
	print_msg(" is full\n", one);
	sem_post(g_info.s_full);
	return (NOERR);
}
int	routine(t_philo *one)
{
	pthread_t death;
	pthread_t state_write;
	uint64_t target;
	pthread_t full;

	pthread_create(&death, NULL, &check_death, one);
	pthread_detach(death);
	pthread_create(&full, NULL, &check_full, one);
	pthread_detach(full);
	if (one->idx % 2 == 0)
		usleep(g_info.t_eat * CONVERT_FACTOR / 2 + (100 - one->idx *10));
	while (one->state != DIED)
	{
		do_eat(one);
		////print_msg(" is sleeping\n", one);
		target = get_time() + g_info.t_sleep;
		while (get_time() < target)
			usleep(50);
		//print_msg(" is thinking\n", one);
	}
	return (NOERR);
}

void kill_process(t_philo *ph_set)
{
	int i;

	i = 0;
	while (i < g_info.nbr_of_philo)
	{
		kill(ph_set[i].pid, SIGTERM);
		i++;
	}
	return ;
}


void *read_state_death(void *arg)
{
	t_philo *ph_set;
	
	ph_set = (t_philo *)arg;
	sem_wait(g_info.s_death);
	printf("%llums ", get_time() - ph_set[0].t_start);
	printf("someone is died\n");
	kill_process(ph_set);
	return (NOERR);

}
void *read_state_full(void  *arg)
{
	int full;
	t_philo *ph_set;

	ph_set = (t_philo *)arg;
	if (g_info.must_eat == -1)
		return (NOERR);
	while (full != g_info.nbr_of_philo)
	{
		sem_wait(g_info.s_full);
		full++;
		printf("%d\n", full);
	}
	printf("all are full\n");
	kill_process(ph_set);
	return (NOERR);
}

int make_process(t_philo *ph_set)
{
	int i;
	pthread_t state_death;
	pthread_t state_full;
	pthread_t temp;

	i = 0;	
	pthread_create(&state_death, NULL, read_state_death, ph_set);
	pthread_detach(state_death);
	pthread_create(&state_full, NULL, read_state_full, ph_set);
	pthread_detach(state_death);
	while (i < g_info.nbr_of_philo)
	{
		ph_set[i].pid = fork();
		if (ph_set[i].pid == 0)
		{
			routine(&ph_set[i]);
			exit (0);
		}
		i++;
	}
	i = 0;
	while (i < g_info.nbr_of_philo)
		waitpid(ph_set[i++].pid, NULL, 0);

	return (0);
}

int main()
{
	t_philo *ph_set;
	pid_t process;

	init_info();
	init_sema();
	process = fork();
	if (process == 0)
	{
		ph_set = init_philo();
		make_process(ph_set);
		free(ph_set);
		exit(0);
	}
	else
		waitpid(process, NULL, 0);
	sem_unlink("s_write");
	sem_unlink("s_eat");
	sem_unlink("s_death");
	sem_unlink("s_full");
	sem_close(g_info.s_write);
	sem_close(g_info.s_eat);
	sem_close(g_info.s_death);
	sem_close(g_info.s_full);
	return (0);

}
