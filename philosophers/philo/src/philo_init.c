/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:28:59 by semin             #+#    #+#             */
/*   Updated: 2021/12/10 18:02:42 by semin            ###   ########.fr       */
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

	params = (t_params *)malloc(sizeof(t_params));
	if (!params)
		return (NULL);
	params->dead = 0;
	num = ft_atoi(av[1], params);
	params->philo_num = num;
	params->die = ft_atoi(av[2], params) * 1000;
	params->eat = ft_atoi(av[3], params) * 1000;
	params->sleep = ft_atoi(av[4], params) * 1000;
	params->ate = 0;
	pthread_mutex_init(&params->print, 0);
	if (ac == 6)
		params->cnt = ft_atoi(av[5], params);
	else
		params->cnt = -1;
	params->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	params->philo = (t_philo *)malloc(sizeof(t_philo) * num);
	if (!params->forks || !params->philo || params->philo_num <= 0)
		params->dead = 1;
	fork_init(params);
	return (params);
}
