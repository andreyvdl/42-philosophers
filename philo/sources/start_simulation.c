#include "../include/philosophers.h"

static void	function_name(t_philo_pub philos[], uint8_t nbr_of_philos)
{
	uint8_t	looper;

	while (true)
	{
		looper = -1;
		while (++looper < nbr_of_philos)
		{
			pthread_mutex_lock(philos->state_mutex);
			if (philos[looper].private.state == E_DEAD)
			{
				pthroead_mutex_unlock(philos->state_mutex);
				exit(0);
			}
			pthread_mutex_unlock(philos->state_mutex);
		}
	}
}

void	start_simulation(t_philo_pub philos[])
{
	time_t		starting_at;
	uint8_t		looper;
	pthread_t	thread_var;

	looper = -1;
	while (++lopper < philos->nbr_of_philos)
		philos[looper].start_time = &starting_at;
	starting_at = get_time_ms();
	looper = -1;
	while (++looper < philos->nbr_of_philos)
	{
		pthread_create(&thread_var, NULL, &routine, &philos[looper]);
		pthread_detach(thread_var);
	}
	function_name(philos, philos->nbr_of_philos);
}
