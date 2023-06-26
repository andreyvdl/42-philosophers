#include "../philosophers.h"

static void	print_error(char *arg)
{
	write(STDERR_FILENO, ERR_INPUT_WRONG, sizeof(ERR_INPUT_WRONG));
	ft_putstr_fd(arg, STDERR_FILENO);
	write(STDERR_FILENO, CLOSE_ERR_INPUT, sizeof(CLOSE_ERR_INPUT));
	exit(22);
}

static t_test	*set_values(char *argv[])
{
	t_test	test[1];
	ssize_t	user_input;

	user_input = ft_atol(*argv);
	if (user_input < 1)
		print_error(*argv);
	++argv;
	test->nbr_philos = user_input;
	user_input = ft_atol(*argv);
	if (user_input < 0 || user_input > SSIZE_LIMIT)
		print_error(*argv);
	++argv;
	test->lifetime = user_input * 1000;
	user_input = ft_atol(*argv);
	if (user_input < 0 || user_input > SSIZE_LIMIT)
		print_error(*argv);
	++argv;
	test->launch_time = user_input * 1000;
	user_input = ft_atol(*argv);
	if (user_input < 0 || user_input > SSIZE_LIMIT)
		print_error(*argv);
	++argv;
	test->sleep_time = user_input * 1000;
	if (*argv != NIL)
	{
		user_input = ft_atol(*argv);
		if (user_input < 0)
			print_error(*argv);
		test->meals = user_input;
	}
	else
		test->meals = -1;
	return (test);
}

void	infinite_sim(char *argv[])
{
	t_test	*test;

	if (values_are_valid(argv))
	{
		test = set_values(argv);
		printf("You want a simulation with %ld philos, that live for %ldms, "\
		"take %ldms to eat, sleep for %ld and has to take %ld meals\n", \
		test->nbr_philos, test->lifetime, test->launch_time, test->sleep_time, \
		test->meals);
		exit(0);
	}
	else
		exit(22);
}
