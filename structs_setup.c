#include "philo.h"

int	ft_struct_setup(t_philo *phil)
{
	sem_unlink("/forks");
	phil->sem_f = sem_open("/forks", O_CREAT, 0666, phil->nm_phil);
	if (phil->sem_f == SEM_FAILED)
		return (-1);
	sem_unlink("/prints");
	phil->sem_p = sem_open("/prints", O_CREAT, 0666, 1);
	phil->dead = 1;
	return (0);
}

int	ft_struct_phils_setup(t_philo **phil, t_tr_philos *tr_phil)
{
	int	k;

	k = -1;
	while (++k < (*phil)->nm_phil)
	{
		tr_phil[k].eat_times = (*phil)->all_need_eat;
		tr_phil[k].phil = *phil;
	}
	return (0);
}

int	ft_execute(t_philo *phil, t_tr_philos *tr_phil)
{
	phil->count = -1;
	phil->time_start = ft_get_time();
	phil->pid = (pid_t *)malloc(sizeof(pid_t) * phil->nm_phil + 1);
	if (phil->pid == NULL)
		return (-1);
	phil->time_start = ft_get_time();
	while (++phil->count < phil->nm_phil)
	{
		tr_phil[phil->count].die_start = ft_get_time();
		tr_phil[phil->count].index = phil->count;
		ft_fork_start(&tr_phil[phil->count], phil->count);
	}
	return (1);
}
