#include "../../include/philosophers_bonus.h"

void	infinite_simulation(char *argv[], int16_t nbr_philos)
{
	t_philo	philos[MAX_PHILOS];

	set_semaphores_infinite(philos, nbr_philos);
	set_philos_infinite(philos, argv, nbr_philos);
	start_simulation(philos, nbr_philos);
}
