#include "philo.h"

int	ft_argv_set(char **argv, t_philo *phil, int i)
{
	phil->nm_phil = ft_atoi(argv[1]);
	phil->tme_die = ft_atoi(argv[2]);
	phil->tme_eat = ft_atoi(argv[3]);
	phil->tme_slp = ft_atoi(argv[4]);
	if (i == 5)
		phil->all_need_eat = ft_atoi(argv[i]);
	return (0);
}

int	ft_pars_argc(char **argv, t_philo *phil)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '\0' && !ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	if (ft_argv_set(argv, phil, i - 1))
		return (1);
	return (0);
}

int	ft_args_setup(t_philo *phil, int argc, char **argv)
{
	phil->all_need_eat = -20;
	if (argc < 5 || argc > 6)
	{
		printf("Main error args\n");
		return (1);
	}
	else
	{
		if (ft_pars_argc(argv, phil))
		{
			printf("Error arguments in main\n");
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo		*phil;
	t_tr_philos	*tr_phil;

	phil = (t_philo *)malloc(sizeof(t_philo));
	if (phil == NULL)
	{
		printf("Malloc main");
		return (-1);
	}
	if (ft_args_setup(phil, argc, argv))
		return (-1);
	if (ft_struct_setup(phil))
		return (-1);
	tr_phil = (t_tr_philos *)malloc(sizeof(t_tr_philos) * phil->nm_phil);
	if (tr_phil == NULL)
	{
		printf("Malloc main 2");
		return (-1);
	}
	if (ft_struct_phils_setup(&phil, tr_phil))
		return (-1);
	if (ft_execute(phil, tr_phil))
		return (-1);
	ft_free(phil, tr_phil);
	return (0);
}
