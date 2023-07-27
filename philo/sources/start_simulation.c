#include "../include/philosophers.h"

static void	panopticon(
	t_philo philos[], uint16_t nbr_philos, pthread_t thread[])
{
	uint16_t	i;
	uint16_t	finished;

	while (nobody_died(philos))
	{
		i = -1;
		finished = 0;
		while (++i < nbr_philos)
		{
			if (he_died(philos))
				set_died(true);
		}
	}
	wait_for_them(thread, nbr_philos);
}

void	start_simulation(t_philo philos[], uint16_t nbr_philos)
{
	pthread_t	thread[MAX_PHILOS];
	uint16_t	i;

	i = -1;
	while (++i < nbr_philos)
		pthread_create(&thread[i], NIL, &routine, (void *)&philos[i]);
	panopticon(philos, nbr_philos, pid);
}
