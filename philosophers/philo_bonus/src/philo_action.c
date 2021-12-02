/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:32:06 by semin             #+#    #+#             */
/*   Updated: 2021/12/02 15:40:29 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_eat(t_params *params, t_philo *philo)
{
	if (pthread_mutex_lock(philo->f1))
		ft_error(params);
	if (pthread_mutex_lock(philo->f2))
		ft_error(params);
	if (params->dead == 1)
	{
		pthread_mutex_unlock(philo->f2);
		pthread_mutex_unlock(philo->f1);
		return ;
	}
	philo->ate++;
	philo->eating = 1;
	pthread_mutex_lock(&params->print);
	printf("%.0f %d has taken a fork\n", time_gap(params), philo->num);
	printf("%.0f %d has taken a fork\n", time_gap(params), philo->num);
	printf("%.0f %d is eating\n", time_gap(params), philo->num);
	pthread_mutex_unlock(&params->print);
	philo->last_ate = get_time();
	my_usleep(params->eat);
	philo->eating = 0;
	if (pthread_mutex_unlock(philo->f2))
		ft_error(params);
	if (pthread_mutex_unlock(philo->f1))
		ft_error(params);
}

void	philo_sleep(t_params *params, t_philo *philo)
{
	pthread_mutex_lock(&params->print);
	printf("%.0f %d is sleeping\n", time_gap(params), philo->num);
	pthread_mutex_unlock(&params->print);
	if (params->sleep >= params->die)
	{
		my_usleep(params->die);
		kill_philo(params, philo);
	}
	else
		my_usleep(params->sleep);
}

void	philo_think(t_params *params, t_philo *philo)
{
	pthread_mutex_lock(&params->print);
	printf("%.0f %d is thinking\n", time_gap(params), philo->num);
	pthread_mutex_unlock(&params->print);
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
	if (params->philo[num].f1 == params->philo[num].f2)
		my_usleep(params->die);
	while (params->dead == 0)
	{
		philo_eat(params, &params->philo[num]);
		if (params->dead == 1)
			break ;
		if (params->time_to_eat >= 0
			&& params->philo[num].ate >= params->time_to_eat)
			break ;
		philo_sleep(params, &params->philo[num]);
		if (params->dead == 1)
			break ;
		philo_think(params, &params->philo[num]);
		if (params->dead == 1)
			break ;
	}
	pthread_detach(params->philo[num].check);
	return (NULL);
}
