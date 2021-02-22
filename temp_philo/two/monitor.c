void print_msg(const char *str, t_philo *one);
void *check_death(void *arg)
{
	t_philo *one;
	uint64_t gap;

	one = (t_philo *)arg;
	while (one->info->state != 1)
	{
		gap = get_time() - one->last_meal;
		if (gap > one->info->t_die)
		{
			print_msg(" is died\n", one);
			sem_wait(one->info->s_state);
			one->info->state = 1;
			sem_post(one->info->s_state);
			break;
		}
	}
	return (0);
}

/*
   void *check_full(void *arg)
{
	t_philo *ph_set;
	int	i;

	i = 0;
	ph_set = (t_philo *)arg;
	while (state != DIED && state != FULL)
	{
		while (i < nbr_ph)
		{
			if (ph_set[i].remain > 0)
				i = 0;
			else
				i++;
		}
		pthread_mutex_lock(&m_state);
		state = FULL;
		pthread_mutex_unlock(&m_state);
	}
	return (NOERR);
}*/
