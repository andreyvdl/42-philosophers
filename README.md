<div align="center">
	<img src="https://github.com/gawbsouza/42-pdh/blob/main/dark/philosophers_dark.svg"><br>
	<a href="https://github.com/gawbsouza/42-pdh"><img src="https://github.com/gawbsouza/42-pdh/blob/main/badge/42pdh_badge.svg"></a>
</div>

---
<table>
	<tr>
		<td style="font-weight:bold">Program Name</td>
		<td style="font-weight:bold">Files</td>
		<td style="font-weight:bold">Makefile</td>
		<td style="font-weight:bold">Functions</td>
		<td style="font-weight:bold">Score</td>
	</tr>
	<tr>
		<td>
			philo<br>
			philo_bonus
		</td>
		<td>
			Makefile, *.h, *.c
		</td>
		<td>
			NAME, all, clean, fclean, re
		</td>
		<td>
			memset, printf, malloc, free, write, usleep, gettimeofday,
			pthread_create, pthread_detach, pthread_join, pthread_mutex_init,
			pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock<br>
			fork, kill, exit, waitpid, sem_open, sem_close, sem_post, sem_wait,
			sem_unlink
		</td>
		<td>0/100</td>
	</tr>
</table>

## Objective

> Eat, Sleep, Spaghetti, repeat. This project is about learning how threads work
> by precisely timing a group of philosophers on when to pick up forks and eat
> spaghetti without dying from hunger.

## Execution

On the philo folder
```sh
$ make
$ ./philo nbr_of_philosophers time_to_die time_to_eat time_to_sleep [nbr_of_meals]
```

On the philo_bonus folder
```sh
$ make bonus
$ ./philo_bonus nbr_of_philosophers time_to_die time_to_eat time_to_sleep [nbr_of_meals]
```
