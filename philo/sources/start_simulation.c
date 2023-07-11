#include "philosophers.h"

static void	detach_and_exit(t_philo_pub philos[], pthread_t ids[])
{
	uint8_t	looper;

	looper = -1;
	while (++looper < philos->nbr_of_philos)
		pthread_detach(ids[looper]);
	exit(EXIT_SUCCESS);
}

static void	function_name(t_philo_pub philos[], pthread_t ids[])
{
	uint8_t	looper;

	while (true)
	{
		looper = -1;
		while (++looper < philos->nbr_of_philos)
		{
			pthread_mutex_lock(philos->state_mutex);
			if (philos[looper].private.state == E_DEAD)
			{
				pthread_mutex_unlock(philos->state_mutex);
				detach_and_exit(philos, ids);
			}
			pthread_mutex_unlock(philos->state_mutex);
		}
	}
}

void	start_simulation(t_philo_pub philos[])
{
	time_t		starting_at;
	uint8_t		looper;
	pthread_t	thread_id[MAX_PHILOS];

	looper = -1;
	while (++looper < philos->nbr_of_philos)
		philos[looper].start_time = &starting_at;
	starting_at = get_time_ms();
	looper = -1;
	while (++looper < philos->nbr_of_philos)
		pthread_create(&thread_id[looper], NULL, &routine, &philos[looper]);
	function_name(philos, thread_id);
}
