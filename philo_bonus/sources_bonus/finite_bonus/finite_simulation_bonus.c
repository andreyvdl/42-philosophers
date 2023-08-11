/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finite_simulation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:39:38 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/11 12:39:39 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/philosophers_bonus.h"

void	finite_simulation(char *argv[], int16_t nbr_philos)
{
	t_philo	philos[MAX_PHILOS];

	set_semaphores(philos, nbr_philos);
	set_philos_finite(philos, argv, nbr_philos);
	start_simulation(philos, nbr_philos);
}
