#include "../../include/philosophers.h"

void	set_times_infinite(char *argv[], t_philo_pub philos[])
{
	ssize_t	time_to_die;
	ssize_t	time_to_eat;
	ssize_t	time_to_sleep;
	int16_t	looper;

	time_to_die = ft_atol(*argv++);
	time_to_eat = ft_atol(*argv++);
	time_to_sleep = ft_atol(*argv++);
	looper = -1;
	while (++looper < philos->nbr_of_philos)
	{
		philos[looper].lifetime = time_to_die;
		philos[looper].lunch_time = time_to_eat;
		philos[looper].snooze_time = time_to_sleep;
	}
}
