#include "../philosophers.h"

static void	fixed_values(t_test *test, char *arg)
{
	ssize_t	user_input;

	user_input = ft_atol(arg);
	if (user_input < 1)
		value_error(arg, test);
	test->nbr_philos = user_input;
	test->meals = -1;
}

static void	time_values(t_test *test, char *argv[])
{
	ssize_t	user_input;

	user_input = ft_atol(*argv);
	if (user_input < 0 || user_input > SSIZE_LIMIT)
		value_error(*argv, test);
	test->lifetime = user_input * ONE_MS;
	++argv;
	user_input = ft_atol(*argv);
	if (user_input < 0 || user_input > SSIZE_LIMIT)
		value_error(*argv, test);
	test->launch_time = user_input * ONE_MS;
	++argv;
	user_input = ft_atol(*argv);
	if (user_input < 0 || user_input > SSIZE_LIMIT)
		value_error(*argv, test);
	test->sleep_time = user_input * ONE_MS;
}

static void	set_values(char *argv[], t_test *test)
{
	fixed_values(test, *argv++);
	time_values(test, argv);
}

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
