#include "../../include/philosophers.h"

void	set_basic_infinite(t_philo philos[], char *argv[], int16_t nbr_philos)
{
	ssize_t	time;
	int16_t	i;

	time = ft_atol(*argv);
	i = -1;
	while (++i < nbr_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals = -1;
		philos[i].lifetime = time;
		philos[i].starting = philos->starting;
	}
	time = ft_atol(argv[1]);
	i = -1;
	while (++i < nbr_philos)
		philos[i].lunch_time = time;
	time = ft_atol(argv[2]);
	i = -1;
	while (++i < nbr_philos)
		philos[i].snooze_time = time;
}
