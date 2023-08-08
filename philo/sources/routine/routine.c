/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:02:07 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/08 12:54:03 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(500);
	while (has_meals(philo) && nobody_died(philo))
	{
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		snooze(philo);
		think(philo);
	}
	return (NIL);
}
