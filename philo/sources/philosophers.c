#include "philosophers.h"

/*
todo: get argv as input - nbr_philos lifetime lunch_time amimir [meals]
* learn about pthreads and mutex in C - on test.c
todo: read pdf better
* learn basic math to convert time - μs to ms is (μs / 1000)
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
