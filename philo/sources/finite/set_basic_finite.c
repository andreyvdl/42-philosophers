/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_basic_finite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:01:38 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/11 12:30:01 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	set_basic_finite(t_philo philos[], char *argv[], int16_t nbr_philos)
{
	ssize_t	aux;
	int16_t	i;

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
