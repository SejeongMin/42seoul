/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:46:56 by semin             #+#    #+#             */
/*   Updated: 2021/12/07 02:19:09 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

useconds_t	get_time(void)
{
	struct timeval	time;
	useconds_t		ret;

	gettimeofday(&time, 0);
	ret = (unsigned int)time.tv_sec * 1000000 + time.tv_usec;
	return (ret);
}

float	time_gap(t_params *params)
{
	struct timeval	time;
	float			ret;

	gettimeofday(&time, 0);
	ret = (unsigned int)time.tv_sec * 1000000 + time.tv_usec;
	ret = (ret - params->start) * 0.001;
	return (ret);
}

void	kill_philo(t_params *params, t_philo *philo)
{
	int	i;

	if (params->dead == 1)
		exit(1);
	sem_wait(philo->print);
	params->dead = 1;
	printf("%.0f %d died\n", time_gap(params), philo->num);
	exit(1);
}
