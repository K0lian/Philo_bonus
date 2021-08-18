#include "philo.h"

void	ft_sem_printf(t_tr_philos *tr_phil, char *s)
{
	sem_wait(tr_phil->phil->sem_p);
	if (tr_phil->phil->dead == 1)
		printf("%ld %d %s", ft_get_time() - \
		tr_phil->phil->time_start, tr_phil->index + 1, s);
	sem_post(tr_phil->phil->sem_p);
}

void	*ft_dead(void *tr_phil0)
{
	t_tr_philos	*tr_phil;

	tr_phil = (t_tr_philos *)tr_phil0;
	while (1)
	{
		usleep(50);
		if (!tr_phil->phil->all_need_eat)
			return (NULL);
		if ((int)(ft_get_time() - tr_phil->die_start) > \
		tr_phil->phil->tme_die)
		{
			sem_wait(tr_phil->phil->sem_p);
			printf("%ld %d is dead\n", ft_get_time() - \
		tr_phil->phil->time_start, tr_phil->index + 1);
			tr_phil->phil->dead = -100000000;
			exit (1);
		}
	}
}

void	ft_eating(t_tr_philos *tr_phil)
{
	sem_wait(tr_phil->phil->sem_f);
	ft_sem_printf(tr_phil, "has taken a fork\n");
	sem_wait(tr_phil->phil->sem_f);
	ft_sem_printf(tr_phil, "has taken a fork\n");
	ft_sem_printf(tr_phil, "is eating\n");
	tr_phil->die_start = ft_get_time();
	usleep_modified(tr_phil->phil->tme_eat);
	sem_post(tr_phil->phil->sem_f);
	sem_post(tr_phil->phil->sem_f);
}

void	ft_waiting(t_tr_philos *tr_phil)
{
	int	j;
	int	status;

	j = -1;
	while (++j < tr_phil->phil->nm_phil)
		waitpid(tr_phil->phil->pid[j], &status, 0);
}

void	ft_fork_start(t_tr_philos *tr_phil, int i)
{
	pthread_t	kil;

	tr_phil->phil->pid[i] = fork();
	if (tr_phil->phil->pid[i] < 0)
	{
		write(2, "bad fork\n", 9);
		exit(0);
	}
	if (tr_phil->phil->pid[i] == 0)
	{
		if (i % 2)
			usleep_modified(10);
		pthread_create(&kil, NULL, ft_dead, (void *)tr_phil);
		while (1)
			ft_eating(tr_phil);
		exit(0);
	}
	if (i == tr_phil->phil->nm_phil - 1)
		ft_waiting(tr_phil);
}
