#include "../include/philosophers_bonus.h"

void	unlink_semaphores(void)
{
	sem_unlink("/fork");
	sem_unlink("/printf");
	sem_unlink("/getter");
	sem_unlink("/time");
	sem_unlink("/meal");
}
