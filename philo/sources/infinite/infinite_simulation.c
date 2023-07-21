#include "../../include/philosophers.h"

void	infinite_sim(char *argv[])
{
	t_philo_pub	philos[MAX_PHILOS];

	if (values_are_valid(argv))
	{
		if (set_philos_infinite(philos, argv++) == false)
			return ;
		set_times_infinite(argv, philos);
		if (set_mutexes_infinite(philos) == false)
			return ;
		start_simulation(philos);
	}
}
