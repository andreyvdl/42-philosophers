/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:40:50 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/11 12:40:50 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/philosophers_bonus.h"

void	print_action(t_philo *philo, char *str)
{
	sem_wait(philo->sem_printf);
	printf(str, get_time_ms() - philo->starting, philo->id);
	sem_post(philo->sem_printf);
}
