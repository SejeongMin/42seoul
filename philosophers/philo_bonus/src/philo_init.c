/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:28:59 by semin             #+#    #+#             */
/*   Updated: 2021/12/10 18:11:02 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
	if (ac == 6)
		params->time_to_eat = ft_atoi(av[5], params);
	else
		params->time_to_eat = -1;
	params->philo = (t_philo *)malloc(sizeof(t_philo) * num);
	if (!params->philo)
		params->dead = 1;
	if (params->philo_num <= 0)
	{
		printf("The number of philosophers must be at least 1\n");
		params->dead = 1;
	}
	return (params);
}
