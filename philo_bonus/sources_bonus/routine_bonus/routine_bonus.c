#include "../../include_bonus/philosophers_bonus.h"

static void	snooze(t_philo *philo)
{
	time_t	aux;

	aux = get_time_ms();
	print_action(philo, PHILO_SLEEP);
	while (get_time_ms() < aux + philo->snooze_time)
	{
		usleep(100);
		am_i_alive(philo);
	}
}

static void	think(t_philo *philo)
{
	print_action(philo, PHILO_THINK);
	usleep(100);
	am_i_alive(philo);
	usleep(100);
	am_i_alive(philo);
	usleep(100);
}

void	routine(t_philo *philo)
{
	am_i_alive(philo);
	if (philo->id % 2 == 1)
		usleep(1000);
	am_i_alive(philo);
	while (philo->meals != 0)
	{
		take_forks(philo);
		am_i_alive(philo);
		eat(philo);
		drop_forks(philo);
		am_i_alive(philo);
		snooze(philo);
		think(philo);
		am_i_alive(philo);
	}
	close_semaphores(philo);
	exit(EXIT_SUCCESS);
}
