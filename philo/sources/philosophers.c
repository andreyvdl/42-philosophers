#include "../include/philosophers.h"

/*
DONE: get argv as input - nbr_philos lifetime lunch_time amimir [meals]
DONE: learn about pthreads and mutex in C - on test.c
DONE: learn basic math to convert time
DONE:	μs to ms is (μs / 1000)
DONE:	sec to ms is (sec * 1000)
DONE:	us->ms + sec->ms is perfect ms
TODO: read pdf better

%: left fork is a pointer to the fork of the next philosopher
!: time_t is a signed long int
?: optimization
*/

static void	make_the_l(ssize_t	t)
{
	printf(PHILO_FORK, 0L, 1);
	usleep(t * 1000);
	printf(PHILO_RIP, t, 1);
}

static void	select_simulation(int argc, char *argv[])
{
	if (values_are_valid(argv))
	{
		if (ft_atol(*argv) > 1)
		{
			if (argc == 4)
				infinite_simulation(argv + 1, ft_atol(*argv));
			else
				(void)argc;
				// finite_sim(argv);
		}
		else
			make_the_l(ft_atol(*(argv + 1)));
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
		select_simulation(argc - 1, argv + 1);
	else
		argc_error();
	return (0);
}
