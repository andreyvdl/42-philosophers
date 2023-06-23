#include "./philosophers.h"

/* explicação
* pthread_create: cria uma thread e a manda para a função;

* pthread_detach:
*	não espera pela thread, a thread q a invocou continua, isso pode parecer
*	ruim mas na verdade isso permite ao PC liberar recursos automaticamente;

* pthread_join:
*	é tipo o waitpid;

* pthread_mutex_init:
*	inicia ou destroy uma mutex, pode ser substituida pela macro 
*	PTHREAD_MUTEX_INITIALIZER;

* pthread_mutex_destroy:
*	destroi uma mutex, é útil para liberar recursos (não especificamente 
*	memória);

* pthread_mutex_lock:
*	trava a mutex, qualquer outra thread que tente travar vai ficar em espera 
*	para que o recurso seja liberado;

* pthread_mutex_unlock:
*	destrava a mutex, qualquer outra thread que tente usar recurso vai 
*	conseguir;

* gettimeofday:
*	guarda segundos e microsegundos dentro de uma struct chamada timeval, 
*	o tempo é baseado em 01/jan/1970 00:00:00 UTC;
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

/* mutex
typedef struct s_tester {
	pthread_mutex_t	mutex;
	unsigned int	garfos;
}	t_tester;

void	*teste(void *arg)
{
	t_tester	*tester;
	static int	id = 0;

	tester = (t_tester *)arg;
	pthread_mutex_lock(&tester->mutex);
	printf("sou o philo %d e vejo %u garfos\n", id++, tester->garfos);
	tester->garfos += 2;
	pthread_mutex_unlock(&tester->mutex);
	return (NULL);
}

int	main(void)
{
	pthread_t	thread_id[3];
	t_tester	tester;

	tester = (t_tester){PTHREAD_MUTEX_INITIALIZER, 0};
	for (int i = 0; i < 3; i++)
		pthread_create(&thread_id[i], NULL, teste, (void *)&tester);
	for (int i = 0; i < 3; i++)
		pthread_join(thread_id[i], NULL);
	for (int i = 0; i < 3; i++)
		pthread_mutex_destroy(&tester.mutex);
	printf("eu vejo %u garfos\n", tester.garfos);
	return (0);
}
*/

/* gettimeofday
int	main(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("%ld %ld\n", time.tv_sec, time.tv_usec);
	return (0);
}
*/
