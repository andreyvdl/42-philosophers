#include "../include_bonus/philosophers_bonus.h"

static bool	has_died(t_philo philos[])
{
	bool	ret;

	sem_wait(philos->sem_time);
	if (philos->lifetime + philos->last_meal < get_time_ms())
	{
		kill(0, SIGKILL);
		sem_wait(philos->sem_print);
		printf(PHILO_RIP, get_time_ms() - philos->starting, philos->id);
		sem_post(philos->sem_print);
		ret = true;
	}
	else
		ret = false;
	sem_post(philos->sem_time);
}

static void	panopticon(t_philo philos[], int16_t nbr_philos)
{
	int16_t	i;
	int16_t	finished;

	finished = 0;
	while (finished != nbr_philos && nobody_died(philos))
	{
		i = -1;
		finished = 0;
		while (++i < nbr_philos)
		{
			if (has_meals(&philos[i]) == false)
				finished++;
			else if (has_died(&philos[i]))
				break ;
		}
		usleep(100);
	}
}

void	start_simulation(t_philo philos[], int16_t nbr_philos)
{
	pid_t	pid;
	int16_t	i;

	i = -1;
	while (++i < nbr_philos)
	{
		philos[i].starting = get_time_ms();
		philos[i].last_meal = philos[i].starting;
	}
	i = -1;
	while (++i < nbr_philos)
	{
		pid = fork();
		if (pid == 0)
			routine(&philos[i]);
	}
	usleep(100);
	panopticon(philos, nbr_philos);
	close_semaphores(philos);
	free_semaphores(philos);
	unlink_semaphores();
	exit(0);
}
