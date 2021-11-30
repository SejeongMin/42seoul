/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:32:06 by semin             #+#    #+#             */
/*   Updated: 2021/11/30 18:48:26 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	kill_philo(t_params *params, t_philo *philo)
{
	int	philo_num;

	if (params->dead == 1)
		return ;
	params->dead = 1;
	printf("[%.0f] %d is dead\n", time_gap(params), philo->num);
	philo_num = params->philo_num;
	while (--philo_num)
		pthread_detach(params->philo[philo_num].check);
	// pthread_mutex_unlock(&params->print);
}

void	philo_eat(t_params *params, t_philo *philo)
{
	pthread_mutex_lock(philo->f1);
	pthread_mutex_lock(philo->f2);
	if (params->dead == 1)
		return ;
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
	if (params->sleep >= params->die)
	{
		usleep(params->die);
		// pthread_mutex_lock(&params->print);
		kill_philo(params, philo);
	}
	else
		usleep(params->sleep);
}

void	philo_think(t_params *params, t_philo *philo)
{
	printf("[%.0f] %d is thinking\n", time_gap(params), philo->num);
}

void	*dead_check(t_params *params)
{
	int			num;
	useconds_t	gap;

	num = params->cur_num;
	while (params->dead == 0)
	{
		gap = get_time() - params->philo[num].last_ate;
		if (gap >= params->die && !params->philo[num].eating)
		{
			// pthread_mutex_lock(&params->print);
			kill_philo(params, &params->philo[num]);
		}
		usleep(10);
		if (params->dead == 1)
			break ;
	}
	return (NULL);
}

void	*routine(t_params *params)
{
	int	num;

	num = params->cur_num;
	pthread_create(&params->philo[num].check, 0, (void *)dead_check, params);
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
	pthread_detach(params->philo[num].check);
	return (NULL);
}
