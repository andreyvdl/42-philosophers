#include "../../include/philosophers.h"

static bool	free_fork_and_return(t_philo_pub philos[], bool ret)
{
	free(philos->table_forks);
	return (ret);
}

static bool	put_time()
{
	int16_t	looper;

	looper = -1;
	while (++looper < philos->nbr_of_philos)
	{
		philos[looper].lifetime = time_to_die;
		philos[looper].lunch_time = time_to_eat;
		philos[looper].snooze_time = time_to_sleep;
	}
}

bool	set_times_infinite(char *argv[], t_philo_pub philos[])
{
	ssize_t	time_to_die;
	ssize_t	time_to_eat;
	ssize_t	time_to_sleep;

	time_to_die = ft_atol(*argv++);
	if (time_to_die < 1 || time_to_die > TIME_MAX)
	{
		value_error(*(--argv));
		return (free_fork_and_return(philos, false));
	}
	time_to_eat = ft_atol(*argv++);
	if (time_to_eat < 0 || time_to_eat > TIME_MAX)
	{
		value_error(*(--argv));
		return (free_fork_and_return(philos, false));
	}
	time_to_sleep = ft_atol(*argv++);
	if (time_to_sleep < 0 || time_to_sleep > TIME_MAX)
	{
		value_error(*(--argv));
		return (free_fork_and_return(philos, false));
	}
	put_time(philos, time_to_die, time_to_eat, time_to_sleep);
	
}
