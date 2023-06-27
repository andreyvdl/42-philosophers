#include "../philosophers.h"



void	infinite_sim(char *argv[])
{
	t_test	*test;

	if (values_are_valid(argv))
	{
		test = malloc(sizeof(t_test));
		if (test == NIL)
			malloc_error();
		set_values(argv, test);
		printf("%ld, %ld, %ld, %ld, %ld\n", test->nbr_philos, test->lifetime,
			test->launch_time, test->sleep_time, test->meals);
		exit(0);
	}
	else
		exit(22);
}
