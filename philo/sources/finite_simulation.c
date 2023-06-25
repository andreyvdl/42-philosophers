#include "../philosophers.h"

void	finite_sim(char *argv[])
{
	if (values_are_valid(argv))
		exit(0);
	else
		exit(22);
}
