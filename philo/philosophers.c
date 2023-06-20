/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:26:04 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/20 17:57:16 by adantas-         ###   ########.fr       */
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

// static void	pre_sim(int argc, char *argv[])
// {
// 	if (argc == 5)
// 		inifinite_sim(argv);
// 	else
// 		finite_sim(argv);
// }

int	main(int argc, char *argv[])
{
	if (argc > 4 && argc < 7)
		printf("argv: %s\n", *argv);
		// pre_sim(argc, argv + 1);
	else
	{
		write(STDERR_FILENO, ERR_NBR_ARGS, sizeof(ERR_NBR_ARGS));
		write(STDERR_FILENO, EXEMPLE_INPUT, sizeof(EXEMPLE_INPUT));
		exit(22);
	}
	exit(0);
}
