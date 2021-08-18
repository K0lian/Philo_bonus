#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philo
{
	int				nm_phil;
	long			tme_die;
	int				tme_eat;
	int				tme_slp;
	int				all_need_eat;
	int				count;
	int				dead;
	unsigned long	time_start;
	pid_t			*pid;
	sem_t			*sem_f;
	sem_t			*sem_p;
}	t_philo;

typedef struct s_philos
{
	t_philo			*phil;
	int				eat_times;
	int				index;
	unsigned long	die_start;
	int				dead_status;
	pthread_t		thread;
}					t_tr_philos;

int				ft_isdigit(int c);
unsigned long	ft_get_time(void);
int				ft_atoi(const char *nptr);
int				ft_struct_setup(t_philo *phil);
int				ft_struct_phils_setup(t_philo **phil, t_tr_philos *tr_phil);
int				ft_execute(t_philo *phil, t_tr_philos *tr_phil);
void			*ft_thread_execute(void *phil0);
void			ft_mut_fork(t_tr_philos *tr_phil);
void			ft_sleep(t_tr_philos *tr_phil);
void			usleep_modified(unsigned long time);
void			ft_free(t_philo *phil, t_tr_philos *tr_phil);
void			ft_fork_start(t_tr_philos *tr_phil, int i);
#endif