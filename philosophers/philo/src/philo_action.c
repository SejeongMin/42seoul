/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:32:06 by semin             #+#    #+#             */
/*   Updated: 2021/11/29 19:39:57 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_params *params, t_philo *philo)
{
	pthread_mutex_lock(philo->f1);
	pthread_mutex_lock(philo->f2);
	printf("%d has taken a fork\n", philo->num);
	printf("%d has taken a fork\n", philo->num);
	printf("%d is eating\n", philo->num);
	usleep(params->eat);
	pthread_mutex_unlock(philo->f2);
	pthread_mutex_unlock(philo->f1);
}

void	philo_sleep(t_params *params, t_philo *philo)
{
	printf("%d is sleeping\n", philo->num);
	usleep(params->sleep);
}

void	philo_think(t_params *params, t_philo *philo)
{
	printf("%d is thinking\n", philo->num);
}

void	*routine(t_params *params)
{
	int	num;

	num = params->cur_num;
	while (params->dead == 0)
	{
		philo_eat(params, &params->philo[num]);
		philo_sleep(params, &params->philo[num]);
		philo_think(params, &params->philo[num]);
	}
	return (NULL);
}
