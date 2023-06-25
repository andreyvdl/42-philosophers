#include "../philosophers.h"

void	infinite_sim(char *argv[])
{
	if (values_are_valid(argv))
		exit(0);
	else
		exit(22);
}
