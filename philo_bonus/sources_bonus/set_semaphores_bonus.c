#include "../include_bonus/philosophers_bonus.h"

void	set_semaphores(t_philo philos[], int16_t nbr_philos)
{
	int16_t	i;

	philos->sem_fork = sem_open("/fork", O_CREAT, RNW, nbr_philos);
	philos->sem_printf = sem_open("/printf", O_CREAT, RNW, 1);
	i = 0;
	while (++i < nbr_philos)
	{
		philos[i].sem_fork = philos->sem_fork;
		philos[i].sem_printf = philos->sem_printf;
	}
}
