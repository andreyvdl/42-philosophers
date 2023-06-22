#include "./philosophers.h"

/*
* pthread_create cria uma thread e a manda para a função;
* pthread_detach não espera pela thread, a thread q a invocou continua,
*	isso pode parecer ruim mas na verdade isso permite ao PC liberar recursos
*	automaticamente;
* pthread_join é tipo o waitpid;
todo: learn pthread_mutex_init;
todo: learn pthread_mutex_destroy;
todo: learn pthread_mutex_lock;
todo: learn pthread_mutex_unlock;
*/

/* create e join
void	*teste(void *arg)
{
	printf("teste\n");
	return (arg);
}

int	main(void)
{
	pthread_t	thread_id;

	pthread_create(&thread_id, NULL, teste, NULL);
	pthread_join(thread_id, NULL);
	return (0);
}
*/

/* thread id
void	*teste(void *arg)
{
	printf("%d\n", ((int *)arg)[0]);
	return (NULL);
}

int	main(void)
{
	pthread_t	thread_id;
	int			i;

	i = -1;
	while (++i < 3)
		pthread_create(&thread_id, NULL, teste, (void *)&thread_id);
	pthread_exit(NULL);
	return (0);
}
*/

void	*teste(void *arg)
{
	printf("%d\n", ((int *)arg)[0]);
	return (NULL);
}

int	main(void)
{
	pthread_t	thread_id;
	int			i;

	i = -1;
	while (++i < 3)
	{
		pthread_create(&thread_id, NULL, teste, (void *)&thread_id);
		pthread_detach(thread_id);
	}
	while (1)
	{
		if (i == 10)
			break ;
		usleep(1000);
		i++;
	}
	return (0);
}
