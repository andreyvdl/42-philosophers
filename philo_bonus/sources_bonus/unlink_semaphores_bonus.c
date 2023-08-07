#include "../include_bonus/philosophers_bonus.h"

void	unlink_semaphores(void)
{
	sem_unlink("/fork");
	sem_unlink("/printf");
}
