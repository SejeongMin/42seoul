/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:07:48 by semin             #+#    #+#             */
/*   Updated: 2021/12/10 17:55:45 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	wait_child(sem_t *forks, sem_t *print)
{
	int	status;

	waitpid(-1, &status, 0);
	sem_unlink("forks");
	sem_unlink("print");
	sem_close(forks);
	sem_close(print);
	return (status);
}

int	create_philosophers(t_params *params)
{
	int		i;
	sem_t	*forks;
	sem_t	*print;
	int		*status;

	params->start = get_time();
	forks = sem_open("forks", O_CREAT | O_EXCL, 0644, params->philo_num);
	print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	i = 0;
	while (i < params->philo_num && params->dead == 0)
	{
		params->philo[i].num = i + 1;
		params->philo[i].eating = 0;
		params->philo[i].ate = 0;
		params->cur_num = i;
		params->philo[i].forks = forks;
		params->philo[i].print = print;
		params->philo[i].pid = fork();
		if (params->philo[i].pid == 0)
			routine(params, &params->philo[i]);
		usleep(40);
		i++;
	}
	return (wait_child(forks, print));
}

void	end_process(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->philo_num)
	{
		kill(params->philo[i].pid, SIGKILL);
		i++;
	}
}

int	main(int ac, char **av)
{
	pthread_t	*philosopher;
	t_params	*params;
	int			philo_num;
	int			status;

	if (ac < 5 || ac > 6)
		return (1);
	params = param_init(ac, av);
	if (!params)
		return (1);
	status = create_philosophers(params);
	if (status == 0)
		printf("All philosophers survived!\n");
	end_process(params);
	ft_free(&(params));
	exit(0);
}
