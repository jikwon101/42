#include "one.h"

void my_time(long now, long target)
{
	uint64_t tmp;

	tmp = now + target;
	while (get_time() <  tmp)
		usleep(10);
	return ;
}
void do_eat(t_philo *one)
{
	uint64_t t_target;
	uint64_t temp;

	pthread_mutex_lock(one->left_fork);
	pthread_mutex_lock(one->right_fork);
	print_msg_thread(" has taken a fork\n",one);
	print_msg_thread(" is eating\n", one);
	one->last_meal = get_time();
	t_target = one->last_meal + t_eat;         
	while (get_time() < t_target)
		usleep(50); //100us = 0.1ms
	//my_time(one->last_meal, t_eat);
	pthread_mutex_unlock(one->right_fork);
	pthread_mutex_unlock(one->left_fork);
	if (one->remain > 0)
		one->remain -= 1;
}

void *routine(void *arg)
{
	t_philo *one;
	pthread_t died;
	pthread_t full;
	uint64_t t_target;

	one = (t_philo *)arg;
	pthread_create(&died, NULL, &check_death, one);
	pthread_detach(died);
	one->idx % 2 ? 0 : usleep(t_eat * CF - 1.5 * one->idx); //usleep = us . t_eat = ms
	while (state != DIED && state != FULL)
	{
		do_eat(one);
		print_msg_thread(" is sleeping\n", one);
		t_target = get_time() + t_sleep;
		while (get_time() < t_target)
			usleep(50);
		print_msg_thread(" is thinking\n", one);
	}
	return (NOERR);
}

int main(int ac, char **av)
{
	t_philo *ph_set;
	
	if (init_state(ac, av) == ERR)
		return (ERR);
	if (init_mutex() == ERR)
		return (ERR);
	ph_set = init_threads();
	make_threads(ph_set);
	finish_threads(ph_set);
	return (0);
}
