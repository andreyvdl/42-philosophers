#include "philosophers.h"

static void	set_mutexes(t_philo_pub philos[])
{
	t_pth_mutex	print;
	t_pth_mutex	state;
	t_pth_mutex	fork;
	uint8_t		looper;

	print = (t_pth_mutex)PTHREAD_MUTEX_INITIALIZER;
	state = (t_pth_mutex)PTHREAD_MUTEX_INITIALIZER;
	fork = (t_pth_mutex)PTHREAD_MUTEX_INITIALIZER;
	looper = -1;
	while (++looper < philos->nbr_of_philos)
	{
		philos[looper].print_mutex = &print;
		philos[looper].state_mutex = &state;
		philos[looper].forks_mutex = &fork;
	}
}

static void	set_times(char *argv[], t_philo_pub philos[])
{
	uint8_t	looper;
	ssize_t	time_to_die;
	ssize_t	time_to_eat;
	ssize_t	time_to_sleep;

	looper = -1;
	while (++looper < philos->nbr_of_philos)
	{
		philos[looper].lifetime = &time_to_die;
		philos[looper].lunch_time = &time_to_eat;
		philos[looper].snooze_time = &time_to_sleep;
	}
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
}

void	set_philos_infinite(t_philo_pub philos[], char *argv[])
{
	uint8_t	nbr_of_philos;
	uint8_t	looper;

	nbr_of_philos = ft_atol(*argv);
	if (nbr_of_philos > MAX_PHILOS || nbr_of_philos < 1)
		value_error(*argv);
	++argv;
	looper = -1;
	while (++looper < nbr_of_philos)
	{
		philos[looper].nbr_of_philos = nbr_of_philos;
		philos[looper].id = looper + 1;
		philos[looper].private.philo_meals = -1;
		philos[looper].private.philo_forks = 0;
		philos[looper].private.state = E_EATING;
		philos[looper].table_forks = &nbr_of_philos;
	}
	set_times(argv, philos);
	set_mutexes(philos);
}
