#include "../../include_bonus/philosophers_bonus.h"

bool	*get_died(void)
{
	static bool	died = false;

	return (&died);
}
