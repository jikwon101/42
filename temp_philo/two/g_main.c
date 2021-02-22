#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>

# define ERR 1
# define NOERR 0
# define NORMAL 0
# define DIED 1
# define FULL 2
# define CONVERT_FACTOR 1000L

typedef struct s_info
{
	int nbr_of_philo;
	uint64_t t_die;
	uint64_t t_eat;
	uint64_t t_sleep;
	int must_eat;
	int state;
	sem_t *s_write;
	sem_t *s_eat;
	sem_t *s_state;
}		t_info;

typedef struct s_philo
{
	int idx;
	pthread_t thread;
	int remain;
	uint64_t last_meal;
	uint64_t t_start;
}	t_philo;

t_info info;

uint64_t get_time(void)
{
	struct timeval s_time;

	gettimeofday(&s_time, NULL);
	return (s_time.tv_sec * CONVERT_FACTOR + s_time.tv_usec / CONVERT_FACTOR);
}


int init_info(void)
{
	info.nbr_of_philo = 5;
	info.t_die = 800;
	info.t_eat = 200;
	info.t_sleep = 200;
	info.must_eat = 7;
	info.state = NORMAL;
	sem_unlink("s_eat");
	sem_unlink("s_write");
	sem_unlink("s_state");
	info.s_write = sem_open("s_write", O_CREAT, 0644, 1);
	int max_eat  = info.nbr_of_philo  / 2;
	info.s_eat = sem_open("s_eat", O_CREAT, 0644, max_eat);
	info.s_state = sem_open("s_state", O_CREAT, S_IRWXU, 1);
	return (NOERR);
}

t_philo *init_philo()
{
	t_philo *ph_set;
	int i;

	i = 0;
	ph_set = (t_philo *)malloc(sizeof(t_philo) * info.nbr_of_philo);
	while (i < info.nbr_of_philo)
	{
		ph_set[i].idx = i + 1;
		ph_set[i].remain = info.must_eat;
		ph_set[i].last_meal = get_time();
		ph_set[i].t_start = get_time();
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
	if (one->remain == 0 || info.state == DIED || info.state == FULL)
		return ;
	sem_wait(info.s_write);
	ft_putnbr(get_time() - one->t_start);
	ft_putstr("ms idx ");
	ft_putnbr(one->idx);
	ft_putstr(str);
	sem_post(info.s_write);
}

int do_eat(t_philo *one)
{
	sem_wait(info.s_eat);
	print_msg(" has taken forks\n", one);
	print_msg(" is eating\n", one);
	one->last_meal = get_time();
	uint64_t target;
	target = one->last_meal + info.t_eat;
	while (get_time() < target)
		usleep(50);
	usleep(info.t_eat);
	sem_post(info.s_eat);
	one->remain > 0 ? one->remain -= 1 : 0;
	return (0);
}
void *check_death(void *arg)
{
	t_philo *one;
	uint64_t gap;
	uint64_t die;


	one = (t_philo *)arg;
	while (info.state != DIED)
	{
		gap = get_time() - one->last_meal;
		if (gap > info.t_die)
		{
			print_msg(" is died\n", one);
			sem_wait(info.s_state);
			info.state = DIED;
			sem_post(info.s_state);
			break;
		}
	}
	return (0);
}
void *check_full(void *arg)
{
	t_philo *ph_set;
	int i;
	
	ph_set = (t_philo *)arg;
	if (info.must_eat == -1)
		return (NOERR);
	while (info.state != DIED && info.state != FULL)
	{
		i = 0;
		while (i < info.nbr_of_philo)
		{
			if (ph_set[i].remain > 0)
				i = 0;
			else
				i++;
		}
		sem_wait(info.s_state);
		print_msg(" is FULLED\n", &ph_set[0]);
		info.state = FULL;
		sem_post(info.s_state);
	}
	return (NOERR);
}

void *routine(void *arg)
{
	t_philo *one;
	int i;
	pthread_t death;

	i = 0;
	one = (t_philo *)arg;
	pthread_create(&death, NULL, &check_death, (void *)one);
	pthread_detach(death);
	if (one->idx % 2 == 0)
		usleep(info.t_eat * 2 / 3);
	while (info.state != DIED && info.state != FULL)
	{
		do_eat(one);
		print_msg(" is sleeping\n", one);
		uint64_t target;
		target = get_time() + info.t_sleep;
		while (get_time() < target)
			usleep(50);
		print_msg(" is thinking\n", one);
	}
	return (NOERR);
}
int make_threads(t_philo *ph_set)
{
	int i;
	pthread_t full;

	i = 0;
	while (i < info.nbr_of_philo)
	{
		pthread_create(&ph_set[i].thread, NULL, &routine, &ph_set[i]);
		usleep(50);
		i++;
	}
	pthread_create(&full, NULL, &check_full, ph_set);
	pthread_detach(full);
	i = 0;
	while (i < info.nbr_of_philo)
		pthread_join(ph_set[i++].thread, NULL);
	return (NOERR);
}

int main()
{
	t_philo *ph_set;

	init_info();
	ph_set = init_philo();
	make_threads(ph_set);
	if (info.state == FULL)
		write(1, "FULL\n", 5);
	else if (info.state == DIED)
		write(1, "DIED\n", 5);
}
