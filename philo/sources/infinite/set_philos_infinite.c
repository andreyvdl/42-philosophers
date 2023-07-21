#include "../../include/philosophers.h"

static void	set_public_infinite(
	t_philo_pub philos[], int16_t nbr_of_philos, int16_t *table_forks)
{
	int16_t	looper;

	looper = -1;
	while (++looper < nbr_of_philos)
	{
		philos[looper].nbr_of_philos = nbr_of_philos;
		philos[looper].id = looper + 1;
		philos[looper].private.philo_meals = -1;
		philos[looper].private.state = E_EATING;
		philos[looper].table_forks = table_forks;
		++looper;
	}
}

bool	set_philos_infinite(t_philo_pub philos[], char *argv[])
{
	int16_t	nbr_of_philos;
	int16_t	*table_forks;

	table_forks = malloc(sizeof(int16_t));
	if (table_forks == NIL)
	{
		malloc_error();
		return (false);
	}
	nbr_of_philos = ft_atol(*argv);
	*table_forks = nbr_of_philos;
	set_public_infinite(philos, nbr_of_philos, table_forks);
	return (true);
}
