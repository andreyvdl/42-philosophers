#include "../../include_bonus/philosophers_bonus.h"

void	eat(t_philo *philo)
{
	philo->last_meal = get_time_ms();
	print_action(philo, PHILO_EAT);
	while (get_time_ms() < philo->last_meal + philo->lunch_time)
	{
		usleep(100);
		am_i_alive(philo);
	}
	--philo->meals;
}
