#include "../include_bonus/philosophers_bonus.h"

static void	kill_philos(t_philo philos[])
{
	sem_wait(philos->sem_getter);
	*get_died() = true;
	sem_post(philos->sem_getter);
}

static bool	has_died(t_philo philos[], int16_t nbr_philos)
{
	bool	ret;

	sem_wait(philos->sem_time);
	if (philos->lifetime + philos->last_meal < get_time_ms())
	{
		kill_philos(philos, nbr_philos);
		sem_wait(philos->sem_printf);
		printf(PHILO_RIP, get_time_ms() - philos->starting, philos->id);
		sem_post(philos->sem_printf);
		ret = true;
	}
	else
		ret = false;
	sem_post(philos->sem_time);
	return (ret);
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
			else if (has_died(&philos[i], nbr_philos))
				break ;
		}
		usleep(100);
	}
}

void	start_simulation(t_philo philos[], int16_t nbr_philos)
{
	pid_t	pids[MAX_PHILOS];
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
		pids[i] = fork();
		if (pids[i] == 0)
			routine(&philos[i]);
	}
	usleep(100);
	panopticon(philos, nbr_philos, pids);
	close_semaphores(philos);
	free_semaphores(philos);
	unlink_semaphores();
	exit(0);
}
