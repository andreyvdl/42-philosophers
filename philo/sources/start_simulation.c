#include "../include/philosophers.h"

void	start_simulation(t_philo philos[], uint16_t nbr_philos)
{
	pthread_t	thread[MAX_PHILOS];
	uint16_t	i;

	i = -1;
	*philos->starting = get_time_ms();
	while (++i < nbr_philos)
		pthread_create(&thread[i], NIL, &routine, (void *)&philos[i]);
	panopticon(philos, nbr_philos, pid);
}
