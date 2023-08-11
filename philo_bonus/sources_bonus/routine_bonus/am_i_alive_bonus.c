/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_i_alive_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:40:32 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/11 12:40:37 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/philosophers_bonus.h"

void	am_i_alive(t_philo *philo)
{
	if (get_time_ms() > philo->last_meal + philo->lifetime)
	{
		sem_wait(philo->sem_printf);
		printf(PHILO_RIP, get_time_ms() - philo->starting, philo->id);
		close_semaphores(philo);
		exit(EXIT_FAILURE);
	}
}
