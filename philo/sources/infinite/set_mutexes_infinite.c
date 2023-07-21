#include "../../include/philosophers.h"

static bool	free_and_return(t_philo_pub philos[], int n, bool ret)
{
	if (n == 1)
		free(philos->print_mutex);
	else if (n == 2)
	{
		free(philos->print_mutex);
		free(philos->state_mutex);
	}
	else if (n == 3)
	{
		free(philos->print_mutex);
		free(philos->state_mutex);
		free(philos->forks_mutex);
	}
	free(philos->table_forks);
	return (ret);
}

static bool	init_mutexes_infinite(t_philo_pub philos[])
{
	if (pthread_mutex_init(philos->print_mutex, NULL) != 0)
	{
		mutex_error();
		return (false);
	}
	if (pthread_mutex_init(philos->state_mutex, NULL) != 0)
	{
		mutex_error();
		return (false);
	}
	if (pthread_mutex_init(philos->forks_mutex, NULL) != 0)
	{
		mutex_error();
		return (false);
	}
	return (true);
}

bool	set_mutexes(t_philo_pub philos[])
{
	philos->print_mutex = malloc(sizeof(pthread_mutex_t));
	if (philos->print_mutex == NIL)
	{
		malloc_error();
		return (free_and_return(philos, 0, false));
	}
	philos->state_mutex = malloc(sizeof(pthread_mutex_t));
	if (philos->state_mutex == NIL)
	{
		malloc_error();
		return (free_and_return(philos, 1, false));
	}
	philos->forks_mutex = malloc(sizeof(pthread_mutex_t));
	if (philos->forks_mutex == NIL)
	{
		malloc_error();
		return (free_and_return(philos, 2, false));
	}
	if (init_mutexes_infinite(philos) == false)
		return (free_and_return(philos, 3, false));
	pass_to_all_philos(philos);
	return (true);
}
