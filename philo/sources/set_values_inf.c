#include "../philosophers.h"

static void	fixed_values(t_test *test, char *arg)
{
	ssize_t	user_input;

	user_input = ft_atol(arg);
	if (user_input < 1 || user_input > 200)
		value_error(arg, test);
	test->nbr_philos = user_input;
	test->meals = -1;
}

static void	time_values(t_test *test, char *argv[])
{
	ssize_t	user_input;

	user_input = ft_atol(*argv);
	if (user_input < 0)
		value_error(*argv, test);
	test->lifetime = user_input;
	++argv;
	user_input = ft_atol(*argv);
	if (user_input < 0)
		value_error(*argv, test);
	test->launch_time = user_input;
	++argv;
	user_input = ft_atol(*argv);
	if (user_input < 0)
		value_error(*argv, test);
	test->sleep_time = user_input;
}

void	set_values(char *argv[], t_test *test)
{
	fixed_values(test, *argv++);
	time_values(test, argv);
}
