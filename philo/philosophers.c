/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:26:04 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/22 11:14:09 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

/*
todo: get argv as input - nbr_philos lifetime launch_time amimir [meals]
todo: learn about pthreads and mutex in C
todo: read pdf better
todo: learn basic math to convert time
!: time_t is a signed long int
?: optimization
*/

static void	select_simulation(int argc, char *argv[])
{
	if (argc == 5)
		inifinite_sim(argv);
	else
		finite_sim(argv);
}

int	main(int argc, char *argv[])
{
	if (argc > 4 && argc < 7)
		select_simulation(argc, argv + 1);
	else
	{
		write(STDERR_FILENO, ERR_NBR_ARGS, sizeof(ERR_NBR_ARGS));
		write(STDERR_FILENO, EXEMPLE_INPUT, sizeof(EXEMPLE_INPUT));
		exit(22);
	}
	exit(0);
}
