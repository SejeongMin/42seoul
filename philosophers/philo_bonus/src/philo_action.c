/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:32:06 by semin             #+#    #+#             */
/*   Updated: 2021/12/06 21:11:46 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_eat(t_params *params, t_philo *philo)
{
	sem_wait(params->sem);
	sem_wait(params->sem);
	if (params->dead == 1)
		return ;
	philo->ate++;
	philo->eating = 1;
	sem_wait(params->print);
	printf("%.0f %d has taken a fork\n", time_gap(params), philo->num);
	printf("%.0f %d has taken a fork\n", time_gap(params), philo->num);
	printf("%.0f %d is eating\n", time_gap(params), philo->num);
	sem_post(params->print);
	philo->last_ate = get_time();
	my_usleep(params->eat);
	philo->eating = 0;
	sem_post(params->sem);
	sem_post(params->sem);
}

void	philo_sleep(t_params *params, t_philo *philo)
{
	sem_wait(params->print);
	printf("%.0f %d is sleeping\n", time_gap(params), philo->num);
	sem_post(params->print);
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
	sem_wait(params->print);
	printf("%.0f %d is thinking\n", time_gap(params), philo->num);
	sem_post(params->print);
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
		if (params->dead == 1)
			break ;
	}
	return (NULL);
}

void	routine(t_params *params, t_philo *philo)
{
	int	num;

	if (params->dead == 1)
		exit(1);
	num = params->cur_num;
	philo->last_ate = params->start;
	pthread_detach(philo->check);
	pthread_create(&philo->check, 0, (void *)dead_check, params);
	while (params->dead == 0)
	{
		philo_eat(params, philo);
		if (params->dead == 1)
			break ;
		if (params->time_to_eat >= 0
			&& philo->ate >= params->time_to_eat)
			exit(0);
		philo_sleep(params, philo);
		if (params->dead == 1)
			break ;
		philo_think(params, philo);
	}
	exit(1);
}