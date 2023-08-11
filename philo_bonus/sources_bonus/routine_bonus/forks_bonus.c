/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:40:40 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/11 12:40:41 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/philosophers_bonus.h"

static void	wait_your_turn(t_philo *philo)
{
	while (*(int16_t *)philo->sem_fork < 2)
	{
		usleep(500);
		am_i_alive(philo);
	}
}

void	take_forks(t_philo *philo)
{
	wait_your_turn(philo);
	sem_wait(philo->sem_fork);
	print_action(philo, PHILO_FORK);
	sem_wait(philo->sem_fork);
	print_action(philo, PHILO_FORK);
}

void	drop_forks(t_philo *philo)
{
	sem_post(philo->sem_fork);
	sem_post(philo->sem_fork);
}
