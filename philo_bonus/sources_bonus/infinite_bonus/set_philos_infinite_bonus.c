#include "../../include_bonus/philosophers_bonus.h"

void	set_philos_infinite(t_philo philos[], char *argv[], int16_t nbr_philos)
{
	int16_t	i;
	ssize_t	time;

	time = ft_atol(*argv);
	i = -1;
	while (++i < nbr_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals = -1;
		philos[i].lifetime = time;
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
