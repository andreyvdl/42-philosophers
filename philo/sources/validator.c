#include "../philosophers.h"

static bool	bigger_than_max(char *arg)
{
	size_t	index;

	index = 0;
	while (SIZE_MAX_STR[index] != '\0')
	{
		if (*arg > SIZE_MAX_STR[index])
			return (true);
		else if (*arg < SIZE_MAX_STR[index])
			break ;
		++index;
		++arg;
	}
	return (false);
}

static bool	number_too_big(char **arg)
{
	size_t	size;

	size = 0;
	if (**arg < '0' || **arg > '9')
		return (true);
	while ((*arg)[size] >= '0' && (*arg)[size] <= '9')
		++size;
	if (size > SIZE_MAX_LEN)
		return (true);
	else if (size == SIZE_MAX_LEN && bigger_than_max(*arg))
		return (true);
	while (**arg >= '0' && **arg <= '9')
		++(*arg);
	return (false);
}

static bool	found_something_wrong(char *arg)
{
	while (*arg != '\0')
	{
		while (*arg == ' ' || *arg == '\t')
			++arg;
		if (*arg == '-')
			return (true);
		else if (*arg == '+')
			++arg;
		if (number_too_big(&arg))
			return (true);
		if (*arg != '\0' && *arg != ' ' && *arg != '\t')
			return (true);
		while (*arg == ' ' || *arg == '\t')
			++arg;
		if (*arg != '\0')
			return (true);
	}
	return (false);
}

bool	values_are_valid(char *argv[])
{
	while (*argv != NIL)
	{
		if (found_something_wrong(*argv))
		{
			write(STDERR_FILENO, ERR_INPUT_WRONG, sizeof(ERR_INPUT_WRONG));
			ft_putstr_fd(*argv, STDERR_FILENO);
			write(STDERR_FILENO, CLOSE_ERR_INPUT, sizeof(CLOSE_ERR_INPUT));
			return (false);
		}
		++argv;
	}
	return (true);
}
