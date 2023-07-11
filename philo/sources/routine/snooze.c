#include "../../include/philosophers.h"

static void	print_sleep(t_philo_pub philo[])
{
	pthread_mutex_lock(philo->print_mutex);
	printf(PHILO_SLEEP, get_time_ms() - *(philo->start_time), philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}

static void	check_sleep_death(t_philo_pub philo[])
{
	time_t	diff_to_die;

	diff_to_die = (philo->private.last_meal + *(philo->lifetime))
		- (philo->private.last_meal + *(philo->snooze_time));
	if (diff_to_die <= 0)
	{
		print_sleep(philo);
		usleep((*(philo->snooze_time) - diff_to_die) * 1000);
		memento_mori(philo);
	}
}

void	snooze(t_philo_pub philo[])
{
	check_sleep_death(philo);
	print_sleep(philo);
	usleep(*(philo->snooze_time) * 1000);
	pthread_mutex_lock(philo->state_mutex);
	change_state(philo, E_THINKING);
	pthread_mutex_unlock(philo->state_mutex);
}
