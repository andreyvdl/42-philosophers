/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:01:54 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/31 13:01:57 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

static void	decrease_meals(t_philo *philo)
{
	pthread_mutex_lock(philo->m_meals);
	--philo->meals;
	pthread_mutex_unlock(philo->m_meals);
}

void	eat(t_philo *philo)
{
	update_time(philo);
	print_action(philo, PHILO_EAT);
	usleep(philo->lunch_time * 1000);
	decrease_meals(philo);
}
