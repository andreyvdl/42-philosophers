#include "../../include/philosophers.h"

void	infinite_simulation(char *argv[], int16_t nbr_philos)
{
	t_philo	philos[MAX_PHILOS];

	set_basic_infinite(philos, argv, nbr_philos);
	set_mutex(philos, nbr_philos);
	start_simulation(philos, nbr_philos);
}
