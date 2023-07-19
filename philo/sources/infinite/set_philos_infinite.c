#include "philosophers.h"

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

static void	set_times(char *argv[], t_philo_pub philos[])
{
	uint8_t	looper;
	ssize_t	time_to_die;
	ssize_t	time_to_eat;
	ssize_t	time_to_sleep;

	time_to_die = ft_atol(*argv);
	if (time_to_die < 1 || time_to_die > TIME_MAX)
		value_error(*argv);
	++argv;
	time_to_eat = ft_atol(*argv);
	if (time_to_eat < 0 || time_to_eat > TIME_MAX)
		value_error(*argv);
	++argv;
	time_to_sleep = ft_atol(*argv);
	if (time_to_sleep < 0 || time_to_sleep > TIME_MAX)
		value_error(*argv);
	looper = -1;
	while (++looper < philos->nbr_of_philos)
	{
		philos[looper].lifetime = time_to_die;
		philos[looper].lunch_time = time_to_eat;
		philos[looper].snooze_time = time_to_sleep;
	}
}

void	set_philos_infinite(t_philo_pub philos[], char *argv[])
{
	uint8_t	nbr_of_philos;
	uint8_t	looper;
	uint8_t	*table_forks;

	nbr_of_philos = ft_atol(*argv);
	if (nbr_of_philos > MAX_PHILOS || nbr_of_philos < 1)
		value_error(*argv);
	++argv;
	looper = -1;
	table_forks = malloc(sizeof(uint8_t));
	*table_forks = nbr_of_philos;
	while (++looper < nbr_of_philos)
	{
		philos[looper].nbr_of_philos = nbr_of_philos;
		philos[looper].id = looper + 1;
		philos[looper].private.philo_meals = -1;
		philos[looper].private.philo_forks = 0;
		philos[looper].private.state = E_EATING;
		philos[looper].table_forks = table_forks;
	}
	set_times(argv, philos);
	set_mutexes(philos);
}
