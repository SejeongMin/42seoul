/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:07:48 by semin             #+#    #+#             */
/*   Updated: 2021/12/06 23:49:47 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	create_philosophers(t_params *params)
{
	int		i;
	t_philo	*philo;
	sem_t	*forks;
	sem_t	*print;

	philo = params->philo;
	params->start = get_time();
	forks = sem_open("forks", O_CREAT | O_EXCL, 0644, params->philo_num);
	print = sem_open("forks", O_CREAT | O_EXCL, 0644, params->philo_num);
	i = 0;
	while (i < params->philo_num && params->dead == 0)
	{
		philo[i].num = i + 1;
		philo[i].eating = 0;
		philo[i].ate = 0;
		params->cur_num = i;
		philo[i].forks = forks;
		philo[i].print = print;
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			routine(params, &philo[i]);
		}
		usleep(50);
		i++;
	}
	sem_unlink("forks");
	sem_unlink("print");
	sem_close(forks);
	sem_close(print);
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
	create_philosophers(params);
	int i = 0;
	philo_num = params->philo_num;
	while (i < philo_num)
	{
		waitpid(params->philo[i].pid, &status, 0);
		i++;
	}
	if (status == 0)
		printf("All philosophers survived!\n");
	ft_free(&(params));
}
