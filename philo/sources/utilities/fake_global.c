#include "../../include/philosophers.h"

bool	*get_died(void)
{
	static bool	died = false;

	return (&died);
}
