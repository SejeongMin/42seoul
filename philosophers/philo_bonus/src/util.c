/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:49:23 by semin             #+#    #+#             */
/*   Updated: 2021/12/02 15:40:18 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_free(t_params **params)
{
	free((*params)->forks);
	free((*params)->philo);
	free(*params);
	return (0);
}

void	ft_error(t_params *params)
{
	printf("Error\n");
	params->dead = 1;
	// usleep(1000);
}

int	ft_atoi(char *s, t_params *params)
{
	long long	ret;

	ret = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			ft_error(params);
		s++;
	}
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			ret = 10 * ret + (*s - '0');
		else
			ft_error(params);
		s++;
	}
	if (ret > 2147483647)
		ft_error(params);
	return (ret);
}

void	my_usleep(useconds_t wait)
{
	useconds_t	start;

	start = get_time();
	while (get_time() - start < wait)
	{
		usleep(1);
	}
}

void	destroy_mutex(t_params *params)
{
	int	num;

	num = params->philo_num;
	while (--num >= 0)
	{
		pthread_mutex_destroy(&params->forks[num]);
	}
	pthread_mutex_destroy(&params->print);
}
