#include "../../include/philosophers.h"
#include <stdbool.h>
#include <stdlib.h>

static void	set_mutexes(t_philo_pub philos[])
{
	uint8_t		looper;

	philos->print_mutex = malloc(sizeof(pthread_mutex_t));

	philos->state_mutex = malloc(sizeof(pthread_mutex_t));
	philos->forks_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philos->print_mutex, NULL);
	pthread_mutex_init(philos->state_mutex, NULL);
	pthread_mutex_init(philos->forks_mutex, NULL);
	looper = 0;
	while (++looper < philos->nbr_of_philos)
	{
		philos[looper].print_mutex = philos->print_mutex;
		philos[looper].state_mutex = philos->state_mutex;
		philos[looper].forks_mutex = philos->forks_mutex;
	}
}



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

	nbr_of_philos = ft_atol(*argv);
	if (nbr_of_philos > MAX_PHILOS || nbr_of_philos < 1)
	{
		value_error(*argv);
		return (false);
	}
	++argv;
	table_forks = malloc(sizeof(int16_t));
	if (table_forks == NIL)
	{
		malloc_error();
		return (false);
	}
	*table_forks = nbr_of_philos;
	set_public_infinite(philos, nbr_of_philos, table_forks);
	return (true);
}
