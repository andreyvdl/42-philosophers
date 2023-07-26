#include "../../include/philosophers.h"

void	infinite_simulation(char *argv[], uint16_t nbr_philos)
{
	t_philo	philos[MAX_PHILOS];

	set_basic_infinite(philos, argv, nbr_philos);
	if (try_set_mutex(philos, nbr_of_philos))
	{

	}
}
