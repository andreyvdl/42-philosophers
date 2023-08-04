#include "../../include_bonus/philosophers_bonus.h"

static void	update_meal_time(t_philo *philo)
{
	sem_wait(philo->sem_time);
	philo->last_meal = get_time_ms();
	sem_post(philo->sem_time);
}

static void	update_meal_count(t_philo *philo)
{
	sem_wait(philo->sem_meals);
	--philo->meals;
	sem_post(philo->sem_meals);
}

void	eat(t_philo *philo)
{
	update_meal_time(philo);
	print_action(philo, PHILO_EAT);
	usleep(philo->lunch_time * 1000);
	update_meal_count(philo);
}
