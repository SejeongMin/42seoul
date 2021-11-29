/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:32:06 by semin             #+#    #+#             */
/*   Updated: 2021/11/30 01:15:01 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_params *params, t_philo *philo)
{
	pthread_mutex_lock(philo->f1);
	pthread_mutex_lock(philo->f2);
	philo->eating = 1;
	printf("[%.0f] %d has taken a fork\n", time_gap(params), philo->num);
	printf("[%.0f] %d has taken a fork\n", time_gap(params), philo->num);
	printf("[%.0f] %d is eating\n", time_gap(params), philo->num);
	usleep(params->eat);
	philo->last_ate = get_time();
	philo->eating = 0;
	pthread_mutex_unlock(philo->f2);
	pthread_mutex_unlock(philo->f1);
}

void	philo_sleep(t_params *params, t_philo *philo)
{
	printf("[%.0f] %d is sleeping\n", time_gap(params), philo->num);
	usleep(params->sleep);
}

void	philo_think(t_params *params, t_philo *philo)
{
	printf("[%.0f] %d is thinking\n", time_gap(params), philo->num);
}

void	*dead_check(t_params *params)
{
	int	num = params->cur_num;

	while (params->dead == 0)
	{
		if (time_gap(params) > params->die)
		{
			params->dead = 1;
			printf("[%.0f] %d is dead~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", time_gap(params), num + 1);
		}
	}
	return (NULL);
}

void	*routine(t_params *params)
{
	int	num;

	num = params->cur_num;
	// pthread_create(&params->philo[num].check, 0, (void *)dead_check, params);
	while (params->dead == 0)
	{
		philo_eat(params, &params->philo[num]);
		if (params->dead == 1)
			break;
		philo_sleep(params, &params->philo[num]);
		if (params->dead == 1)
			break;
		philo_think(params, &params->philo[num]);
		if (params->dead == 1)
			break;
	}
	pthread_join(params->philo[num].check, 0);
	return (NULL);
}
