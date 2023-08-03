/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_ms_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:02:38 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/01 16:02:01 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers_bonus.h"

time_t	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
