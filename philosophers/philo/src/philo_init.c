/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:28:59 by semin             #+#    #+#             */
/*   Updated: 2021/11/29 19:39:11 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fork_init(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->philo_num)
	{
		pthread_mutex_init(&params->forks[i], 0);
		i++;
	}
	i = 0;
	while (i < params->philo_num)
	{
		if (i == 0)
			params->philo[i].f1 = &(params->forks[params->philo_num - 1]);
		else
			params->philo[i].f1 = &(params->forks[i - 1]);
		params->philo[i].f2 = &(params->forks[i]);
		i++;
	}
}

t_params	*param_init(int ac, char **av)
{
	t_params	*params;
	int			num;

	num = ft_atoi(av[1]);
	params = (t_params *)malloc(sizeof(t_params));
	pthread_mutex_init(&params->m, 0);
	params->philo_num = num;
	params->dead = 0;
	params->die = ft_atoi(av[2]) * 1000;
	params->eat = ft_atoi(av[3]) * 1000;
	params->sleep = ft_atoi(av[4]) * 1000;
	if (ac == 6)
		params->time_to_eat = ft_atoi(av[5]);
	else
		params->time_to_eat = -1;
	params->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	params->philo = (t_philo *)malloc(sizeof(t_philo) * num);
	fork_init(params);
	return (params);
}
