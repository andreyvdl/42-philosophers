#include "philosophers.h"

/*
DONE: get argv as input - nbr_philos lifetime lunch_time amimir [meals]
DONE: learn about pthreads and mutex in C - on test.c
DONE: learn basic math to convert time
DONE:	μs to ms is (μs / 1000)
DONE:	sec to ms is (sec * 1000)
DONE:	us->ms + sec->ms is perfect ms
TODO: read pdf better

%: make a bool for the forks , if taken is false, else true
%: left fork is a pointer to the fork of the next philosopher
!: time_t is a signed long int
?: optimization
*/

static void	select_simulation(int argc, char *argv[])
{
	if (argc == 4)
		infinite_sim(argv);
	else
		(void)argc;
		// finite_sim(argv);
}

int	main(int argc, char *argv[])
{
	--argc;
	if (argc > 3 && argc < 6)
		select_simulation(argc, argv + 1);
	else
		argc_error();
	exit(0);
}
