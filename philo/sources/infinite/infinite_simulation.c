#include "../../include/philosophers.h"

void	infinite_sim(char *argv[])
{
	t_philo_pub	philos[MAX_PHILOS];

	if (values_are_valid(argv))
	{
		
		set_values(argv, philos);
		exit(0);
	}
	else
		exit(22);
}
