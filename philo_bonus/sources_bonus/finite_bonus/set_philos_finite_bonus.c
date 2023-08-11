/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos_finite_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:39:43 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/11 12:39:44 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/philosophers_bonus.h"

void	set_philos_finite(t_philo philos[], char *argv[], int16_t nbr_philos)
{
	int16_t	i;
	ssize_t	aux;

	aux = ft_atol(*argv);
	i = -1;
	while (++i < nbr_philos)
	{
		philos[i].id = i + 1;
		philos[i].lifetime = aux;
	}
	aux = ft_atol(argv[1]);
	i = -1;
	while (++i < nbr_philos)
		philos[i].lunch_time = aux;
	aux = ft_atol(argv[2]);
	i = -1;
	while (++i < nbr_philos)
		philos[i].snooze_time = aux;
	aux = ft_atol(argv[3]);
	i = -1;
	while (++i < nbr_philos)
		philos[i].meals = aux;
}
