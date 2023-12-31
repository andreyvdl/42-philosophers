/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:40:58 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/11 12:40:58 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/philosophers_bonus.h"

static void	eat(t_philo *philo)
{
	philo->last_meal = get_time_ms();
	print_action(philo, PHILO_EAT);
	am_i_alive(philo);
	while (get_time_ms() < philo->last_meal + philo->lunch_time)
	{
		usleep(100);
		am_i_alive(philo);
	}
	--philo->meals;
}

static void	snooze(t_philo *philo)
{
	time_t	aux;

	aux = get_time_ms();
	print_action(philo, PHILO_SLEEP);
	am_i_alive(philo);
	while (get_time_ms() < aux + philo->snooze_time)
	{
		usleep(100);
		am_i_alive(philo);
	}
}

static void	think(t_philo *philo)
{
	print_action(philo, PHILO_THINK);
	am_i_alive(philo);
	usleep(1000);
}

void	routine(t_philo *philo)
{
	am_i_alive(philo);
	if (philo->id % 2 == 0)
		think(philo);
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
