#include "../../include/philosophers.h"

static void	set_times(char **argv[], t_philo_pub philos[])
{
	uint8_t	looper;
	ssize_t	time_to_die;
	ssize_t	time_to_eat;
	ssize_t	time_to_sleep;

	looper = -1;
	while (++looper < philos->nbr_of_philos)
	{
		philos[looper].lifetime = &time_to_die;
		philos[looper].launch_time = &time_to_eat;
		philos[looper].snooze_time = &time_to_sleep;
	}
	time_to_die = ft_atol(**argv);
	if (time_to_die < 1 || time_to_die > TIME_MAX)
		value_error(**argv);
	++(*argv);
	time_to_eat = ft_atol(**argv);
	if (time_to_eat < 0 || time_to_eat > TIME_MAX)
		value_error(**argv);
	++(*argv);
	time_to_sleep = ft_atol(**argv);
	if (time_to_sleep < 0 || time_to_sleep > TIME_MAX)
		value_error(**argv);
}

static void	set_philos(t_philo_pub philos[], char **argv[])
{
	uint8_t	nbr_of_philos;
	uint8_t	looper;

	nbr_of_philos = ft_atol(**argv);
	if (nbr_of_philos > MAX_PHILOS || nbr_of_philos < 1)
		value_error(**argv);
	++(*argv);
	looper = -1;
	while (++looper < nbr_of_philos)
	{
		philos[looper].nbr_of_philos = nbr_of_philos;
		philos[looper].id = looper + 1;
	}
	set_times(argv, philos);
}

void	infinite_sim(char *argv[])
{
	t_philo_pub	philos[MAX_PHILOS];

	if (values_are_valid(argv))
	{
		set_philos(philos, &argv);
		printf("philos %i, lifetime %ld, launch_time %ld, snooze_time %ld", philos->nbr_of_philos, *philos->lifetime, *philos->launch_time, *philos->snooze_time);
		exit(0);
	}
	else
		exit(22);
}
